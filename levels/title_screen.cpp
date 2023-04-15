#include "title_screen.h"
#include "../io/terminal.h"

TitleScreen::TitleScreen(std::shared_ptr<GameState> gamestate) : Level(gamestate)
{
}

void TitleScreen::draw(char c)
{
    if(c == 's')
    {
        dirty = true;
        gamestate->set_current_level(CurrentLevel::SNAKE_STATE);
    }
    else if(dirty)
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

        term.set_text_color(TextColor::WHITE);

        std::string line = "Terminal Snake";
        term.move_to(3, (size.second - line.length())/2);
        term.print(line);
        
        line = "By:";
        term.move_to(4, (size.second - line.length())/2);
        term.print(line);
        
        line = "anton.quelle@pasqal.com";
        term.move_to(5, (size.second - line.length())/2);
        term.print(line);
        
        line = "mauro.mendizabal-pico@pasqal.com";
        term.move_to(6, (size.second - line.length())/2);
        term.print(line);        
        
        line = "q=quit, s=start, i,j,k,l=move";
        term.move_to(size.first-1, 2);
        term.print(line);
        
        line = "\x1b[36mo     \x1b[37mX\x1b[32mpasqalpasqal\x1b[37m";
        term.move_to(std::min(11,size.first-2), size.second/2-10);
        term.print(line);    
        dirty = false;
    }
}
