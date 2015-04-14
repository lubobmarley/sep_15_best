#include "Position.h"
#include "Tile.h"
#include "Game.h"
#include "Addtile.h"
#include <iostream>
#include <string>
#include <vector>


enum Orientation
{
    TOP = 1,
    BOT = 2,
    RIGHT = 3,
    LEFT = 4          
};

bool checktile(Tile temptile, Position tempposition, std::vector<Tile> Tiles, 
               std::vector<Position> Positions)
{
    
    int identifier = 0;
    int counter = 0;
    
    for(counter; counter<Tiles.size(); counter++)
    {
        if((tempposition.getX()   == Positions[counter].getX()) && 
           (tempposition.getY()+1 == Positions[counter].getX()))
            { identifier = TOP;}
        if((tempposition.getX()   == Positions[counter].getX()) && 
           (tempposition.getY()-1 == Positions[counter].getX())) 
            {identifier = BOT;}
        if((tempposition.getX()+1 == Positions[counter].getX()) && 
           (tempposition.getY() == Positions[counter].getX()))
            {identifier = LEFT;}
        if((tempposition.getX()-1 == Positions[counter].getX()) && 
           (tempposition.getY()   == Positions[counter].getX()))
            {identifier = RIGHT;}
    }

    switch(identifier)
    {
        case TOP: 
        {
            if((((Tiles[counter].getSide()  == Tile::TYPE_CROSS   && 
                  Tiles[counter].getColor() == COLOR_WHITE) ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_1 && 
                  Tiles[counter].getColor() == COLOR_WHITE) ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_2 && 
                  Tiles[counter].getColor() == COLOR_WHITE))                  
                    && 
                ((temptile.getSide()       == Tile::TYPE_CURVE_1  &&
                  temptile.getColor()       == COLOR_RED)   ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_2 &&
                  temptile.getColor()       == COLOR_RED)   ||
                 (temptile.getSide()        == Tile::TYPE_CROSS   &&
                  temptile.getColor()       == COLOR_WHITE))) 
                    || 
               (((Tiles[counter].getSide()  == Tile::TYPE_CROSS   && 
                  Tiles[counter].getColor() == COLOR_RED)   ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_1 && 
                  Tiles[counter].getColor() == COLOR_RED)   ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_2 && 
                  Tiles[counter].getColor() == COLOR_RED) )       
                    &&
                ((temptile.getSide()        == Tile::TYPE_CURVE_1 &&
                  temptile.getColor()       == COLOR_WHITE)  ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_2 &&
                  temptile.getColor()       == COLOR_WHITE)  ||
                 (temptile.getSide()        == Tile::TYPE_CROSS   &&
                  temptile.getColor()       == COLOR_RED))))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        case BOT: 
        {
        
            if((((Tiles[counter].getSide()  == Tile::TYPE_CURVE_1 && 
                  Tiles[counter].getColor() == COLOR_RED)     ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_2 && 
                  Tiles[counter].getColor() == COLOR_RED)     ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CROSS   && 
                  Tiles[counter].getColor() == COLOR_WHITE))     
                    && 
                ((temptile.getSide()        == Tile::TYPE_CROSS   &&
                  temptile.getColor()       == COLOR_WHITE)    ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_1 &&
                  temptile.getColor()       == COLOR_WHITE)    ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_2 &&
                  temptile.getColor()       == COLOR_WHITE))) 
                    ||   
               (((Tiles[counter].getSide()  == Tile::TYPE_CURVE_1 &&
                  Tiles[counter].getColor() == COLOR_WHITE)    ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_2 && 
                  Tiles[counter].getColor() == COLOR_WHITE)    ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CROSS   && 
                  Tiles[counter].getColor() == COLOR_RED) )     
                    &&
                ((temptile.getSide()        == Tile::TYPE_CROSS   &&
                  temptile.getColor()       == COLOR_RED)      ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_1 &&
                  temptile.getColor()       == COLOR_RED)      ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_2 &&
                  temptile.getColor()       == COLOR_RED))))
            {
                return true;
            }
            else
            {
                return false;
            }
        
        }
        case RIGHT: 
        {
            if((((Tiles[counter].getSide()  == Tile::TYPE_CROSS   && 
                  Tiles[counter].getColor() == COLOR_WHITE) ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_1 && 
                  Tiles[counter].getColor() == COLOR_WHITE) ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_2 && 
                  Tiles[counter].getColor() == COLOR_RED))                  
                    && 
                ((temptile.getSide()       == Tile::TYPE_CURVE_1  &&
                  temptile.getColor()       == COLOR_RED)   ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_2 &&
                  temptile.getColor()       == COLOR_WHITE)   ||
                 (temptile.getSide()        == Tile::TYPE_CROSS   &&
                  temptile.getColor()       == COLOR_WHITE))) 
                    || 
               (((Tiles[counter].getSide()  == Tile::TYPE_CROSS   && 
                  Tiles[counter].getColor() == COLOR_RED)   ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_1 && 
                  Tiles[counter].getColor() == COLOR_RED)   ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_2 && 
                  Tiles[counter].getColor() == COLOR_WHITE) )       
                    &&
                ((temptile.getSide()        == Tile::TYPE_CURVE_1 &&
                  temptile.getColor()       == COLOR_WHITE)  ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_2 &&
                  temptile.getColor()       == COLOR_RED)  ||
                 (temptile.getSide()        == Tile::TYPE_CROSS   &&
                  temptile.getColor()       == COLOR_RED))))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case LEFT: 
              {
            if((((Tiles[counter].getSide()  == Tile::TYPE_CURVE_1 && 
                  Tiles[counter].getColor() == COLOR_RED) ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_2 && 
                  Tiles[counter].getColor() == COLOR_WHITE) ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CROSS   && 
                  Tiles[counter].getColor() == COLOR_WHITE))                  
                    && 
                ((temptile.getSide()       == Tile::TYPE_CROSS    &&
                  temptile.getColor()       == COLOR_WHITE)   ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_1 &&
                  temptile.getColor()       == COLOR_WHITE)   ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_2 &&
                  temptile.getColor()       == COLOR_RED))) 
                    ||
               (((Tiles[counter].getSide()  == Tile::TYPE_CURVE_1 && 
                  Tiles[counter].getColor() == COLOR_WHITE)   ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CURVE_2 && 
                  Tiles[counter].getColor() == COLOR_RED)   ||
                 (Tiles[counter].getSide()  == Tile::TYPE_CROSS   && 
                  Tiles[counter].getColor() == COLOR_RED) )       
                    &&
                ((temptile.getSide()        == Tile::TYPE_CROSS   &&
                  temptile.getColor()       == COLOR_RED)  ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_1 &&
                  temptile.getColor()       == COLOR_RED)  ||
                 (temptile.getSide()        == Tile::TYPE_CURVE_2 &&
                  temptile.getColor()       == COLOR_WHITE))))
            {
                return true;
            }
            else
            {
                return false;
            }
        default:
            return false;
       }
    }
}

