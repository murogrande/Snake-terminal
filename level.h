#pragma once

#include "gamestate.h"
#include <memory>

class Level
{
public:
    Level(std::shared_ptr<GameState> gamestate);
    virtual ~Level();
    virtual void draw(char c) = 0; //pure virtual
protected:
    std::shared_ptr<GameState> gamestate;
    bool dirty = true;
};