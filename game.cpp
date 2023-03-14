#include "game.h"
#include "terminal.h"
#include "title_screen.h"
#include "snake_state.h"
Game::Game()
{
    levels.emplace_back(std::make_shared<TitleScreen>(gamestate));
    //levels.emplace_back(std::make_shared<SnakeState>(gamestate));
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
    

    int x, y, fruitX, fruitY, score;
    
    x = size.first / 2;
    y = size.second / 2;
    fruitX = (rand() % (size.first-2))+2;
    fruitY = (rand() % (size.second-2))+2;
    score = 0;
    bool titlescreen=true;
    
    
    while(run)
    {
        char c = term.read_char();
        if(c && c !='q' && titlescreen)
        {
            levels.front()->draw();
        }
        if(c == 'q')
        {
            Terminal::instance().clear();
            Terminal::instance().move_to(1,1);
            run = false;
        }
        if (c == 's' || c == 'i'||c == 'j'||c == 'k'||c == 'l' )
        {                        	
	    Terminal::instance().clear();//clear the terminal
	    titlescreen=false;
	    gamestate->draw_snake(c,x,y,fruitX,fruitY);
	}
    }
}
