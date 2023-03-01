#pragma once

#include "level.h"

class Game;

class TitleScreen: public Level
{
public:
    TitleScreen(std::shared_ptr<GameState> gamestate, LevelSignal finished_handler);
    ~TitleScreen();
    void step(char c) override;
};