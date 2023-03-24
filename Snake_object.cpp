#include "snake_state.h"
#include "terminal.h"
#include "Snake_object.h"
#include "title_screen.h"

Snake_object::Snake_object(std::shared_ptr<GameState> gamestate): Level(gamestate)
{ 
    auto size = gamestate->get_window_size();
    
    positionX= size.first / 2;
    positionY= size.second / 2;
}

Snake_object::~Snake_object()
{

}

void Snake_object::updatePosition(char c)
{
    enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
        dir = STOP;
        if (c == 'j')
        	dir = LEFT;
        if (c == 'l')
            	dir = RIGHT;
        if (c == 'k')
            	dir = DOWN;
        if (c == 'i')
            	dir = UP;
 
        switch(dir)
	{
	case LEFT:
		positionY--;//move to left
		break;
	case RIGHT:
		positionY++;//move to right
		break;
	case UP:
		positionX--;//move up
		break;
	case DOWN:
		positionX++;//move down
		break;	
	default:
		break;
	}
}

bool Snake_object::crash_boundary(int posX, int posY)
{       auto& term = Terminal::instance();
        auto size = term.get_size();
        int middleX = size.first/2;
        int middleY = size.second/2;

        if ((positionX <0 || positionX > (size.first-4) || positionY<0 || positionY>(size.second-4))){
            term.set_text_color(TextColor::BLUE);
            term.clear();
		    term.move_to(middleX,middleY);
		    term.print("Game Over");
            gamestate->set_current_level(0);
            //it cannot draw char is empty
            return true;  
        }
        return false;
}

void Snake_object::draw(char c)
{
    auto& term = Terminal::instance();
    auto size = term.get_size();

    bool constrainBoundary = crash_boundary(positionX,positionY);
    
    updatePosition(c);    
    boundary();

    for (int i = 2; i  < size.first; i++)//chech the initial number
	{
		for (int j = 2; j  < size.second ; j++)//chech the initial number
		{
			if (i == positionX && j == positionY)
			{
				term.set_text_color(TextColor::YELLOW);
				term.move_to(i,j);
				term.print("X");    
			}
			//fruit went here
		}
	
	}
	
}


/// setter and getter
void Snake_object::setPositionX(int posX){
    this -> positionX = posX;
}

int Snake_object::getPositionX(){
    return positionX;
}

void Snake_object::setPositionY(int posY){
    this -> positionY = posY;
}

int Snake_object::getPositionY(){
    return positionY;
}
/////////////////






