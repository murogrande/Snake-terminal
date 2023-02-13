#include <string>

enum TextColor
{
    BLACK=30,
    RED=31,
    GREEN=32,
    YELLOW=33,
    BLUE=34,
    MAGENTA=35,
    CYAN=36,
    WHITE=37
};

class Terminal
{
private:
    Terminal();
    ~Terminal();
public:    
    static Terminal& instance();
    Terminal(Terminal const&) = delete;
    void operator=(Terminal const&) = delete;
    void print(std::string str);
    void move_to(int row, int column); //1-based indexing
    void clear();
    std::pair<int,int> get_size();
    char read_char();
    void set_text_color(TextColor color);
    void show_cursor(bool show);
};