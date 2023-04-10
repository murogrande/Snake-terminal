#pragma once
#include "level.h"
#include "snake.h"
#include "fruit.h"
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
    std::chrono::time_point<std::chrono::system_clock> current_time;
    std::chrono::duration<double> frame_rate = std::chrono::milliseconds(200);
    Snake snake;
    Fruit fruit;
    std::mt19937 rng;
	std::uniform_int_distribution<uint32_t> rows_dist;
	std::uniform_int_distribution<uint32_t> cols_dist;
};
