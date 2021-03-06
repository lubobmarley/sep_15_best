// ------------------------------------------------------------------------------
// Addtile.cpp
//
// Group: Group 10, study assistant: Philipp Hafner
//
// Authors: Markus Gallacher (1430391)
// Philipp Feldner (1216081)
// Lukas Bodner (1431293)
// ------------------------------------------------------------------------------
//

#include "Addtile.h"
#include "Game.h"
#include "Position.h"
#include "Tile.h"
#include "Write.h"
#include <iostream>
#include <string>
#include <vector>

enum Orientation
{
  TOP   = 1,
  BOT   = 2,
  RIGHT = 3,
  LEFT  = 4
};

// ------------------------------------------------------------------------------
int Addtile::getOrientation(int&                  counter,
                            Position              tempposition,
                            std::vector<Position> positions)
{
  for (counter;counter < positions.size();counter++)
  {
    if (( tempposition.getX() == positions.at(counter).getX()) &&
        ( tempposition.getY() + 1 == positions.at(counter).getY()))
    {
      return TOP;
    }
    if (( tempposition.getX() == positions.at(counter).getX()) &&
        ( tempposition.getY() - 1 == positions.at(counter).getY()))
    {
      return BOT;
    }
    if (( tempposition.getX() - 1 == positions.at(counter).getX()) &&
        ( tempposition.getY() == positions.at(counter).getY()))
    {
      return RIGHT;
    }
    if (( tempposition.getX() + 1 == positions.at(counter).getX()) &&
        ( tempposition.getY() == positions.at(counter).getY()))
    {
      return LEFT;
    }
  }
  return 0;
}


// ------------------------------------------------------------------------------

Color Addtile::colorOutput(int direction, Tile temptile)
{
  switch (direction)
  {
    case TOP:

      return temptile.getColor();

    case BOT:

      if (( temptile.getColor() == COLOR_RED &&
            temptile.getSide()  == Tile::TYPE_CROSS ) ||

          ( temptile.getColor() == COLOR_WHITE &&
          ( temptile.getSide()  == Tile::TYPE_CURVE_1 ||
            temptile.getSide()  == Tile::TYPE_CURVE_2 )))
      {
        return COLOR_RED;
      }
      else
      {
        return COLOR_WHITE;
      }

    case RIGHT:

      if (( temptile.getColor() == COLOR_WHITE &&
          ( temptile.getSide()  == Tile::TYPE_CROSS ||
            temptile.getSide()  == Tile::TYPE_CURVE_1 )) ||

          ( temptile.getColor() == COLOR_RED &&
          ( temptile.getSide()  == Tile::TYPE_CURVE_2 )))
      {
        return COLOR_RED;
      }
      else
      {
        return COLOR_WHITE;
      }

    case LEFT:

      if (( temptile.getColor() == COLOR_WHITE &&
          ( temptile.getSide()  == Tile::TYPE_CROSS ||
            temptile.getSide()  == Tile::TYPE_CURVE_2 )) ||

          ( temptile.getColor() == COLOR_RED &&
          ( temptile.getSide()  == Tile::TYPE_CURVE_1 )))
      {
        return COLOR_RED;
      }
      else
      {
        return COLOR_WHITE;
      }
  }
}

// ------------------------------------------------------------------------------

bool Addtile::checkempty(int x, int y, std::vector<Position> positions)
{
  int counter;

  for (counter = 0;counter < positions.size();counter++)
  {
    if (positions.at(counter).getX() == x && positions.at(counter).getY() == y)
    {
      return false;
    }
  }
  return true;
}


// ------------------------------------------------------------------------------

bool Addtile::checktile(Tile&                 temptile,
                        Position              tempposition,
                        std::vector<Tile>     tiles,
                        std::vector<Position> positions)
{
  temptile.setColor(COLOR_WHITE);   // default color
  if (tiles.size() == 0 && tempposition.getX() == 0 && tempposition.getY() == 0)
  {
    temptile.setColor(COLOR_RED);
    return true;
  }
  int counter = 0;
  if (!checkempty(tempposition.getX(), tempposition.getY(), positions))
  {
    std::cout << "Invalid coordinates - field not empty" << std::endl;
    return false;
  }
  int set_red    = 0;
  int set_white  = 0;
  int identifier = 0;

  for (counter = 0;counter < tiles.size();counter++)
  {
    int identifier = getOrientation(counter, tempposition, positions);

    switch (identifier)
    {
      case TOP:
        if (colorOutput(TOP, tiles.at(counter)) == colorOutput(BOT, temptile))
        {
          set_white++;
          break;
        }
        else
        {
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
          set_red++;
          break;
        }
      default:
      {
        if (counter == tiles.size() && set_red == 0 && set_white == 0)
        {
          std::cout << "Invalid coordinates - field not connected to tile" <<
          std::endl;
          return false;
        }
        else
        {
          break;
        }
      }
    }
  }

  if (set_red > 0 && set_white > 0)
  {
    std::cout << "Invalid move - connected line colors mismatch" << std::endl;
    return false;
  }
  else if (set_red > 0)
  {
    temptile.setColor(COLOR_RED);
  }
  else if (set_white > 0)
  {
    temptile.setColor(COLOR_WHITE);
  }

  return true;
}


