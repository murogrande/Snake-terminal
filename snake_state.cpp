#include "snake_state.h"
#include "terminal.h"

SnakeState::SnakeState(std::shared_ptr<GameState> gamestate) : Level(gamestate), snake((gamestate->get_window_size()).second/2, (gamestate->get_window_size()).first/2)
{
	auto size = gamestate->get_window_size();
    fruitX = (rand() % (size.first-2))+2;
    fruitY = (rand() % (size.second-2))+2;
}

SnakeState::~SnakeState()
{
}
void SnakeState::draw(char c)
{ // give the crach boundary 
// chech if the snake crash and ser the level to title screen level 0
// make the fruit object, get rid of loop 2 (line 27). Very simmilar to snake.

        auto& term = Terminal::instance();
        auto size = term.get_size();
        term.clear();
        term.move_to(1,1);
		boundary();
		snake.move(c);
		snake.draw();
	
	
	for (int i = 2; i  < size.first; i++)//chech the initial number
	{
		for (int j = 2; j  < size.second ; j++)//chech the initial number
		{
			
			if (i == fruitX && j == fruitY)
			{ 
				term.set_text_color(TextColor::BLUE);
				term.move_to(i,j);
				term.print("F");
			}
		}
	
	}
	// score for later
	//term.set_text_color(TextColor::BLUE); 
	//term.move_to(0,size.size);
	//term.print("score");
}


//print top bounding row
void SnakeState::boundary(){
	auto& term = Terminal::instance();
    auto size = term.get_size();
	term.set_text_color(TextColor::GREEN);

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