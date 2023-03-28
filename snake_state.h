#pragma once
#include "level.h"
#include "snake.h"
#include "fruit.h"

class SnakeState;

class SnakeState: public Level
{
public:
    SnakeState(std::shared_ptr<GameState> gamestate);
    ~SnakeState();
    void set_window_size(std::pair<int,int> rows_cols);
    std::pair<int,int> get_window_size();
    void draw(char c) override;
private:
    //int x = 0;
    //int y = 0; 
    int fruitX = 0; // delete when you have the fruit class
    int fruitY = 0;// delete when you have the fruit class
    void boundary();
    Snake snake;
    Fruit fruit;
};
