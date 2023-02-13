#include "game.h"
#include "terminal.h"

void Game::run()
{
    auto& term = Terminal::instance();
    term.show_cursor(false);
    bool run = true;
    while(run)
    {
        char c = Terminal::instance().read_char();
        if(c && c !='q')
        {
            draw();
        }
        if(c == 'q')
        {
            Terminal::instance().clear();
            Terminal::instance().move_to(1,1);
            run = false;
        }
    }
    term.show_cursor(true);
}

void Game::draw()
{
    auto& term = Terminal::instance();
    term.clear();
    term.move_to(1,1);
    auto size = term.get_size();
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
    
    line = "Anton Quelle (anton.quelle@pasqal.com)";
    term.move_to(5, (size.second - line.length())/2);
    term.print(line);
    
    line = "q=quit, s=start";
    term.move_to(size.first-1, 2);
    term.print(line);
    
    line = "\x1b[34mo     \x1b[33mX\x1b[35mpasqalpasqal\x1b[37m";
    term.move_to(11, size.second/2-10);
    term.print(line);
}
