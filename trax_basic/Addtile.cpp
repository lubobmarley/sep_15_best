#include "Position.h"
#include "Tile.h"
#include "Game.h"
#include "Addtile.h"
#include "Write.h"
#include <iostream>
#include <string>
#include <vector>
#include "CheckVictory.h"

enum Orientation
{
    TOP = 1,
    BOT = 2,
    RIGHT = 3,
    LEFT = 4          
};




int getOrientation(int& counter, Position tempposition, std::vector<Position> positions)
{
    
    for(counter; counter < positions.size(); counter++)
    {
        if((tempposition.getX()   == positions.at(counter).getX()) && 
           (tempposition.getY()-1 == positions.at(counter).getY()))
            {return TOP;}
        if((tempposition.getX()   == positions.at(counter).getX()) && 
           (tempposition.getY()+1 == positions.at(counter).getY())) 
            {return BOT;}
        if((tempposition.getX()-1 == positions.at(counter).getX()) && 
           (tempposition.getY()   == positions.at(counter).getY()))
            {return RIGHT;}
        if((tempposition.getX()+1 == positions.at(counter).getX()) && 
           (tempposition.getY()   == positions.at(counter).getY()))
            {return LEFT;}
    }
    return 0;
}



Color colorOutput(int direction, Tile temptile)
{
  switch(direction)
    case TOP:
    {
        
        return temptile.getColor();
    
    case BOT:
    
      if((temptile.getColor()  == COLOR_RED          &&
          temptile.getSide()   == Tile::TYPE_CROSS)  ||
          
          (temptile.getColor() == COLOR_WHITE        &&
          (temptile.getSide()  == Tile::TYPE_CURVE_1 ||
          temptile.getSide()   == Tile::TYPE_CURVE_2)))
          return COLOR_RED;
      else
          return COLOR_WHITE;
    
    case RIGHT:
    
      if((temptile.getColor() == COLOR_WHITE          &&
         (temptile.getSide()  == Tile::TYPE_CROSS     ||
          temptile.getSide()  == Tile::TYPE_CURVE_1)) ||
        
         (temptile.getColor() == COLOR_RED            &&
         (temptile.getSide()  == Tile::TYPE_CURVE_2)))
          return COLOR_RED;
      else
          return COLOR_WHITE;
    
    case LEFT:
    
      if((temptile.getColor() == COLOR_WHITE          &&
         (temptile.getSide()  == Tile::TYPE_CROSS     ||
          temptile.getSide()  == Tile::TYPE_CURVE_2)) ||
        
         (temptile.getColor() == COLOR_RED            &&
         (temptile.getSide()  == Tile::TYPE_CURVE_1)))
          return COLOR_RED;
      else
          return COLOR_WHITE;
        
    }    
    
}

bool checkempty(int x, int y, std::vector<Tile> tiles, std::vector<Position> positions)
{
    int counter;
    for(counter = 0; counter < tiles.size(); counter++)
        {
            if(positions.at(counter).getX() == x && positions.at(counter).getY() == y)
               return false;
        }
 return true;
 }


