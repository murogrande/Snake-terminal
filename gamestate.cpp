#include "gamestate.h"
#include "terminal.h"

void GameState::set_window_size(std::pair<int,int> rows_cols)
{
    window_size = rows_cols;
}

std::pair<int,int> GameState::get_window_size()
{
    return window_size;
}

void GameState::set_current_level(int level)
{
    current_level = level;
}

int GameState::get_current_level()
{
    return current_level;
}


void GameState::draw_snake(char c, int& x, int& y, int& fruitX, int& fruitY)
{

        auto& term = Terminal::instance();
        auto size = term.get_size();
        term.clear();
        term.move_to(1,1);
        term.set_text_color(TextColor::GREEN);
        
        enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
        eDirection dir;
        dir = STOP;
      
        if (c == 'j')
        	dir = LEFT;
        if (c == 'l')
            	dir = RIGHT;
        if (c == 'k')
            	dir = DOWN;
        if (c == 'i')
            	dir = UP;
 
        switch(dir)
	{
	case LEFT:
		y--;//move to left
		break;
	case RIGHT:
		y++;//move to right
		break;
	case UP:
		x--;//move up
		break;
	case DOWN:
		x++;//move down
		break;	
	default:
		break;
	}
	
	//print top bounding row
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
    	
	
	for (int i = 2; i  < size.first; i++)//chech the initial number
	{
		for (int j = 2; j  < size.second ; j++)//chech the initial number
		{
			if (i == x && j == y)
			{
				term.set_text_color(TextColor::YELLOW);
				term.move_to(i,j);
				term.print("X");
			}
			else if (i == fruitX && j == fruitY)
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
