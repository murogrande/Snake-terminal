#include "game.h"
#include "terminal.h"
#include "title_screen.h"
#include "snake_game.h"

enum Levels
{
    TITLE_SCREEN=0,
    SNAKE_GAME=1,
    LEVEL_COUNT=2 //this should always be last
};

void Game::title_screen_finished()
{    
    gamestate->set_current_level(Levels::SNAKE_GAME);
}

Game::Game()
{
    auto finished_handler = SignalHandler(this, &Game::title_screen_finished);
    levels.emplace_back(std::make_shared<TitleScreen>(gamestate, finished_handler));
    levels.emplace_back(std::make_shared<SnakeGame>(gamestate));
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
    while(run)
    {
        char c = term.read_char();
        if(c == 'q')
        {
            Terminal::instance().clear();
            Terminal::instance().move_to(1,1);
            run = false;
        }
        else
        {
            levels[gamestate->get_current_level()]->step(c);
        }
    }
}