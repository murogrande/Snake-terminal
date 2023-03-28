#ifndef FRUIT_H
#define FRUIT_H

#pragma once

class Fruit
{
public:
    
    Fruit(int fruit_pos_x, int fruit_pos_y );
    ~Fruit();

    void set_position(int position_x, int position_y);
    void draw();

private:

int fruit_pos_x;
int fruit_pos_y;

};

#endif