#include "snake.h"
#include "../io/terminal.h"
#include "../game/gamestate.h"
#include <chrono>

static const int n_letters = 6;
static const char letters[] = {'p', 'a', 's', 'q', 'a','l'};

Snake::Snake(int x, int y)
{
	segments.emplace_back(std::make_unique<Head>());
	segments.emplace_back(std::make_unique<Tail>(letters[(segments.size()-1)%n_letters]));
	segments.emplace_back(std::make_unique<Tail>(letters[(segments.size()-1)%n_letters]));
	segments[0]->set_position(x,y);
	segments[1]->set_position(x-1,y);
	segments[2]->set_position(x-2,y);
}

void Snake::move()
{
	auto pos = segments[0]->get_position();
	
    switch(dir)
	{
	case LEFT:
		segments[0]->set_position(pos.first-1, pos.second);
		break;
	case RIGHT:
		segments[0]->set_position(pos.first+1, pos.second);
		break;
	case UP:
		segments[0]->set_position(pos.first, pos.second-1);
		break;
	case DOWN:
		segments[0]->set_position(pos.first, pos.second+1);
		break;	
	default:
		break;
	}	

	//Loop over the tail
	for(auto it = ++segments.begin(); it != segments.end(); ++it)
	{
		auto tmp = (*it)->get_position();
		(*it)->set_position(pos.first, pos.second);
		pos = tmp;
	}
}

void Snake::grow()
{
	segments.emplace_back(std::make_unique<Tail>(letters[(segments.size()-1)%n_letters]));
}

void Snake::draw()
{
    auto& term = Terminal::instance();
    term.set_text_color(TextColor::YELLOW);
	segments[0]->draw();
    term.set_text_color(TextColor::MAGENTA);
	//Loop over the tail
	for(auto it = ++segments.begin(); it != segments.end(); ++it)
	{
		(*it)->draw();
	}
}

void Snake::undraw_last()
{  
	segments.back()->undraw();
}

bool Snake::has_fruit(Fruit& fruit)
{
	auto fruit_pos = fruit.get_position();
	auto pos = segments[0]->get_position();
	return pos.first == fruit_pos.first && pos.second == fruit_pos.second;
}

bool Snake::crash_self()
{
	auto head_pos = segments[0]->get_position();
	for(auto it = ++segments.begin(); it != segments.end(); ++it)
	{
		if((*it)->get_position() == head_pos)
		{
			return true;
		}
	}
	return false;
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

