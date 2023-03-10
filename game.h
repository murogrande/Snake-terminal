#pragma once

#include <memory>
#include <vector>
#include "level.h"
#include "gamestate.h"

class Game
{
public:
    Game();
    ~Game();
    void run();
private:
    void title_screen_finished();
    std::shared_ptr<GameState> gamestate = std::make_shared<GameState>(0);
    std::vector<std::shared_ptr<Level>> levels;
};