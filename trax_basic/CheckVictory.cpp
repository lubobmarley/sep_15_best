#include "CheckVictory.h"

CheckVictory::CheckVictory():
    red_counter_row_(1), red_counter_column_(1), white_counter_row_(1), white_counter_column_(1)
{

}


CheckVictory::~CheckVictory()
{
    
}


std::string CheckVictory::getPlayerColor(Game game)
{
	if(game.getActivePlayer() == COLOR_WHITE)
	{
		return "white";
	}
	else
	{
		return "red";
	}
}


void CheckVictory::setCounters()
{
    red_counter_row_ = 1;
    red_counter_column_ = 1;
    white_counter_row_=  1;
    white_counter_column_ = 1;
}


int CheckVictory::siegLoop(std::vector<Position> &coord, int counter, int increment, Game game)
{
    if(coord[counter].getX() == coord[increment].getX() &&
       coord[counter].getY() == coord[increment].getY())
    {
        std::cout << "Player " << getPlayerColor(game) << " wins!" << std::endl;
        game.setRunning(false);
        return 0;
    }
}


void CheckVictory::sieg(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, Game game)
{
    int increment;
    int counter;
    
    for(increment = 0; increment < tile.size(); increment++)
    {
        setCounters();
        
        if((tile[increment].getSide()   == Tile::TYPE_CROSS) && 
           (tile[increment].getColor()  == COLOR_WHITE))
            { 
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         white_counter_column_++;
		            		tileTop(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()   == coord[counter].getX()) && 
			           (position.getY()-1 == coord[counter].getY())) 
			            {
                                                                        white_counter_column_--;
		            		tileBottom(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                                                         red_counter_row_++;
		            		tileRight(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                                                        red_counter_row_--;
		            		tileLeft(tile, coord, position, counter, increment, game);
		            	}
                           }
	}
        if((tile[increment].getSide()   == Tile::TYPE_CROSS) && 
           (tile[increment].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         red_counter_column_++;
		            		tileTop(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()   == coord[counter].getX()) && 
			           (position.getY()-1 == coord[counter].getY())) 
			            {
                                                                        red_counter_column_--;
		            		tileBottom(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                                                         white_counter_row_++;
		            		tileRight(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                                                        white_counter_row_--;
		            		tileLeft(tile, coord, position, counter, increment, game);
		            	}
                           }
            }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[increment].getColor() == COLOR_WHITE))
            {
            	 if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         white_counter_column_++;
		            		tileTop(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()   == coord[counter].getX()) && 
			           (position.getY()-1 == coord[counter].getY())) 
			            {
                                                                        red_counter_column_--;
		            		tileBottom(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                                                         red_counter_row_++;
		            		tileRight(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                                                        white_counter_row_--;
		            		tileLeft(tile, coord, position, counter, increment, game);
		            	}
                           }
            }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[increment].getColor() == COLOR_RED))
            {
            	if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         red_counter_column_++;
		            		tileTop(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()   == coord[counter].getX()) && 
			           (position.getY()-1 == coord[counter].getY())) 
			            {
                                                                        white_counter_column_--;
		            		tileBottom(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                                                         white_counter_row_++;
		            		tileRight(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                                                        red_counter_row_--;
		            		tileLeft(tile, coord, position, counter, increment, game);
		            	}
                           }
            
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[increment].getColor() == COLOR_WHITE))
            {
            	if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         white_counter_column_++;
		            		tileTop(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()   == coord[counter].getX()) && 
			           (position.getY()-1 == coord[counter].getY())) 
			            {
                                                                        red_counter_column_--;
		            		tileBottom(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                                                         white_counter_row_++;
		            		tileRight(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                                                        red_counter_row_--;
		            		tileLeft(tile, coord, position, counter, increment, game);
		            	}
                           }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[increment].getColor() == COLOR_RED))
            {
            	if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         red_counter_column_++;
		            		tileTop(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()   == coord[counter].getX()) && 
			           (position.getY()-1 == coord[counter].getY())) 
			            {
                                                                        white_counter_column_--;
		            		tileBottom(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                                                         red_counter_row_++;
		            		tileRight(tile, coord, position, counter, increment, game);
		            	}
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                                                        white_counter_row_--;
		            		tileLeft(tile, coord, position, counter, increment, game);
		            	}
                           
            }
}


