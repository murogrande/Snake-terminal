#include "gamestate.h"


GameState::GameState(int current_level): current_level(current_level)
{}

void GameState::set_window_size(std::pair<int,int> rows_cols)
{
    window_size = rows_cols;
}

std::pair<int,int> GameState::get_window_size()
{
    return window_size;
}

void GameState::set_current_level(int level)
{
    current_level = level;
}

int GameState::get_current_level()
{
    return current_level;
}