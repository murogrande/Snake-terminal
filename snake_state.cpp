#include "snake_state.h"
#include "terminal.h"

#include <chrono>
#include <thread>
#include <ctime>

SnakeState::SnakeState(std::shared_ptr<GameState> gamestate) : Level(gamestate), snake(gamestate->get_window_size().second/2, gamestate->get_window_size().first/2),fruit(5,5)
{
	auto size = gamestate->get_window_size();

	current_time = std::chrono::system_clock::now();//time_point variable
}

SnakeState::~SnakeState()
{
}
void SnakeState::draw(char c)
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
		snake.undraw();
		snake.move();
		snake.draw();
		fruit.draw();
		current_time = current_time_now;
	}	

	if (snake.crash_boundary(size.second, size.first))
	{
		dirty = true;
		snake.set_position(size.second/2, size.first/2);
	 	gamestate->set_current_level(CurrentLevel::TITLE_SCREEN);
	}
}

//print boundary
void SnakeState::boundary(){
	auto& term = Terminal::instance();
	term.clear();
    auto size = term.get_size();
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