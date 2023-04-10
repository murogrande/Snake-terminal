#pragma once
#include "fruit.h"
#include "snake_segments.h"
#include <vector>
#include <memory>

class Snake
{
public:
    Snake();
    void set_position(int position_x, int position_y);
    void move();
    void draw();
    void undraw();
    bool crash_boundary(int size_x, int size_y);
    bool has_fruit(Fruit& fruit);
    void set_direction(char c);

private:
    enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
    std::vector<std::unique_ptr<SnakeSegment>> segments;   
};