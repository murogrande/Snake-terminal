#pragma once

#include <utility>

class GameState
{
public:
    void set_window_size(std::pair<int,int> rows_cols);
    std::pair<int,int> get_window_size();
    void set_current_level(int level);
    int get_current_level();
private:
    std::pair<int,int> window_size = {0,0};
    int current_level = 0;
};
