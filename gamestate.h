#pragma once

#include <utility>

class GameState
{
public:
    void set_window_size(std::pair<int,int> rows_cols);
    std::pair<int,int> get_window_size();
private:
    std::pair<int,int> window_size = {0,0};
};