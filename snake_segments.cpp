#include "snake_segments.h"
#include "terminal.h"

SnakeSegment::~SnakeSegment(){}

void SnakeSegment::undraw()
{
    auto& term = Terminal::instance();
    term.move_to(y,x);
    term.set_text_color(TextColor::YELLOW);
    term.print(" ");
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
    auto& term = Terminal::instance();
    term.move_to(y,x);
    term.set_text_color(TextColor::YELLOW);
    term.print("X");
}

void Tail::draw()
{
    auto& term = Terminal::instance();
    term.move_to(y,x);
    term.set_text_color(TextColor::YELLOW);
    term.print(name);
}