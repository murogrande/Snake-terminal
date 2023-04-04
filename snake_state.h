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
    void boundary();
    std::chrono::time_point<std::chrono::system_clock> current_time;
    std::chrono::duration<double> frame_rate = std::chrono::milliseconds(200);
    Snake snake;
    Fruit fruit;
};