//Vielleicht als Methoden implementieren?
std::vector<Position> swapposition(std::vector<Position> positions, int i, int j)
{    
    Position tempposition = positions.at(i);
    positions.at(i) = positions.at(j);
    positions.at(j) = tempposition;
    return positions;
}

std::vector<Tile> swaptiles(std::vector<Tile> tiles, int i, int j)
{    
    Tile temptile = tiles.at(i);
    tiles.at(i) = tiles.at(j);
    tiles.at(j) = temptile;
    return tiles;
}



void sort(std::vector<Tile> tiles, std::vector<Position> positions)
{
    int counter = 0;
    for(;;) 
    {
        if(positions.at(counter).getX() > positions.at(counter+1).getX())
        {
            swaptiles(tiles,counter,counter+1);
            swapposition(positions, counter, counter+1);
        }
        if(positions.at(counter).getX() < positions.at(counter-1).getX())
        {
            swaptiles(tiles,counter,counter-1);
            swapposition(positions, counter, counter-1);
    }
       
        
        
        
    }
     
    
}


void filltile(std::vector<Tile> tiles, std::vector<Position> positions)
{
    
    
    
}




Addtile::Addtile(std::string name) : Command(name) {}
Addtile::~Addtile() {}

int Addtile::execute(Game& board, std::vector<std::string>& params)
    {        
        std::vector<Tile> tiles;
        std::vector<Position> positions;
        
        Tile temptile(Tile::TYPE_CROSS,COLOR_WHITE);
        Position tempposition(0,0);
        
        tempposition.parse(params[0]);
        temptile.setColor(board.getActivePlayer());
        
        if(params.at(1) == "+")
            temptile.setSide(Tile::TYPE_CROSS);
        if(params.at(1) == "/")
            temptile.setSide(Tile::TYPE_CURVE_1);
        if(params.at(1) == "\\")
            temptile.setSide(Tile::TYPE_CURVE_2); 
        else
        {
            // Errorhandling
        }
        
        if(checktile(temptile,tempposition, tiles, positions))
        {
            tiles.push_back(temptile);
            positions.push_back(tempposition);
            //filltile()
            //sort()
            //if(graphicon == true)
            //  write.execute(tiles, positions);
        }
        
       
        swaptiles(tiles, 1, 4);
        
        
        return 0;
    }
