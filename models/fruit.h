#pragma once
#include <utility>

class Fruit
{
public:
    
    Fruit();
    ~Fruit();

    void set_position(int x, int y);
    std::pair<int /*x*/,int /*y*/> get_position();
    void draw();

private:

int x;
int y;

};