// ------------------------------------------------------------------------------

std::vector<Position> Addtile::swapposition(std::vector<Position> positions,
                                            int i, int j)
{
  Position tempposition = positions.at(i);

  positions.at(i) = positions.at(j);
  positions.at(j) = tempposition;
  return positions;
}


std::vector<Tile> Addtile::swaptiles(std::vector<Tile> tiles, int i, int j)
{
  Tile temptile = tiles.at(i);

  tiles.at(i) = tiles.at(j);
  tiles.at(j) = temptile;
  return tiles;
}


// ------------------------------------------------------------------------------

bool Addtile::sort(std::vector<Tile>& tiles, std::vector<Position>& positions)
{
  int counter = positions.size() - 1;

  if (positions.size() == 0 || positions.size() == 1)
  {
    return true;
  }



  while (counter > 0)
  {
    if (positions.at(counter).getY() > positions.at(counter - 1).getY())
    {
      counter--;
    }
    else if (positions.at(counter).getY() < positions.at(counter - 1).getY())
    {
      tiles     = swaptiles(tiles, counter, counter - 1);
      positions = swapposition(positions, counter, counter - 1);
      counter--;
    }
    else if (positions.at(counter).getY() == positions.at(counter - 1).getY())
    {
      if (positions.at(counter).getX() < positions.at(counter - 1).getX())
      {
        tiles     = swaptiles(tiles, counter, counter - 1);
        positions = swapposition(positions, counter, counter - 1);
        counter--;
      }
      else
      {
        counter--;
      }
    }
  }

  return true;
}

// ------------------------------------------------------------------------------

int Addtile::getCorner(int& counter, Position tempposition,
                       std::vector<Position> positions)
{
  for (counter; counter < positions.size(); counter++)
  {
    if (( tempposition.getX() == positions.at(counter).getX() + 1 ) &&
        ( tempposition.getY() == positions.at(counter).getY() + 1 ))
    {
        return 1;
    }
    if (( tempposition.getX() == positions.at(counter).getX() - 1 ) &&
        ( tempposition.getY() == positions.at(counter).getY() + 1 ))
    {
        return 2;
    }
    if (( tempposition.getX() == positions.at(counter).getX() + 1 ) &&
        ( tempposition.getY() == positions.at(counter).getY() - 1 ))
    {
        return 3;
    }
    if (( tempposition.getX() == positions.at(counter).getX() - 1 ) &&
        ( tempposition.getY() == positions.at(counter).getY() - 1 ))
    {
        return 4;
    }
  }
  return 0;
}

// ------------------------------------------------------------------------------