//------------------------------------------------------------------------------
// checktile()
//
// @param tiles, <vector> of all tiles from user input
// @param positions, <vector> of all tiles from user input
// @param temtile, Tile that is used to store userinput
// @param tempposition, position of that temptile
//
// @return bool, returns if tile may be placed
//
bool checktile(Tile& temptile, Position tempposition, std::vector<Tile> tiles, 
               std::vector<Position> positions)
{
    
    temptile.setColor(COLOR_WHITE); //default color   
    if(tiles.size() == 0 && tempposition.getX() == 0 && tempposition.getY() == 0)
    {
        temptile.setColor(COLOR_RED);
        return true;
    }
    
    int counter = 0;
    

    if(!checkempty(tempposition.getX(), tempposition.getY(), tiles, positions))
    {
        std::cout << "Invalid coordinates - field not empty" << std::endl;
        return false;
    }
        
            
    
    int set_red = 0;
    int set_white = 0;
    int identifier = 0;
    
    
    for(counter = 0 ; counter < tiles.size() ; counter++)
    {
       int identifier = getOrientation(counter, tempposition, positions);
       

       
       switch(identifier)
       {           
            case TOP:
                if (colorOutput(TOP, tiles.at(counter)) == colorOutput(BOT, temptile))
                {
                    set_white++;
                    break;
                }
                else
                {
                    temptile.setColor(COLOR_RED);
                    set_red++;
                    break;
                }
                
            case BOT:
                if (colorOutput(BOT, tiles.at(counter)) == colorOutput(TOP, temptile))
                {
                    set_white++;
                    break;
                }
                else
                {
                    temptile.setColor(COLOR_RED);
                    set_red++;
                    break;
                }
            case RIGHT:
                if (colorOutput(RIGHT, tiles.at(counter)) == colorOutput(LEFT, temptile))
                {
                    set_white++;
                    break;
                }
                else
                {
                    temptile.setColor(COLOR_RED);
                    set_red++;
                    break;
                }
            case LEFT:
                if (colorOutput(LEFT, tiles.at(counter)) == colorOutput(RIGHT, temptile))
                {
                    set_white++;
                    break;
                }
                else
                {
                    temptile.setColor(COLOR_RED);
                    set_red++;
                    break;
                }
            default:
            {
                if(counter == tiles.size()-1 && set_red == 0 && set_white == 0)
                {
                    std::cout << "Invalid coordinates - field not connected to tile" << std::endl;    
                    return false;
                }
                else
                    break;
                
            }
       }
    }
  
    if(set_red > 0 && set_white > 0)
    {
        std::cout << "Invalid move - connected line colors mismatch" << std::endl;
        return true;
    }
    else
        return true;
     
}


//------------------------------------------------------------------------------
// swappositions()
//
// @param positions, <position> of all tiles from user input
// @param int i, index to be swapped with j
// @param int j, index to be swapped with i
//
// @return vector<Position> the new vector with swapped elements
//
std::vector<Position> swapposition(std::vector<Position> positions, int i, int j)
{    
    Position tempposition = positions.at(i);
    positions.at(i) = positions.at(j);
    positions.at(j) = tempposition;
    return positions;
}

//------------------------------------------------------------------------------
// swaptiles()
//
// @param tiles, <vector> of all tiles from user input
// @param int i, index to be swapped with j
// @param int j, index to be swapped with i
//
// @return vector<Tile> the new vector with swapped elements
//
std::vector<Tile> swaptiles(std::vector<Tile> tiles, int i, int j)
{    
    Tile temptile = tiles.at(i);
    tiles.at(i) = tiles.at(j);
    tiles.at(j) = temptile;
    return tiles;
}


//------------------------------------------------------------------------------
// sort()
//
// @param tiles, <vector> of all tiles from user input
// @param positions, vector of all coordinates connected to tiles
//
// @return bool returns true if sorted sucessfully
//
bool sort(std::vector<Tile>& tiles, std::vector<Position>& positions)
{
    int counter = positions.size() - 1;
    
    if(positions.size() == 0 || positions.size() == 1)
        return true;
    

    
while(counter > 0)
{
	if(positions.at(counter).getY() >  positions.at(counter-1).getY())
            counter--;
	else if (positions.at(counter).getY() <  positions.at(counter-1).getY())
	{
            tiles = swaptiles(tiles, counter,counter-1);
            positions = swapposition(positions, counter, counter-1);
            counter--;
	}
	else if(positions.at(counter).getY() == positions.at(counter-1).getY())
	{
		if(positions.at(counter).getX() <  positions.at(counter-1).getX())
		{
                    tiles = swaptiles(tiles,counter,counter - 1);
                    positions = swapposition(positions, counter, counter-1);
                    counter --;
                }
                else 
                    counter--;
        }	
}
        
    return true;
}

