#pragma once

#include "level.h"

class TitleScreen: public Level
{
public:
    TitleScreen(std::shared_ptr<GameState> gamestate, SignalHandler finished_handler);
    ~TitleScreen();
    void step(char c) override;
};