#pragma once

#include "signals.h"
#include "gamestate.h"
#include <memory>

class Game;
typedef SignalHandler<Game,void> LevelSignal;

class Level
{
public:
    Level(std::shared_ptr<GameState> gamestate, LevelSignal finished_handler);
    virtual ~Level();
    virtual void step(char c) = 0; //pure virtual
protected:
    std::shared_ptr<GameState> gamestate;
    void on_finished();
    bool dirty = true;
private:
    SignalHandler<Game, void> finished_handler;
};