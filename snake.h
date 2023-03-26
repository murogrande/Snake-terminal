#ifndef SNAKE_H
#define SNAKE_H

#pragma once

class Snake
{
public:
    Snake(int position_x,int position_y);
    ~Snake();
    void set_position(int position_x, int position_y);
    void move(char c);
    void draw();
    bool crash_boundary(int size_x, int size_y);
private:

    int position_x;
    int position_y;   

};

#endif