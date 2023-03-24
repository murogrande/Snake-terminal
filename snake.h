#ifndef SNAKE_H
#define SNAKE_H

#pragma once

class Snake
{
public:
    Snake(int position_x,int position_y);
    ~Snake();
    void move(char c);
    void draw();
    bool crash_boundary();
private:

    int position_x;
    int position_y;   

};

#endif