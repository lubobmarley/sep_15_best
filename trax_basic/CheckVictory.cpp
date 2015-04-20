#include "CheckVictory.h"

CheckVictory::CheckVictory(int x, int y, int v, int w):
    red_counter_row_(x), red_counter_column_(y), white_counter_row_(v), white_counter_column_(w)
{

}


CheckVictory::~CheckVictory()
{
    
}


std::string CheckVictory::getPlayerColor()
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


void CheckVictory::sieg()
{
    
    switch(game.getActivePlayer())
    {
            case COLOR_WHITE:
                if(white_counter_column_ <= -8 || white_counter_row_ <= -8
                        || white_counter_column_ >= 8 || white_counter_row_ >= 8)
                {
                    std::cout << "Player white wins!" << std::endl;
                    game.setRunning(false);
                }
                else if(red_counter_column_ <= -8 || red_counter_row_ <= -8
                        || red_counter_column_ >= 8 || red_counter_row_ >= 8)
                {
                    std::cout << "Player red wins!" << std::endl;
                    game.setRunning(false);
                }
                break;
                
            case COLOR_RED:
                if(red_counter_column_ <= -8 || red_counter_row_ <= -8
                        || red_counter_column_ >= 8 || red_counter_row_ >= 8)
                {
                    std::cout << "Player red wins!" << std::endl;
                    game.setRunning(false);
                }
                else if(white_counter_column_ <= -8 || white_counter_row_ <= -8
                        || white_counter_column_ >= 8 || white_counter_row_ >= 8)
                {
                    std::cout << "Player white wins!" << std::endl;
                    game.setRunning(false);
                }
                break;
    }
}


void CheckVictory::siegLoop(std::vector<Position> &coord, int counter, int increment)
{
    
    if(coord[counter].getX() == coord[increment].getX() &&
       coord[counter].getY() == coord[increment].getY())
    {
        std::cout << "Player " << getPlayerColor() << " wins!" << std::endl;
        game.setRunning(false);
    }
}


void CheckVictory::checkSurrounding(std::vector<Tile> &tile, std::vector<Position> &coord)
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
		            if((coord[increment].getX()   == coord[counter].getX()) && 
		         	  (coord[increment].getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         white_counter_row_++;
		            		tileTop(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        white_counter_row_--;
		            		tileBottom(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         red_counter_column_++;
		            		tileRight(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        red_counter_column_--;
		            		tileLeft(tile, coord, counter, increment);
		            	}
                           }
	}
        if((tile[increment].getSide()   == Tile::TYPE_CROSS) && 
           (tile[increment].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((coord[increment].getX()   == coord[counter].getX()) && 
		         	  (coord[increment].getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         red_counter_row_++;
		            		tileTop(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        red_counter_row_--;
		            		tileBottom(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         white_counter_column_++;
		            		tileRight(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        white_counter_column_--;
		            		tileLeft(tile, coord, counter, increment);
		            	}
                           }
            }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[increment].getColor() == COLOR_WHITE))
            {
            	 if((coord[increment].getX()   == coord[counter].getX()) && 
		         	  (coord[increment].getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         white_counter_row_++;
		            		tileTop(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        red_counter_row_--;
		            		tileBottom(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         red_counter_column_++;
		            		tileRight(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        white_counter_column_--;
		            		tileLeft(tile, coord, counter, increment);
		            	}
                           }
            }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[increment].getColor() == COLOR_RED))
            {
            	if((coord[increment].getX()   == coord[counter].getX()) && 
		         	  (coord[increment].getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         red_counter_row_++;
		            		tileTop(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        white_counter_row_--;
		            		tileBottom(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         white_counter_column_++;
		            		tileRight(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        red_counter_column_--;
		            		tileLeft(tile, coord, counter, increment);
		            	}
                           }
            
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[increment].getColor() == COLOR_WHITE))
            {
            	if((coord[increment].getX()   == coord[counter].getX()) && 
		         	  (coord[increment].getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         white_counter_row_++;
		            		tileTop(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        red_counter_row_--;
		            		tileBottom(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         white_counter_column_++;
		            		tileRight(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        red_counter_column_--;
		            		tileLeft(tile, coord, counter, increment);
		            	}
                           }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[increment].getColor() == COLOR_RED))
            {
            	if((coord[increment].getX()   == coord[counter].getX()) && 
		         	  (coord[increment].getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         red_counter_row_++;
		            		tileTop(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        white_counter_row_--;
		            		tileBottom(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         red_counter_column_++;
		            		tileRight(tile, coord, counter, increment);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        white_counter_column_--;
		            		tileLeft(tile, coord, counter, increment);
		            	}
                           
            }
}


void CheckVictory::tileTop(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment)
{
    int temp_counter = counter;
    
    if((tile[temp_counter].getSide()   == Tile::TYPE_CROSS) && 
       (tile[temp_counter].getColor()  == COLOR_WHITE))
            { 
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((coord[temp_counter].getX()   == coord[counter].getX()) && 
		         	  (coord[temp_counter].getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment);
		            		white_counter_row_++;
		            		tileTop(tile, coord, counter, increment);
		            	}
			    }
	         }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CROSS) && 
           (tile[temp_counter].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((coord[temp_counter].getX()   == coord[counter].getX()) && 
		         	  (coord[temp_counter].getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment);
		            		red_counter_row_++;
		            		tileTop(tile, coord, counter, increment);
		            	}
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[temp_counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()+1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	red_counter_row_++;
			            	tileRight(tile, coord, counter, increment);
			            }
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[temp_counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()+1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	white_counter_row_++;
			            	tileRight(tile, coord, counter, increment);
			            }
			    }            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[temp_counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()-1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	red_counter_row_++;
			            	tileLeft(tile, coord, counter, increment);
			            }
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[temp_counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()-1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	white_counter_row_++;
			            	tileLeft(tile, coord, counter, increment);
			            }
			    }
            }
    sieg();
}


void CheckVictory::tileBottom(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment)
{
            int temp_counter = counter;
	if((tile[temp_counter].getSide()   == Tile::TYPE_CROSS) && 
       (tile[temp_counter].getColor()  == COLOR_WHITE))
            { 
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((coord[temp_counter].getX()   == coord[counter].getX()) && 
		         	  (coord[temp_counter].getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment);
		            		white_counter_row_--;
		            		tileBottom(tile, coord, counter, increment);
		            	}
			    }
	         }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CROSS) && 
           (tile[temp_counter].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((coord[temp_counter].getX()   == coord[counter].getX()) && 
		         	  (coord[temp_counter].getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment);
		            		red_counter_row_--;
		            		tileBottom(tile, coord, counter, increment);
		            	}
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[temp_counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()+1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	white_counter_row_--;
			            	tileLeft(tile, coord, counter, increment);
			            }
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[temp_counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()+1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	red_counter_row_--;
			            	tileLeft(tile, coord, counter, increment);
			            }
			    }            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[temp_counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()-1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	white_counter_row_--;
			            	tileRight(tile, coord, counter, increment);
			            }
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[temp_counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()-1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	red_counter_row_--;
			            	tileRight(tile, coord, counter, increment);
			            }
			    }
            }
            sieg();
}


void CheckVictory::tileLeft(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment)
{
            int temp_counter = counter;
	if((tile[temp_counter].getSide()   == Tile::TYPE_CROSS) && 
       (tile[temp_counter].getColor()  == COLOR_WHITE))
            { 
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((coord[temp_counter].getX()   == coord[counter].getX()) && 
		         	  (coord[temp_counter].getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment);
		            		red_counter_column_--;
		            		tileLeft(tile, coord, counter, increment);
		            	}
			    }
	         }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CROSS) && 
           (tile[temp_counter].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((coord[temp_counter].getX()   == coord[counter].getX()) && 
		         	  (coord[temp_counter].getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment);
		            		white_counter_column_--;
		            		tileLeft(tile, coord, counter, increment);
		            	}
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[temp_counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()+1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	red_counter_column_--;
			            	tileBottom(tile, coord, counter, increment);
			            }
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[temp_counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()+1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	white_counter_column_--;
			            	tileBottom(tile, coord, counter, increment);
			            }
			    }            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[temp_counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()-1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	white_counter_column_--;
			            	tileTop(tile, coord, counter, increment);
			            }
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[temp_counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()-1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	red_counter_column_--;
			            	tileTop(tile, coord, counter, increment);
			            }
			    }
            }
            sieg();
}


