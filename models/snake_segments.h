#pragma once
#include <string>
#include <utility>

class SnakeSegment
{
public:
    virtual ~SnakeSegment();
    virtual void draw() = 0;
    void undraw();
    void set_position(int x, int y);
    std::pair<int,int> get_position();
protected:
    int x;
    int y;
};

class Head: public SnakeSegment
{
public:
    void draw() override;
};

class Tail: public SnakeSegment
{
public:
    Tail(char name);
    void draw() override;
private:
    std::string name;
};