int CheckVictory::tileTop(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, int counter, int increment, Game game)
{
    if((tile[counter].getSide()   == Tile::TYPE_CROSS) && 
       (tile[counter].getColor()  == COLOR_WHITE))
            { 
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment, game);
		            		white_counter_column_++;
		            		tileTop(tile, coord, position, counter, increment, game);
		            	}
			    }
	         }
        if((tile[counter].getSide()   == Tile::TYPE_CROSS) && 
           (tile[counter].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment, game);
		            		red_counter_column_++;
		            		tileTop(tile, coord, position, counter, increment, game);
		            	}
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	red_counter_column_++;
			            	tileRight(tile, coord, position, counter, increment, game);
			            }
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	white_counter_column_++;
			            	tileRight(tile, coord, position, counter, increment, game);
			            }
			    }            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	red_counter_column_++;
			            	tileLeft(tile, coord, position, counter, increment, game);
			            }
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	white_counter_column_++;
			            	tileLeft(tile, coord, position, counter, increment, game);
			            }
			    }
            }
    if(red_counter_column_ >= 8 || white_counter_column_ >= 8)
    {
    	std::cout << "Player " << getPlayerColor(game) << " wins!" << std::endl;
        game.setRunning(false);
		return 0;
    }
}


int CheckVictory::tileBottom(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, int counter, int increment, Game game)
{
	if((tile[counter].getSide()   == Tile::TYPE_CROSS) && 
       (tile[counter].getColor()  == COLOR_WHITE))
            { 
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment, game);
		            		white_counter_column_--;
		            		tileBottom(tile, coord, position, counter, increment, game);
		            	}
			    }
	         }
        if((tile[counter].getSide()   == Tile::TYPE_CROSS) && 
           (tile[counter].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment, game);
		            		red_counter_column_--;
		            		tileBottom(tile, coord, position, counter, increment, game);
		            	}
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	white_counter_column_--;
			            	tileLeft(tile, coord, position, counter, increment, game);
			            }
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	red_counter_column_--;
			            	tileLeft(tile, coord, position, counter, increment, game);
			            }
			    }            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	white_counter_column_--;
			            	tileRight(tile, coord, position, counter, increment, game);
			            }
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	white_counter_column_--;
			            	tileRight(tile, coord, position, counter, increment, game);
			            }
			    }
            }
    if(red_counter_column_ <= -8 || white_counter_column_ <= -8)
    {
    	std::cout << "Player " << getPlayerColor(game) << " wins!" << std::endl;
	game.setRunning(false);
        return 0;
    }
}


int CheckVictory::tileLeft(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, int counter, int increment, Game game)
{
	if((tile[counter].getSide()   == Tile::TYPE_CROSS) && 
       (tile[counter].getColor()  == COLOR_WHITE))
            { 
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment, game);
		            		red_counter_row_--;
		            		tileLeft(tile, coord, position, counter, increment, game);
		            	}
			    }
	         }
        if((tile[counter].getSide()   == Tile::TYPE_CROSS) && 
           (tile[counter].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment, game);
		            		white_counter_row_--;
		            		tileLeft(tile, coord, position, counter, increment, game);
		            	}
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	red_counter_row_--;
			            	tileBottom(tile, coord, position, counter, increment, game);
			            }
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	white_counter_row_--;
			            	tileBottom(tile, coord, position, counter, increment, game);
			            }
			    }            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	white_counter_row_--;
			            	tileTop(tile, coord, position, counter, increment, game);
			            }
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	red_counter_row_--;
			            	tileTop(tile, coord, position, counter, increment, game);
			            }
			    }
            }
    if(red_counter_row_ <= -8 || white_counter_row_ <= -8)
    {
    	std::cout << "Player " << getPlayerColor(game) << " wins!" << std::endl;
	game.setRunning(false);
        return 0;
    }
}


int CheckVictory::tileRight(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, int counter, int increment, Game game)
{
	if((tile[counter].getSide()   == Tile::TYPE_CROSS) && 
       (tile[counter].getColor()  == COLOR_WHITE))
            { 
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment, game);
		            		red_counter_row_++;
		            		tileRight(tile, coord, position, counter, increment, game);
		            	}
			    }
	         }
        if((tile[counter].getSide()   == Tile::TYPE_CROSS) && 
           (tile[counter].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((position.getX()   == coord[counter].getX()) && 
		         	  (position.getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment, game);
		            		white_counter_row_++;
		            		tileRight(tile, coord, position, counter, increment, game);
		            	}
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	white_counter_row_++;
			            	tileTop(tile, coord, position, counter, increment, game);
			            }
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()+1 == coord[counter].getX()) && 
			           (position.getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	red_counter_row_++;
			            	tileTop(tile, coord, position, counter, increment, game);
			            }
			    }            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	red_counter_row_++;
			            	tileBottom(tile, coord, position, counter, increment, game);
			            }
			    }
            }
        if((tile[counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((position.getX()-1 == coord[counter].getX()) && 
			           (position.getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment, game);
			            	white_counter_row_++;
			            	tileBottom(tile, coord, position, counter, increment, game);
			            }
			    }
            }
    if(red_counter_row_ >= 8 || white_counter_row_ >= 8)
    {
    	std::cout << "Player " << getPlayerColor(game) << " wins!" << std::endl;
	game.setRunning(false);
        return 0;
    }
}


int CheckVictory::unentschieden(Game game)
{
    std::cout << "No more tiles left. Game ends in a draw!" << std::endl;
    game.setRunning(false);
    return 0;
}