void CheckVictory::tileRight(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment)
{
            int temp_counter = counter;
	if((tile[temp_counter].getSide()   == Tile::TYPE_CROSS) && 
       (tile[temp_counter].getColor()  == COLOR_WHITE))
            { 
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((coord[temp_counter].getX()   == coord[counter].getX()) && 
		         	  (coord[temp_counter].getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment);
		            		red_counter_column_++;
		            		tileRight(tile, coord, counter, increment);
		            	}
			    }
	         }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CROSS) && 
           (tile[temp_counter].getColor() == COLOR_RED)) 
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
		            if((coord[temp_counter].getX()   == coord[counter].getX()) && 
		         	  (coord[temp_counter].getY()+1 == coord[counter].getY()))
		            	{ 
                                        siegLoop(coord, counter, increment);
		            		white_counter_column_++;
		            		tileRight(tile, coord, counter, increment);
		            	}
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[temp_counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()+1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	white_counter_column_++;
			            	tileTop(tile, coord, counter, increment);
			            }
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[temp_counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()+1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY() == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	red_counter_column_++;
			            	tileTop(tile, coord, counter, increment);
			            }
			    }            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[temp_counter].getColor() == COLOR_WHITE))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()-1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	red_counter_column_++;
			            	tileBottom(tile, coord, counter, increment);
			            }
			    }
            }
        if((tile[temp_counter].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[temp_counter].getColor() == COLOR_RED))
            {
            	for(counter = 0; counter < tile.size(); counter++)
    			{
			        if((coord[temp_counter].getX()-1 == coord[counter].getX()) && 
			           (coord[temp_counter].getY()   == coord[counter].getY()))
			            {
                                        siegLoop(coord, counter, increment);
			            	white_counter_column_++;
			            	tileBottom(tile, coord, counter, increment);
			            }
			    }
            }
            sieg();
}


void CheckVictory::unentschieden()
{
    std::cout << "No more tiles left. Game ends in a draw!" << std::endl;
    game.setRunning(false);
}
