#include "snake.h"
#include "terminal.h"
#include "gamestate.h"

Snake::Snake(int position_x, int position_y): position_x(position_x),position_y(position_y)
{ 

}

Snake::~Snake()
{

}

void Snake::move(char c)
{
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
		position_x--;//move to left
		break;
	case RIGHT:
		position_x++;//move to right
		break;
	case UP:
		position_y--;//move up
		break;
	case DOWN:
		position_y++;//move down
		break;	
	default:
		break;
	}
}

void Snake::draw()
{
    auto& term = Terminal::instance();
    term.move_to(position_y,position_x);
    term.set_text_color(TextColor::YELLOW);
    term.print("X");  
}

bool Snake::crash_boundary()
{       
    auto& term = Terminal::instance();
    auto size = term.get_size();
    int middleX = size.first/2;
    int middleY = size.second/2;

    if ((position_x <0 || position_x > (size.first-4) || position_y<0 || position_y>(size.second-4))){
        term.set_text_color(TextColor::BLUE);
        term.clear();
        term.move_to(middleX,middleY);
        term.print("Game Over");
        //gamestate->set_current_level(0);
        //it cannot draw char is empty
        return true;  
    }
    return false;
}


