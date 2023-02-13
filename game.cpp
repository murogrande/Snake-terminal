#include "game.h"
#include "terminal.h"
#include "title_screen.h"

Game::Game()
{
    levels.emplace_back(std::make_shared<TitleScreen>(gamestate));
    Terminal::instance().show_cursor(false);
}

Game::~Game()
{
    Terminal::instance().show_cursor(true);
}

void Game::run()
{
    auto& term = Terminal::instance();
    bool run = true;
    auto size = term.get_size();
    gamestate->set_window_size(size);
    levels.front()->draw();
    while(run)
    {
        char c = term.read_char();
        if(c && c !='q')
        {
            levels.front()->draw();
        }
        if(c == 'q')
        {
            Terminal::instance().clear();
            Terminal::instance().move_to(1,1);
            run = false;
        }
    }
}