int getCorner(int& counter, Position tempposition, std::vector<Position> positions)
{
    
    for(counter; counter < positions.size(); counter++)
    {
        if((tempposition.getX() == positions.at(counter).getX() +1) && 
           (tempposition.getY() == positions.at(counter).getY() -1))
            {return 1;}	//NW
        if((tempposition.getX() == positions.at(counter).getX() -1) && 
           (tempposition.getY() == positions.at(counter).getY() -1)) 
            {return 2;} //NO
        if((tempposition.getX() == positions.at(counter).getX() +1) && 
           (tempposition.getY() == positions.at(counter).getY() +1))
            {return 3;} //SW
        if((tempposition.getX() == positions.at(counter).getX() -1) && 
           (tempposition.getY() == positions.at(counter).getY() +1))
            {return 4;} //SO
    }
    return 0;
}
        
      
void fillin(int counter, int direction, int corner, std::vector<Tile>& tiles, std::vector<Position>& positions, Tile& temptile, Position& tempposition)
{
	Tile filltile(Tile::TYPE_CROSS,COLOR_WHITE);
	Position fillposition(0,0);
	if(corner == 1)
	{
		if(direction == TOP)
		{
			fillposition.setX(tempposition.getX());
			fillposition.setY(tempposition.getY()+1);
			if(colorOutput(RIGHT, tiles.at(counter)) == COLOR_WHITE)
                            filltile.setColor(COLOR_RED);
			filltile.setSide(Tile::TYPE_CURVE_2);
		}
		else if(direction == LEFT)
		{
			fillposition.setX(tempposition.getX()-1);
			fillposition.setY(tempposition.getY());
			if(colorOutput(BOT, tiles.at(counter)) == COLOR_RED)
                            filltile.setColor(COLOR_RED);
			filltile.setSide(Tile::TYPE_CURVE_2);
		}
	}
	else if(corner == 2)
	{
		if(direction == TOP)
		{
			fillposition.setX(tempposition.getX());
			fillposition.setY(tempposition.getY()+1);
			if(colorOutput(LEFT, tiles.at(counter)) == COLOR_WHITE)
                            filltile.setColor(COLOR_RED);
			filltile.setSide(Tile::TYPE_CURVE_1);
		}
		if(direction == RIGHT)
		{
			fillposition.setX(tempposition.getX()+1);
			fillposition.setY(tempposition.getY());
			if(colorOutput(BOT, tiles.at(counter)) == COLOR_RED)
                            filltile.setColor(COLOR_RED);
			filltile.setSide(Tile::TYPE_CURVE_1);
		}
	}
	else if(corner == 3)
	{
		if(direction == BOT)
		{
			fillposition.setX(tempposition.getX());
			fillposition.setY(tempposition.getY()-1);
			if(colorOutput(RIGHT, tiles.at(counter)) == COLOR_RED)
                            filltile.setColor(COLOR_RED);
			filltile.setSide(Tile::TYPE_CURVE_1);
		}
		else if(direction == LEFT)
		{
			fillposition.setX(tempposition.getX()-1);
			fillposition.setY(tempposition.getY());
			if(colorOutput(TOP, tiles.at(counter)) == COLOR_WHITE)
                            filltile.setColor(COLOR_RED);
			filltile.setSide(Tile::TYPE_CURVE_1);
		}
	}
	else if(corner == 4)
	{
		if(direction == BOT)
		{
			fillposition.setX(tempposition.getX());
			fillposition.setY(tempposition.getY()-1);
			if(colorOutput(LEFT, tiles.at(counter)) == COLOR_RED)
                            filltile.setColor(COLOR_RED);
			filltile.setSide(Tile::TYPE_CURVE_2);
		}
		else if(direction == RIGHT)
		{
			fillposition.setX(tempposition.getX());
			fillposition.setY(tempposition.getY()-1);
			if(colorOutput(TOP, tiles.at(counter)) == COLOR_WHITE)
                            filltile.setColor(COLOR_RED);
			filltile.setSide(Tile::TYPE_CURVE_2);
		}
	}
            tiles.push_back(filltile);
            positions.push_back(fillposition);
}


