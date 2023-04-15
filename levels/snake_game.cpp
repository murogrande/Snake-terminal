#include "snake_game.h"
#include "../io/terminal.h"

#include <chrono>
#include <thread>
#include <ctime>
#include <queue>

SnakeGame::SnakeGame(std::shared_ptr<GameState> gamestate) : Level(gamestate), rng(time(nullptr)),
	snake(gamestate->get_window_size().second/2+1, gamestate->get_window_size().first/2)
{
	auto pos = new_fruit_position();
	fruit.set_position(pos.first, pos.second);
	current_time = std::chrono::system_clock::now();//time_point variable
}

void SnakeGame::draw(char c)
{ 
	auto size = gamestate->get_window_size();
	auto current_time_now = std::chrono::system_clock::now();

	//only draw the game boundary when we first get into this level
	//this prevents flickering of the screen
	if(dirty)
	{
		draw_boundary();
		print_score();
		dirty = false;
	}


	snake.set_direction(c);

	//since we don't want to redraw the entire screen to prevent flickering
	//when we reach a new frame in the game, undraw the snake, update its position
	//and then redraw it. This way we don't have to clear the entire screen.
	if (current_time_now - current_time > frame_rate){
		snake.undraw_last();
		snake.move();
		snake.draw();
		if(snake.has_fruit(fruit))
		{
			auto pos = new_fruit_position();
			fruit.set_position(pos.first, pos.second);
			snake.grow();
			score++;
			print_score();
		}
		fruit.draw();
		current_time = current_time_now;

	}

	if (snake.crash_boundary(size.second, size.first) || snake.crash_self())
	{
		dirty = true;
		score = 0;
		snake = Snake(size.second/2+1, size.first/2);
		auto pos = new_fruit_position();
		fruit.set_position(pos.first, pos.second);
	 	gamestate->set_current_level(CurrentLevel::TITLE_SCREEN);
	}
}

std::pair<int,int> SnakeGame::new_fruit_position()
{
	//get linear size of the game area
	auto screen_size = gamestate->get_window_size();
	int field_size = (screen_size.first - 2) * (screen_size.second - 2);

	auto snake_positions = snake.get_positions();

	//subtract snake size, and get random tile
	field_size -= snake_positions.size();
	std::uniform_int_distribution<uint32_t> dist(0, field_size - 1);
	int new_fruit_index = dist(rng);

	//generate snake position indices
	std::priority_queue<int, std::vector<int>, std::greater<int>> snake_indices;
	for(auto it = snake_positions.begin(); it != snake_positions.end(); ++it)
	{
		int index = (it->first-2)+(it->second-2)*(screen_size.second - 2);
		snake_indices.push(index);
	}

	//convert random tile to tile including snake positions
	while(!snake_indices.empty() && new_fruit_index >= snake_indices.top())
	{
		snake_indices.pop();
		new_fruit_index++;
	}

	return {new_fruit_index%(screen_size.second - 2)+2, new_fruit_index/(screen_size.second - 2)+2};
}

void SnakeGame::print_score()
{
	auto& term = Terminal::instance();
    auto size = gamestate->get_window_size();
	term.move_to(size.first, 7);
	term.set_text_color(TextColor::WHITE);
	term.print(std::to_string(score));
}

//print boundary
void SnakeGame::draw_boundary(){
	auto& term = Terminal::instance();
	term.clear();
    auto size = gamestate->get_window_size();

	//print bottom bounding row
	term.move_to(size.first, 1);
	term.set_text_color(TextColor::WHITE);
	term.print("score:");
	term.set_text_color(TextColor::GREEN);
	for(int i = 7; i < size.second; ++i)
	{
		term.print("-");
	}

	//print top bounding row
	term.move_to(1,1);
	for(int i = 0; i < size.second; ++i)
	{
		term.print("-");
	}

	//print left bounding row
	for(int i = 2; i < size.first; ++i)
	{
		term.move_to(i, 1);
		term.print("|");
	}
	//print right bounding row
	for(int i = 2; i < size.first; ++i)
	{
		term.move_to(i, size.second);
		term.print("|");
	}
}
