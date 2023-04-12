#pragma once

#include <utility>

enum CurrentLevel
{
    TITLE_SCREEN=0,
    SNAKE_STATE=1,
    NUM_LEVELS=2
};

class GameState
{
public:
    void set_window_size(std::pair<int,int> rows_cols);
    std::pair<int,int> get_window_size();
    void set_current_level(CurrentLevel level);
    int get_current_level();
private:
    std::pair<int,int> window_size = {0,0};
    CurrentLevel current_level = TITLE_SCREEN;
};
