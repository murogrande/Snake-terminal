#include "snake.h"
#include "terminal.h"
#include "gamestate.h"
#include <chrono>


Snake::Snake(int position_x, int position_y): position_x(position_x),position_y(position_y)
{ 
     dir = STOP; // use a another method for the direction 
}

Snake::~Snake()
{

}

void Snake::move()
{
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

void Snake::undraw()
{
    auto& term = Terminal::instance();
    term.move_to(position_y,position_x);
    term.set_text_color(TextColor::YELLOW);
    term.print(" ");  
}

bool Snake::crash_boundary(int size_x, int size_y)
{
    auto& term = Terminal::instance();

    if (position_x <= 1 || position_x >= size_x || position_y<= 1 || position_y>=size_y)
    {
        return true; // why is it starting from 1? 
    }
    return false;
}

void Snake::set_direction(char c)
{
	if (c == 'j')
		dir = LEFT;
	if (c == 'l')
			dir = RIGHT;
	if (c == 'k')
			dir = DOWN;
	if (c == 'i')
			dir = UP;
}

void Snake::set_position(int position_x, int position_y)
{
    this->position_x = position_x;
    this->position_y = position_y;
}