void Addtile::fillin(int counter, int direction, int corner,
                     std::vector<Tile>& tiles,
                     std::vector<Position>& positions,
                     Tile& temptile, Position& tempposition)
{
  Tile     filltile(Tile::TYPE_CROSS, COLOR_WHITE);
  Position fillposition(0, 0);

  if (corner == 1)
  {
    if (direction == TOP)
    {
      fillposition.setX(tempposition.getX());
      fillposition.setY(tempposition.getY() - 1);                // ?
      if (colorOutput(RIGHT, tiles.at(counter)) == COLOR_WHITE)
      {
        filltile.setColor(COLOR_RED);
      }
      filltile.setSide(Tile::TYPE_CURVE_2);
    }
    else if (direction == LEFT)
    {
      fillposition.setX(tempposition.getX() - 1);
      fillposition.setY(tempposition.getY());
      if (colorOutput(BOT, tiles.at(counter)) == COLOR_RED)
      {
        filltile.setColor(COLOR_RED);
      }
      filltile.setSide(Tile::TYPE_CURVE_2);
    }
  }
  else if (corner == 2)
  {
    if (direction == TOP)
    {
      fillposition.setX(tempposition.getX());
      fillposition.setY(tempposition.getY() - 1);
      if (colorOutput(LEFT, tiles.at(counter)) == COLOR_WHITE)
      {
        filltile.setColor(COLOR_RED);
      }
      filltile.setSide(Tile::TYPE_CURVE_1);
    }
    if (direction == RIGHT)
    {
      fillposition.setX(tempposition.getX() + 1);
      fillposition.setY(tempposition.getY());
      if (colorOutput(BOT, tiles.at(counter)) == COLOR_RED)
      {
        filltile.setColor(COLOR_RED);
      }
      filltile.setSide(Tile::TYPE_CURVE_1);
    }
  }
  else if (corner == 3)
  {
    if (direction == BOT)
    {
      fillposition.setX(tempposition.getX());
      fillposition.setY(tempposition.getY() + 1);
      if (colorOutput(RIGHT, tiles.at(counter)) == COLOR_RED)
      {
        filltile.setColor(COLOR_RED);
      }
      filltile.setSide(Tile::TYPE_CURVE_1);
    }
    else if (direction == LEFT)
    {
      fillposition.setX(tempposition.getX() - 1);
      fillposition.setY(tempposition.getY());
      if (colorOutput(TOP, tiles.at(counter)) == COLOR_WHITE)
      {
        filltile.setColor(COLOR_RED);
      }
      filltile.setSide(Tile::TYPE_CURVE_1);
    }
  }
  else if (corner == 4)
  {
    if (direction == BOT)
    {
      fillposition.setX(tempposition.getX());
      fillposition.setY(tempposition.getY() + 1);
      if (colorOutput(LEFT, tiles.at(counter)) == COLOR_RED)
      {
        filltile.setColor(COLOR_RED);
      }
      filltile.setSide(Tile::TYPE_CURVE_2);
    }
    else if (direction == RIGHT)
    {
      fillposition.setX(tempposition.getX() + 1);
      fillposition.setY(tempposition.getY());
      if (colorOutput(TOP, tiles.at(counter)) == COLOR_WHITE)
      {
        filltile.setColor(COLOR_RED);
      }
      filltile.setSide(Tile::TYPE_CURVE_2);
    }
  }
  tiles.push_back(filltile);
  positions.push_back(fillposition);
}

// ------------------------------------------------------------------------------

bool Addtile::filltile(std::vector<Tile>&     tiles,
                       std::vector<Position>& positions)
{
  int      current = 0;
  int      counter = 0;
  int       corner = 0;
  Position tempposition(0, 0);
  Tile     temptile(Tile::TYPE_CROSS, COLOR_WHITE);
  int size = tiles.size();
  int maxcorner = 0;

  if (tiles.size() == 64)
  {
    return false;
  }

  while (current < size)
  {
    counter = 0;
    tempposition = positions.at(current);
    temptile     = tiles.at(current);
    for(maxcorner = 0; maxcorner < 4; maxcorner++)
    {
    corner = getCorner(counter, tempposition, positions);
        
    if (corner == 1)
    {
      if (checkempty(tempposition.getX() - 1, tempposition.getY(),
                     positions) &&
          ( colorOutput(BOT, tiles.at(counter)) == colorOutput(LEFT, temptile)))
      {
        fillin(counter, LEFT, 1, tiles, positions, temptile, tempposition);
        return true;
      }
      else if (checkempty(tempposition.getX(), tempposition.getY() - 1,
                          positions) &&
               ( colorOutput(RIGHT,
                             tiles.at(counter)) == colorOutput(TOP, temptile)))
      {
        fillin(counter, TOP, 1, tiles, positions, temptile, tempposition);
        return true;
      }
      else
          counter++;
    }
    if (corner == 2)
    {
      if (checkempty(tempposition.getX() + 1, tempposition.getY(),
                     positions) &&
          ( colorOutput(BOT, tiles.at(counter)) == colorOutput(RIGHT, temptile)))
      {
        fillin(counter, RIGHT, 2, tiles, positions, temptile, tempposition);
        return true;
      }
      else if (checkempty(tempposition.getX(), tempposition.getY() - 1,
                          positions) &&
               ( colorOutput(LEFT,
                             tiles.at(counter)) == colorOutput(TOP, temptile)))
      {
        fillin(counter, TOP, 2, tiles, positions, temptile, tempposition);
        return true;
      }
      else
          counter++;
    }
    if (corner == 3)
    {
      if (checkempty(tempposition.getX() - 1, tempposition.getY(),
                     positions) &&
          ( colorOutput(TOP, tiles.at(counter)) == colorOutput(LEFT, temptile)))
      {
        fillin(counter, LEFT, 3, tiles, positions, temptile, tempposition);
        return true;
      }
      else if (checkempty(tempposition.getX(), tempposition.getY() + 1,
                          positions) &&
               ( colorOutput(RIGHT,
                             tiles.at(counter)) == colorOutput(BOT, temptile)))
      {
        fillin(counter, BOT, 3, tiles, positions, temptile, tempposition);
        return true;
      }
      else
          counter++;
    }
    if (corner == 4)
    {
      if (checkempty(tempposition.getX() + 1, tempposition.getY(),
                     positions) &&
          ( colorOutput(TOP, tiles.at(counter)) == colorOutput(RIGHT, temptile)))
      {
        fillin(counter, RIGHT, 4, tiles, positions, temptile, tempposition);
        return true;
      }
      else if (checkempty(tempposition.getX(), tempposition.getY() + 1,
                          positions) &&
               ( colorOutput(LEFT,
                             tiles.at(counter)) == colorOutput(BOT, temptile)))
      {
        fillin(counter, BOT, 4, tiles, positions, temptile, tempposition);
        return true;
      }
      else
          counter++;
    }
    }
    current++;
  }
  return false;
}


