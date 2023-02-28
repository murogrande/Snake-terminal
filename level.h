#pragma once

#include "gamestate.h"
#include <memory>

typedef void (*SignalHandler)();

class Level
{
public:
    Level(std::shared_ptr<GameState> gamestate, SignalHandler finished_handler);
    virtual ~Level();
    virtual void step(char c) = 0; //pure virtual
protected:
    std::shared_ptr<GameState> gamestate;
    void on_finished();
    bool dirty = true;
private:
    SignalHandler finished_handler;
};