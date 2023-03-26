#include "snake_state.h"
#include "terminal.h"

SnakeState::SnakeState(std::shared_ptr<GameState> gamestate) : Level(gamestate), snake(gamestate->get_window_size().second/2, gamestate->get_window_size().first/2)
{
	auto size = gamestate->get_window_size();
    fruitX = (rand() % (size.second-3))+2;
    fruitY = (rand() % (size.first-3))+2;
}

SnakeState::~SnakeState()
{
}
void SnakeState::draw(char c)
{ 
	// give the crash boundary 
	// chech if the snake crash and set the level to title screen level 0
	// make the fruit object, get rid of loop 2 (line 27). Very simmilar to snake.

	auto size = gamestate->get_window_size();
	boundary();
	snake.move(c);
	snake.draw();	

	if (snake.crash_boundary(size.second, size.first))
	{
		snake.set_position(size.second/2, size.first/2);
	 	gamestate->set_current_level(CurrentLevel::TITLE_SCREEN);
	}
	
	auto& term = Terminal::instance();
	term.set_text_color(TextColor::BLUE);
	term.move_to(fruitY,fruitX);
	term.print("F");
	// score for later
	//term.set_text_color(TextColor::BLUE); 
	//term.move_to(0,size.size);
	//term.print("score");
}


//print top bounding row
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