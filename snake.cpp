#include "snake.h"
#include "terminal.h"
#include "gamestate.h"
#include <chrono>

Snake::Snake()
{
	segments.emplace_back(std::make_unique<Head>());
}

void Snake::move()
{
	auto pos = segments[0]->get_position();
    switch(dir)
	{
	case LEFT:
		segments[0]->set_position(--pos.first, pos.second);
		break;
	case RIGHT:
		segments[0]->set_position(++pos.first, pos.second);
		break;
	case UP:
		segments[0]->set_position(pos.first, --pos.second);
		break;
	case DOWN:
		segments[0]->set_position(pos.first, ++pos.second);
		break;	
	default:
		break;
	}
}

void Snake::draw()
{
	segments[0]->draw();
}

void Snake::undraw()
{  
	segments[0]->undraw();
}

bool Snake::has_fruit(Fruit& fruit)
{
	auto fruit_pos = fruit.get_position();
	auto pos = segments[0]->get_position();
	return pos.first == fruit_pos.first && pos.second == fruit_pos.second;
}

bool Snake::crash_boundary(int size_x, int size_y)
{
	auto pos = segments[0]->get_position();

    if (pos.first <= 1 || pos.first >= size_x || pos.second<= 1 || pos.second>=size_y)
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
    segments[0]->set_position(x,y);
}

