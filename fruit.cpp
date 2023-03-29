#include "fruit.h"
#include "terminal.h"


Fruit::Fruit(int fruit_pos_x, int fruit_pos_y):fruit_pos_x(fruit_pos_x),fruit_pos_y(fruit_pos_y)
{
    
}

Fruit::~Fruit()
{

}

void Fruit::set_position(int fruit_pos_x, int fruit_pos_y)
{
    this -> fruit_pos_x = fruit_pos_x;
    this -> fruit_pos_y = fruit_pos_y;
}

void Fruit::draw()
{
    auto& term = Terminal::instance();
	term.set_text_color(TextColor::BLUE);
    term.move_to(fruit_pos_y,fruit_pos_x);
	term.print("F");
}
