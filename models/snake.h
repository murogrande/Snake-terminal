#pragma once
#include "fruit.h"
#include "snake_segments.h"
#include <vector>
#include <memory>

class Snake
{
public:
    Snake(int x, int y);
    void move();
    void draw();
    void undraw_last();
    void grow();
    bool crash_boundary(int size_x, int size_y);
    bool crash_self();
    bool has_fruit(Fruit& fruit);
    void set_direction(char c);

private:
    enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
    eDirection dir = RIGHT;
    std::vector<std::unique_ptr<SnakeSegment>> segments;   
};