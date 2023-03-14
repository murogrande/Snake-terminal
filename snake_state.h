#pragma once
#include "level.h"

class SnakeState;

class SnakeState: public Level
{
public:
    SnakeState(std::shared_ptr<GameState> gamestate);
    ~SnakeState();
    void set_window_size(std::pair<int,int> rows_cols);
    std::pair<int,int> get_window_size();
    void set_current_level(int level);
    int get_current_level();
    void draw_snake(char c, int& x, int& y, int& fruitX, int& fruitY);
    //void step(char c) override;
private:
    std::pair<int,int> window_size = {0,0};
    int current_level = 0;
};
