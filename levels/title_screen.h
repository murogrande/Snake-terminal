#pragma once

#include "level.h"

class TitleScreen: public Level
{
public:
    TitleScreen(std::shared_ptr<GameState> gamestate);
    void draw(char c) override;
};