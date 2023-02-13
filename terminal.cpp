#include "terminal.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <poll.h>
#include <termios.h>

static termios s_flags;

Terminal::Terminal()
{
    std::cin >> std::noskipws;
    std::cout << std::unitbuf; //don't buffer output
    if (tcgetattr(STDIN_FILENO,&s_flags)<0) 
    {
        std::cout << "Failed to get flags for std::cin\n";
        exit(1);    
    }
    std::cout << s_flags.c_cc[VTIME];
    termios flags = s_flags;
    flags.c_lflag &= ~ICANON; // no line buffering
    flags.c_lflag &= ~ECHO; // don't echo input
    flags.c_lflag &= ~OPOST; // don't post process output
    flags.c_cc[VMIN] = 0; // block until at least 0 chars have been read
    flags.c_cc[VTIME] = 1; // or 1*0.1secs have passed
    if (tcsetattr(STDIN_FILENO,TCSANOW,&flags)<0) 
    {
        std::cout << "Failed to set flags for std::cin\n";
        exit(2);
    }
}

Terminal::~Terminal()
{
    tcsetattr(STDIN_FILENO,TCSANOW,&s_flags);
}

Terminal& Terminal::instance()
{
    static Terminal instance;
    return instance;
}

void Terminal::print(std::string str)
{
    std::cout << str;
}

void Terminal::clear()
{
    std::cout << "\x1b[2J";
}

std::pair<int,int> Terminal::get_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return std::pair<int, int>(w.ws_row, w.ws_col);
}

char Terminal::read_char()
{
  char c;
  //don't use std::in, it does some high level logic that is not compatible with our termios settings
  read(STDIN_FILENO, &c, 1);
  return c;
}

void Terminal::move_to(int row, int column)
{
    std::cout << "\x1b[" << std::to_string(row) << ";" << std::to_string(column) << "H";
}

void Terminal::set_text_color(TextColor color)
{
    std::cout << "\x1b[" << std::to_string(color) << "m";
}

void Terminal::show_cursor(bool show)
{
    if(show)
        std::cout << "\x1b[?25h";
    else
        std::cout << "\x1b[?25l";
}