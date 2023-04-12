#include "snake_segments.h"
#include "../io/terminal.h"

SnakeSegment::~SnakeSegment(){}

void SnakeSegment::undraw()
{
    if(x>1&&y>1)
    {
        auto& term = Terminal::instance();
        term.move_to(y,x);
        term.print(" ");
    }
}

void SnakeSegment::set_position(int x, int y)
{
    this->x = x;
    this->y = y;
}

std::pair<int /*x*/,int /*y*/> SnakeSegment::get_position()
{
    return {x,y};
}

Tail::Tail(char name):name(1,name)
{}

void Head::draw()
{
    if(x>1&&y>1)
    {
        auto& term = Terminal::instance();
        term.move_to(y,x);
        term.print("X");
    }
}

void Tail::draw()
{
    if(x>1&&y>1)
    {
        auto& term = Terminal::instance();
        term.move_to(y,x);
        term.print(name);
    }
}