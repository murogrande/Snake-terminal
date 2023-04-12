#pragma once
#include "level.h"
#include "../models/snake.h"
#include "../models/fruit.h"
#include <chrono>
#include <random>

class SnakeGame;

class SnakeGame: public Level
{
public:
    SnakeGame(std::shared_ptr<GameState> gamestate);
    void set_window_size(std::pair<int,int> rows_cols);
    std::pair<int,int> get_window_size();
    void draw(char c) override;
private:
    void boundary();
    std::pair<int,int> new_fruit_position();
    std::chrono::time_point<std::chrono::system_clock> current_time;
    std::chrono::duration<double> frame_rate = std::chrono::milliseconds(100);
    Snake snake;
    Fruit fruit;
    std::mt19937 rng;
};
