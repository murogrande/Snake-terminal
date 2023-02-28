#include "snake_game.h"
#include "terminal.h"

SnakeGame::SnakeGame(std::shared_ptr<GameState> gamestate) : Level(gamestate, nullptr)
{
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::step(char)
{
    if(dirty)
    {
        auto& term = Terminal::instance();
        auto size = gamestate->get_window_size();
        term.clear();
        term.move_to(1,1);
        term.set_text_color(TextColor::GREEN);
        //print top bounding row
        for(int i = 0; i < size.second; ++i)
        {
            term.print("-");
        }

        //print bottom bounding row
        term.move_to(size.first, 1);
        for(int i = 0; i < size.second; ++i)
        {
            term.print("-");
        }

        //print left bounding row
        for(int i = 2; i < size.first; ++i)
        {
            term.move_to(i, 1);
            term.print("|");
        }

        //print right bounding row
        for(int i = 2; i < size.first; ++i)
        {
            term.move_to(i, size.second);
            term.print("|");
        }
        dirty = false;
    }
}