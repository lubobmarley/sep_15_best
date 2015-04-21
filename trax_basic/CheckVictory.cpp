#include "CheckVictory.h"

CheckVictory::CheckVictory(): red_counter_column_(1), red_counter_row_(1), white_counter_column_(1),white_counter_row_(1)
{

}


CheckVictory::~CheckVictory()
{
    
}


std::string CheckVictory::getPlayerColor(int active_player)
{
    
    if(active_player == COLOR_WHITE)
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


bool CheckVictory::sieg(std::vector<Tile> &tile, std::vector<Position> &coord, int active_player)
{
    int increment;
    int counter = 0;
    
    for(increment = 0; increment <= tile.size(); increment ++)
    {
        setCounters();
        counter = increment;
        if((tile[increment].getSide()   == Tile::TYPE_CROSS) && 
           (tile[increment].getColor()  == COLOR_WHITE))
        { 
            if(tileTop(tile, coord, counter, increment, active_player) || tileBottom(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player white wins!" << std::endl;
                return false;
            }
            else if(tileRight(tile, coord, counter, increment, active_player) || tileLeft(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player red wins!" << std::endl;
                return false;
            }
        }
        if((tile[increment].getSide()   == Tile::TYPE_CROSS) && 
           (tile[increment].getColor()  == COLOR_RED))
        { 
            if(tileTop(tile, coord, counter, increment, active_player) || tileBottom(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player red wins!" << std::endl;
                return false;
            }
            else if(tileRight(tile, coord, counter, increment, active_player) || tileLeft(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player white wins!" << std::endl;
                return false;
            }
        }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[increment].getColor()  == COLOR_WHITE))
        { 
            if(tileTop(tile, coord, counter, increment, active_player) || tileLeft(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player white wins!" << std::endl;
                return false;
            }
            else if(tileRight(tile, coord, counter, increment, active_player) || tileBottom(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player red wins!" << std::endl;
                return false;
            }
        }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_1) && 
           (tile[increment].getColor()  == COLOR_RED))
        { 
            if(tileTop(tile, coord, counter, increment, active_player) || tileLeft(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player red wins!" << std::endl;
                return false;
            }
            else if(tileRight(tile, coord, counter, increment, active_player) || tileBottom(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player white wins!" << std::endl;
                return false;
            }
        }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[increment].getColor()  == COLOR_WHITE))
        { 
            if(tileTop(tile, coord, counter, increment, active_player) || tileRight(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player white wins!" << std::endl;
                return false;
            }
            if(tileLeft(tile, coord, counter, increment, active_player) || tileBottom(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player white wins!" << std::endl;
                return false;
            }
            if((tile[increment].getSide()   == Tile::TYPE_CURVE_2) && 
               (tile[increment].getColor()  == COLOR_WHITE))
            { 
                if(tileTop(tile, coord, counter, increment, active_player) || tileRight(tile, coord, counter, increment, active_player))
                {
                    std::cout << "Player red wins!" << std::endl;
                    return false;
                }
                if(tileBottom(tile, coord, counter, increment, active_player) || tileLeft(tile, coord, counter, increment, active_player))
            {
                std::cout << "Player white wins!" << std::endl;
                return false;
            }
            }
            
        }   
    }
    return true;
}


bool CheckVictory::siegLoop(std::vector<Position> &coord, int counter, int increment, int active_player)
{
    
    if(coord[counter].getX() == coord[increment].getX() &&
       coord[counter].getY() == coord[increment].getY())
    {
        return true;
    }
    return false;
}


/*void CheckVictory::checkSurrounding(std::vector<Tile> &tile, std::vector<Position> &coord, int active_player)
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
		            		tileTop(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        white_counter_row_--;
		            		tileBottom(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         red_counter_column_++;
		            		tileRight(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        red_counter_column_--;
		            		tileLeft(tile, coord, counter, increment, active_player);
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
		            		tileTop(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        red_counter_row_--;
		            		tileBottom(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         white_counter_column_++;
		            		tileRight(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        white_counter_column_--;
		            		tileLeft(tile, coord, counter, increment, active_player);
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
		            		tileTop(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        red_counter_row_--;
		            		tileBottom(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         red_counter_column_++;
		            		tileRight(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        white_counter_column_--;
		            		tileLeft(tile, coord, counter, increment, active_player);
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
		            		tileTop(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        white_counter_row_--;
		            		tileBottom(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         white_counter_column_++;
		            		tileRight(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        red_counter_column_--;
		            		tileLeft(tile, coord, counter, increment, active_player);
		            	}
                           }
            
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[increment].getColor() == COLOR_WHITE))
            {
            	if((coord[increment].getX()   == coord[counter].getX()) && 
		         	  (coord[increment].getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         white_counter_row_++;
		            		tileTop(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        red_counter_row_--;
		            		tileBottom(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         white_counter_column_++;
		            		tileRight(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        red_counter_column_--;
		            		tileLeft(tile, coord, counter, increment, active_player);
		            	}
                           }
        if((tile[increment].getSide()   == Tile::TYPE_CURVE_2) && 
           (tile[increment].getColor() == COLOR_RED))
            {
            	if((coord[increment].getX()   == coord[counter].getX()) && 
		         	  (coord[increment].getY()+1 == coord[counter].getY()))
		            	{ 
                                                                         red_counter_row_++;
		            		tileTop(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()   == coord[counter].getX()) && 
			           (coord[increment].getY()-1 == coord[counter].getY())) 
			            {
                                                                        white_counter_row_--;
		            		tileBottom(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()+1 == coord[counter].getX()) && 
			           (coord[increment].getY() == coord[counter].getY()))
			            {
                                                                         red_counter_column_++;
		            		tileRight(tile, coord, counter, increment, active_player);
		            	}
			        if((coord[increment].getX()-1 == coord[counter].getX()) && 
			           (coord[increment].getY()   == coord[counter].getY()))
			            {
                                                                        white_counter_column_--;
		            		tileLeft(tile, coord, counter, increment, active_player);
		            	}
                           
            }
}
*/

bool CheckVictory::tileTop(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment, int active_player)
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
		            		white_counter_row_++;
		            		tileTop(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
		            		red_counter_row_++;
		            		tileTop(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	red_counter_row_++;
			            	tileRight(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	white_counter_row_++;
			            	tileRight(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	red_counter_row_++;
			            	tileLeft(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	white_counter_row_++;
			            	tileLeft(tile, coord, counter, increment, active_player);
			            }
			    }
            }
    if(red_counter_row_ >= 8 || white_counter_row_ >= 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool CheckVictory::tileBottom(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment, int active_player)
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
		            		white_counter_row_--;
		            		tileBottom(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
		            		red_counter_row_--;
		            		tileBottom(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	white_counter_row_--;
			            	tileLeft(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	red_counter_row_--;
			            	tileLeft(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	white_counter_row_--;
			            	tileRight(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	red_counter_row_--;
			            	tileRight(tile, coord, counter, increment, active_player);
			            }
			    }
            }
        return false;
}


bool CheckVictory::tileLeft(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment, int active_player)
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
		            		red_counter_column_--;
		            		tileLeft(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
		            		white_counter_column_--;
		            		tileLeft(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	red_counter_column_--;
			            	tileBottom(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	white_counter_column_--;
			            	tileBottom(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	white_counter_column_--;
			            	tileTop(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	red_counter_column_--;
			            	tileTop(tile, coord, counter, increment, active_player);
			            }
			    }
            }
            return false;
}


bool CheckVictory::tileRight(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment, int active_player)
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
		            		red_counter_column_++;
		            		tileRight(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
		            		white_counter_column_++;
		            		tileRight(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	white_counter_column_++;
			            	tileTop(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	red_counter_column_++;
			            	tileTop(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	red_counter_column_++;
			            	tileBottom(tile, coord, counter, increment, active_player);
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
                                        if(siegLoop(coord, counter, increment, active_player))
                                        {
                                            return true;
                                        }
			            	white_counter_column_++;
			            	tileBottom(tile, coord, counter, increment, active_player);
			            }
			    }
            }
    if(red_counter_column_ >= 8 || white_counter_column_ >= 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool CheckVictory::unentschieden(std::vector<Tile> &tile)
{
    if(tile.size() > 64)
    {
    std::cout << "No more tiles left. Game ends in a draw!" << std::endl;
    return false;
    }
    return true;
}