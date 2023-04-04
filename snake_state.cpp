#include "snake_state.h"
#include "terminal.h"

#include <chrono>
#include <thread>
#include <ctime>

SnakeState::SnakeState(std::shared_ptr<GameState> gamestate) : Level(gamestate), snake(gamestate->get_window_size().second/2, gamestate->get_window_size().first/2),fruit(5,5)
{
	auto size = gamestate->get_window_size();

	current_time = std::chrono::system_clock::now();//time_point variable
    //fruitX = (rand() % (size.second-3))+2;
    //fruitY = (rand() % (size.first-3))+2;
	//fruit.set_position((rand() % (size.second-3))+2,(rand() % (size.first-3))+2)
}

SnakeState::~SnakeState()
{
}
void SnakeState::draw(char c)
{ 
	// give the crash boundary 
	// chech if the snake crash and set the level to title screen level 0
	// make the fruit object, get rid of loop 2 (line 27). Very simmilar to snake.
	//srand(time(0));

	auto size = gamestate->get_window_size();
	auto current_time_now = std::chrono::system_clock::now();
	boundary();
	snake.set_direction(c);
	if (current_time_now - current_time > frame_rate){
		snake.move();
		current_time = current_time_now;
	}
	// if statement with delta time bigger_rate
	snake.draw();


	if (snake.crash_boundary(size.second, size.first))
	{
		snake.set_position(size.second/2, size.first/2);
	 	gamestate->set_current_level(CurrentLevel::TITLE_SCREEN);
	}
	fruit.draw();
	// score for later
	//term.set_text_color(TextColor::BLUE); 
	//term.move_to(0,size.size);
	//term.print("score");
	
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