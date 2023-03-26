#include "game.h"
#include "terminal.h"
#include "title_screen.h"
#include "snake_state.h"
Game::Game()
{
    auto& term = Terminal::instance();
    auto size = term.get_size();
    gamestate->set_window_size(size);
    levels.emplace_back(std::make_shared<TitleScreen>(gamestate));
    levels.emplace_back(std::make_shared<SnakeState>(gamestate));
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
