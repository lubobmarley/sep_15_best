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





Addtile::Addtile(std::string name) : Command(name) {}
    Addtile::~Addtile() {}

    int Addtile::execute(Game& board, std::vector<std::string>& params)
    {        
        std::vector<Tile> tiles;
        std::vector<Position> positions;
        
        Tile temptile(Tile::TYPE_CROSS,COLOR_WHITE);
        Position temppositon(0,0);
        
        
        //temptile.setColor(Game::getActivePlayer());
        /*if(checktile(temptile,tempposition, Tiles, Positions)
        {
            addTile()
        }*/
        
       
        
        
        
        return 0;
    }