void Addtile::getTileByPosition(int x, int y, std::vector<Tile>&  tiles, std::vector<Position>& positions, Tile& temptile)
{
int counter;

  for (counter = 0;counter < positions.size();counter++)
  {
    if (positions.at(counter).getX() == x && positions.at(counter).getY() == y)
    {
        temptile.setSide(tiles.at(counter).getSide());
        temptile.setColor(tiles.at(counter).getColor());
    }
  }
}

int Addtile::nextTile(std::vector<Tile>& tiles, std::vector<Position>& positions, Tile temptile, Position tempposition, int prevdirection, Color FOLLOW_COLOR)
{
	int direction;
	if(colorOutput(TOP, temptile) == FOLLOW_COLOR && prevdirection != BOT)
		direction = TOP;
	else if(colorOutput(RIGHT, temptile) == FOLLOW_COLOR && prevdirection != LEFT)
		direction = RIGHT;
	else if(colorOutput(BOT, temptile) == FOLLOW_COLOR && prevdirection != TOP)
		direction = BOT;
	else
		direction = LEFT;

	
	switch(direction)
	{
            case TOP:
			if(!checkempty(tempposition.getX(), tempposition.getY()-1, positions))
				return TOP;
			else
				return 0;

            case RIGHT:
			if(!checkempty(tempposition.getX()+1, tempposition.getY(), positions))
				return RIGHT;
			else
				return 0;

            case BOT:
			if(!checkempty(tempposition.getX(), tempposition.getY()+1, positions))
				return BOT;
			else
				return 0;
            case LEFT:
			if(!checkempty(tempposition.getX()-1, tempposition.getY(), positions))
				return LEFT;
			else
				return 0;

	}
}


int Addtile::followPath(std::vector<Tile>& tiles, std::vector<Position>& positions, Tile temptile, Position tempposition, bool& circle, Color FOLLOW_COLOR)
{
int horizontal_counter = 1;
int vertical_counter = 1;
int path_length_white = 0;
int prevdirection = 0;
Position startposition(tempposition.getX(), tempposition.getY());
int direction;

if(colorOutput(TOP, temptile) == FOLLOW_COLOR)
		direction = TOP;
	else if(colorOutput(RIGHT, temptile) == FOLLOW_COLOR)
		direction = RIGHT;
	else
		direction = BOT;

while(true)
{
	if(!direction)
		break;
	else if(direction == TOP)
	{
		tempposition.setY(tempposition.getY()-1);
                getTileByPosition(tempposition.getX(), tempposition.getY(), tiles, positions, temptile);
		if(startposition.getX() == tempposition.getX() && startposition.getY() == tempposition.getY())
			circle = true;
		vertical_counter++;
                std::cout << "TOP" << std::endl;
	}
		
	else if(direction == RIGHT)
	{
		tempposition.setX(tempposition.getX()+1);
                getTileByPosition(tempposition.getX(), tempposition.getY(), tiles, positions, temptile);
		if(startposition.getX() == tempposition.getX() && startposition.getY() == tempposition.getY())
			circle = true;
		horizontal_counter++;
                std::cout << "RIGHT" << std::endl;
	}
	
	else if(direction == BOT)
	{
		tempposition.setY(tempposition.getY()+1);
                getTileByPosition(tempposition.getX(), tempposition.getY(), tiles, positions, temptile);
		if(startposition.getX() == tempposition.getX() && startposition.getY() == tempposition.getY())
			circle = true;
		vertical_counter--;
                std::cout << "BOT" << std::endl;
	}
	
	else if(direction == LEFT)
	{
		tempposition.setX(tempposition.getX()-1);
                getTileByPosition(tempposition.getX(), tempposition.getY(), tiles, positions, temptile);
		if(startposition.getX() == tempposition.getX() && startposition.getY() == tempposition.getY())
			circle = true;
		horizontal_counter--;
                std::cout << "LEFT" << std::endl;
	}
	prevdirection = direction;
        direction = nextTile(tiles,positions, temptile, tempposition, prevdirection, FOLLOW_COLOR);
        
        if(circle)
            break;

}


if(horizontal_counter > vertical_counter)
	path_length_white =  horizontal_counter;
else if (horizontal_counter < vertical_counter)
	path_length_white = vertical_counter;
else
	path_length_white = horizontal_counter;

return path_length_white;
}

