#include "snake_game.h"
#include "../io/terminal.h"

#include <chrono>
#include <thread>
#include <ctime>

SnakeGame::SnakeGame(std::shared_ptr<GameState> gamestate) : Level(gamestate), rng(time(nullptr)),
	snake(gamestate->get_window_size().second/2+1, gamestate->get_window_size().first/2),
	rows_dist(2,gamestate->get_window_size().first-1), cols_dist(2,gamestate->get_window_size().second-1)
{
    fruit.set_position(cols_dist(rng), rows_dist(rng));
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
		boundary();
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
		}
		fruit.draw();
		current_time = current_time_now;

	}

	if (snake.crash_boundary(size.second, size.first) || snake.crash_self())
	{
		dirty = true;
		snake = Snake(size.second/2+1, size.first/2);
	 	gamestate->set_current_level(CurrentLevel::TITLE_SCREEN);
	}
}

std::pair<int,int> SnakeGame::new_fruit_position()
{
	return {cols_dist(rng), rows_dist(rng)};
}

//print boundary
void SnakeGame::boundary(){
	auto& term = Terminal::instance();
	term.clear();
    auto size = gamestate->get_window_size();
	term.set_text_color(TextColor::GREEN);
	term.move_to(1,1);

	for(int i = 0; i < size.second; ++i)
	{
		term.print("-");//prints a row of '-'
	}

	//print bottom bounding row
	term.move_to(size.first, 1);
	for(int i = 0; i < size.second; ++i)
	{
		term.print("-");//prints a row of '-'
	}
		//print left bounding row
	for(int i = 2; i < size.first; ++i)
	{
		term.move_to(i, 1);
		term.print("|");//prints a column of '|'
	}
		//print right bounding row
	for(int i = 2; i < size.first; ++i)
	{
		term.move_to(i, size.second);
		term.print("|");//prints a column of '|'
	}
}
