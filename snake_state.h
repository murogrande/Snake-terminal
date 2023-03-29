#pragma once
#include "level.h"
#include "snake.h"
#include "fruit.h"
#include <chrono>

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
    //std::chrono::_V2::system_clock::time_point current_time; // declare time_point variable, we can use this in the cpp file
    std::chrono::time_point<std::chrono::system_clock> current_time;
    std::chrono::duration<double> frame_rate = std::chrono::milliseconds(1000);
    Snake snake;
    Fruit fruit;
};
