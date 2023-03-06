#include "game.h"
#include "terminal.h"
void Game::run() // runs a game loop in a terminal-based environment
{	

    auto& term = Terminal::instance();
    auto size = term.get_size(); // get the size of the terminal
    term.show_cursor(false);// hides the terminal cursos 
    bool run = true;
    bool titlescreen=true;
    
    int x, y, fruitX, fruitY, score;
    
    x = size.first / 2;
    y = size.second / 2;
    fruitX = (rand() % (size.first-2))+2;
    fruitY = (rand() % (size.second-2))+2;
    score = 0;
  
    
    while(run) // run until run is false
    {
        char c = Terminal::instance().read_char();//each iteration reads a character 
        
        if(c && c !='q' && titlescreen)
        {
            draw(); //calls the function draw
        }
        if(c == 'q')// exits the loop. Exists the game
        {
            Terminal::instance().clear();//clear the terminal
            Terminal::instance().move_to(1,1);//move the cursor to origin(1,1)
            run = false; //breaks the loop
        }
        if (c == 's' || c == 'i'||c == 'j'||c == 'k'||c == 'l' )
        {                        	
	    Terminal::instance().clear();//clear the terminal
	    titlescreen=false;
	    snake_state(c,x,y,fruitX,fruitY);
        }
    }
    term.show_cursor(true);//shows the terminal cursor
}

void Game::draw()// displays the current state of the game in the terminal
{
    auto& term = Terminal::instance();//reference to the terminal
    term.clear(); //clears the screen
    term.move_to(1,1);//moves to the origin 
    auto size = term.get_size(); // get the size of the terminal
    term.set_text_color(TextColor::GREEN); //text is green
    //print top bounding row
    for(int i = 0; i < size.second; ++i)
    {
        term.print("-");//prints a row of '-'
    }

    //print bottom bounding row
    term.move_to(size.first, 1);
    for(int i = 0; i < size.second; ++i)
    {
        term.print("-");//prints a row of '-'
    }

    //print left bounding row
    for(int i = 2; i < size.first; ++i)
    {
        term.move_to(i, 1);
        term.print("|");//prints a column of '|'
    }

    //print right bounding row
    for(int i = 2; i < size.first; ++i)
    {
        term.move_to(i, size.second);
        term.print("|");//prints a column of '|'
    }

    term.set_text_color(TextColor::WHITE);//text color is white

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


void Game::snake_state(char d, int& x, int& y, int fruitX, int fruitY)
{	

	auto& term = Terminal::instance();//reference to the terminal
	term.clear(); //clears the screen
	term.move_to(1,1);//moves to the origin 
	auto size = term.get_size(); // get the size of the terminal

    	enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
        eDirection dir;
        dir = STOP;
      
        if (d == 'j')
        {
        	dir = LEFT;
        }
        if (d == 'l')
            	dir = RIGHT;
        if (d == 'k')
            	dir = DOWN;
        if (d == 'i')
            	dir = UP;
            	
        switch(dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;	
	default:
		break;
	}
	term.set_text_color(TextColor::WHITE);//text color is white
    	//print top bounding row
    	for(int i = 0; i < size.second; ++i)
    	{
        	term.print("-");//prints a row of '-'
    	}

    	//print bottom bounding row
    	term.move_to(size.first, 1);
    	for(int i = 0; i < size.second; ++i)
    	{
        	term.print("-");//prints a row of '-'
    	}
    	    //print left bounding row
    	for(int i = 2; i < size.first; ++i)
    	{
        	term.move_to(i, 1);
        	term.print("|");//prints a column of '|'
    	}
    	    //print right bounding row
    	for(int i = 2; i < size.first; ++i)
    	{
        	term.move_to(i, size.second);
        	term.print("|");//prints a column of '|'
    	}
    	
	
	for (int i = 2; i  < size.first; i++)//chech the initial number
	{
		for (int j = 2; j  < size.second ; j++)//chech the initial number
		{
			if (i == x && j == y)
			{
				term.set_text_color(TextColor::YELLOW);
				term.move_to(i,j);
				term.print("X");
			}
			else if (i == fruitX && j == fruitY)
			{ 
				term.set_text_color(TextColor::BLUE);
				term.move_to(i,j);
				term.print("F");
			}
		}
	
	}
	// score for later
	//term.set_text_color(TextColor::BLUE); 
	//term.move_to(0,size.size);
	//term.print("score");
	
	
}

//void Game::logic()
//{
//	switch(dir)
//	{
//	case LEFT:
//		x--;
//		break;
//	case RIGTH:
//		x++;
//		break;
//	case UP:
//		y--;
//		break;
//	case DOWN:
//		y++;
//		break;	
//	default:
//		break;//
//	}

//}


