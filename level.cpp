#include "level.h"

Level::Level(std::shared_ptr<GameState> gamestate, LevelSignal finished_handler) : gamestate(gamestate), finished_handler(finished_handler){}

Level::~Level() {}

void Level::on_finished()
{
    if(finished_handler)
        finished_handler();
}