void filltile(std::vector<Tile>& tiles, std::vector<Position>& positions)
{
   
int counter = 0;
Position tempposition(0,0);
Tile temptile(Tile::TYPE_CROSS,COLOR_WHITE);
while(counter < tiles.size())
{
	tempposition = positions.at(counter);
        temptile = tiles.at(counter);
	if(getCorner(counter, tempposition, positions) == 0)
		counter ++;
	else if(getCorner(counter, tempposition, positions) == 1)
	{

		if(checkempty(tempposition.getX()-1, tempposition.getY(), tiles, positions) &&
		  (colorOutput(BOT, tiles.at(counter)) == colorOutput(LEFT, temptile) ))
		{
			fillin(counter, LEFT , 1, tiles, positions, temptile, tempposition);
			counter++;
		}
		else if(checkempty(tempposition.getX(), tempposition.getY()+1, tiles, positions) &&
		 	   (colorOutput(RIGHT, tiles.at(counter)) == colorOutput(TOP, temptile) ))
		{
			fillin(counter, TOP , 1, tiles, positions, temptile, tempposition);
			counter ++;
		}
		else
			counter++;
	}
	else if(getCorner(counter, tempposition, positions) == 2)
	{
		
		if(checkempty(tempposition.getX()+1, tempposition.getY(), tiles, positions) &&
		  (colorOutput(BOT, tiles.at(counter)) == colorOutput(RIGHT, temptile) ))
		{
			fillin(counter, RIGHT , 2, tiles, positions, temptile, tempposition);
			counter++;
		}
		else if(checkempty(tempposition.getX(), tempposition.getY()+1, tiles, positions) &&
		 	   (colorOutput(LEFT, tiles.at(counter)) == colorOutput(TOP, temptile) ))
		{
			fillin(counter, TOP , 2, tiles, positions, temptile, tempposition);
			counter ++;
		}
		else
			counter++;
	}
	
	else if(getCorner(counter, tempposition, positions) == 3)
	{
		
		if(checkempty(tempposition.getX()-1, tempposition.getY(), tiles, positions) &&
		  (colorOutput(TOP, tiles.at(counter)) == colorOutput(LEFT, temptile) ))
		{
			fillin(counter, LEFT , 3, tiles, positions, temptile, tempposition);
			counter++;
		}
		else if(checkempty(tempposition.getX(), tempposition.getY()-1, tiles, positions) &&
		 	   (colorOutput(BOT, tiles.at(counter)) == colorOutput(RIGHT, temptile) ))
		{
			fillin(counter, BOT , 3, tiles, positions, temptile, tempposition);
			counter ++;
		}
		else
			counter++;

	}
	else if(getCorner(counter, tempposition, positions) == 4)
	{
		
		if(checkempty(tempposition.getX()+1, tempposition.getY(), tiles, positions) &&
		  (colorOutput(TOP, tiles.at(counter)) == colorOutput(RIGHT, temptile) ))
		{
			fillin(counter, RIGHT , 4, tiles, positions, temptile, tempposition);
			counter++;
		}
		else if(checkempty(tempposition.getX(), tempposition.getY()-1, tiles, positions) &&
		 	   (colorOutput(LEFT, tiles.at(counter)) == colorOutput(BOT, temptile) ))
		{
			fillin(counter, BOT , 4, tiles, positions, temptile, tempposition);
			counter ++;
		}
		else
			counter++;
	}
}
    
}




Addtile::Addtile(std::string name) : Command(name) {}
Addtile::~Addtile() {}

int Addtile::execute(Game& board, std::vector<std::string>& params) {}

int Addtile::execute(std::vector<std::string> param,
        std::vector<Tile>& tiles, std::vector<Position>& positions, 
        int aplayer, bool graphicon, std::string filename)
    {  
        Write write("write");
        
        CheckVictory checkvictory;
        Tile temptile(Tile::TYPE_CROSS,COLOR_WHITE);
        Position tempposition(0,0);
        
        tempposition.parse(param.at(0));
        
        if(param.at(1) == "+")
            temptile.setSide(Tile::TYPE_CROSS);
        if(param.at(1) == "/")
            temptile.setSide(Tile::TYPE_CURVE_1);
        if(param.at(1) == "\\")
            temptile.setSide(Tile::TYPE_CURVE_2); 
        else
        {
            // Errorhandling
        }
        
        if(checktile(temptile,tempposition, tiles, positions))
        {
            tiles.push_back(temptile);
            positions.push_back(tempposition);
            //filltile(tiles, positions);
            int counter;
            /*for(counter = 0; counter < positions.size(); counter ++)
            {
                std::cout<<counter << ":  x= "<< positions.at(counter).getX()<<":  y="<< positions.at(counter).getY()<<std::endl;
            }*/
            sort(tiles, positions);
             for(counter = 0; counter < positions.size(); counter ++)
            {
                std::cout<<counter << ":  x= "<< positions.at(counter).getX()<<":  y="<< positions.at(counter).getY()<<std::endl;
            }
            
            //if(graphicon == true)
                write.execute(tiles, positions, aplayer, "test"); //filename);
                //checkvictory.sieg(tiles, positions, temptile, tempposition, aplayer);
        }
        else
       
            
        
        
        
        return 0;
    }