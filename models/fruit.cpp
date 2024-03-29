#include "fruit.h"
#include "../io/terminal.h"


Fruit::Fruit()
{    
}

Fruit::~Fruit()
{

}

void Fruit::set_position(int x, int y)
{
    this->x = x;
    this->y = y;
}

std::pair<int /*x*/,int /*y*/> Fruit::get_position()
{
    return {x,y};
}

void Fruit::draw()
{
    auto& term = Terminal::instance();
	term.set_text_color(TextColor::CYAN);
    term.move_to(y,x);
	term.print("o");
}
