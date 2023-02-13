#include "gamestate.h"

void GameState::set_window_size(std::pair<int,int> rows_cols)
{
    window_size = rows_cols;
}

std::pair<int,int> GameState::get_window_size()
{
    return window_size;
}