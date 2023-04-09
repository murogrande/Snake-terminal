#include "snake.h"
#include "terminal.h"
#include "gamestate.h"
#include <chrono>


Snake::Snake(int x, int y): x(x),y(y)
{ 
     dir = RIGHT; // use a another method for the direction 
}

Snake::~Snake()
{

}

void Snake::move()
{
    switch(dir)
	{
	case LEFT:
		x--;//move to left
		break;
	case RIGHT:
		x++;//move to right
		break;
	case UP:
		y--;//move up
		break;
	case DOWN:
		y++;//move down
		break;	
	default:
		break;
	}
}

void Snake::draw()
{
    auto& term = Terminal::instance();
    term.move_to(y,x);
    term.set_text_color(TextColor::YELLOW);
    term.print("X");  
}

void Snake::undraw()
{
    auto& term = Terminal::instance();
    term.move_to(y,x);
    term.set_text_color(TextColor::YELLOW);
    term.print(" ");  
}

bool Snake::has_fruit(Fruit& fruit)
{
	auto fruit_pos = fruit.get_position();
	return x == fruit_pos.first && y == fruit_pos.second;
}

bool Snake::crash_boundary(int size_x, int size_y)
{
    auto& term = Terminal::instance();

    if (x <= 1 || x >= size_x || y<= 1 || y>=size_y)
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

void Snake::set_position(int x, int y)
{
    this->x = x;
    this->y = y;
}

