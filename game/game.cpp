#include "game.h"
#include "../io/terminal.h"
#include "../levels/title_screen.h"
#include <chrono>


Game::Game()
{
    auto& term = Terminal::instance();
    auto size = term.get_size();
    gamestate->set_window_size(size);
    levels.emplace_back(std::make_unique<TitleScreen>(gamestate));
    levels.emplace_back(std::make_unique<SnakeGame>(gamestate));
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
            levels[gamestate->get_current_level()]->draw(c);
	    }
    }
}
