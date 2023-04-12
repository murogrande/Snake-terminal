#pragma once

#include <memory>
#include <vector>
#include "../levels/level.h"
#include "gamestate.h"
#include "../levels/snake_game.h"

class Game
{
public:
    Game();
    ~Game();
    void run();
private:
//    void title_screen_finished();
    std::shared_ptr<GameState> gamestate = std::make_shared<GameState>();
    std::vector<std::unique_ptr<Level>> levels;
};
