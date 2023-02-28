#pragma once

#include "level.h"

class SnakeGame: public Level
{
public:
    SnakeGame(std::shared_ptr<GameState> gamestate);
    ~SnakeGame();
    void step(char c) override;
};