bool Addtile::checkVictory(std::vector<Tile>& tiles, std::vector<Position>& positions, int aplayer)
{
	int counter = 0;
	Tile temptile(Tile::TYPE_CROSS,COLOR_RED);
	std::string active_string;
        Position tempposition(0,0);
	int path_length_white = 0;
	int path_length_red = 0;
	bool circle_red = false;
	bool circle_white = false;
        
        if (aplayer == COLOR_WHITE)
            active_string = "white";
        else
            active_string = "red";

	for(counter; counter < tiles.size(); counter++)
	{
                temptile.setSide(tiles.at(counter).getSide());
                temptile.setColor(tiles.at(counter).getColor());
                tempposition.setX(positions.at(counter).getX());
                tempposition.setY(positions.at(counter).getY());

		path_length_red = followPath(tiles, positions, temptile, tempposition, circle_red, COLOR_RED);
		path_length_white = followPath(tiles, positions, temptile, tempposition, circle_white, COLOR_WHITE);

		std::cout << "r: " << path_length_red << std::endl;
    std::cout << "l: " << path_length_white << std::endl; 
                
		if((path_length_red >= 8 && path_length_white >= 8 ) || (circle_white && circle_red))
                {
			std::cout << "Player " << active_string << " wins!" << std::endl; 
                        return true;
                }
		else if(path_length_red >= 8 || circle_red)
                {
			std::cout << "Player red wins!" << std::endl; 
                        return true;
                }
		else if(path_length_white >= 8 || circle_white)
                {
			std::cout << "Player white wins!" << std::endl; 
                        return true;
                }
		else if(tiles.size() == 64)
                {
			std::cout << "No more tiles left. Game ends in a draw!" << std::endl; 
                        return true;
                }
	}	

	return false;
}


// ------------------------------------------------------------------------------

Addtile::Addtile(std::string name) : Command(name) {}
Addtile::~Addtile() {}

int Addtile::execute(Game& board, std::vector<std::string>& params) {}

int Addtile::execute(std::vector<std::string> param,
                     std::vector<Tile>& tiles, std::vector<Position>& positions,
                     int aplayer, bool graphicon, std::string filename)
{
  Write write("write");


  Tile         temptile(Tile::TYPE_CROSS, COLOR_WHITE);
  Position     tempposition(0, 0);
  std::cout<< tiles.size() << std::endl;
  if (!tempposition.parse(param.at(0)))
  {
    std::cout << "Invalid parameters" << std::endl;
    return 1;
  }
  if (param.at(1) == "+")
  {
    temptile.setSide(Tile::TYPE_CROSS);
  }
  else if (param.at(1) == "/")
  {
    temptile.setSide(Tile::TYPE_CURVE_1);
  }
  else if (param.at(1) == "\\")
  {
    temptile.setSide(Tile::TYPE_CURVE_2);
  }
  else
  {
    std::cout << "Invalid parameters" << std::endl;
    return 1;
  }
  
    if (tiles.size() == 0 && (tempposition.getX() != 0 || tempposition.getY() != 0))
  {
    std::cout << "Invalid coordinates - first tile must be set on (0,0)" <<
    std::endl;
    return 1;
  }

  if (checktile(temptile, tempposition, tiles, positions))
  {
    tiles.push_back(temptile);
    positions.push_back(tempposition);
    sort(tiles, positions);

    while (filltile(tiles, positions))
    {
      sort(tiles, positions);
    }
    sort(tiles, positions);

    if(graphicon == true)
        write.execute(tiles, positions, aplayer, filename);
    
    if(checkVictory(tiles, positions, aplayer))
        return 2; 
  }
  return 0;
}