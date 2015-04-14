#include "Addtile.h"
#include "Position.h"
#include "Tile.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>

    
bool checktile(Tile temptile, Position tempposition, std::vector<Tile> Tiles, 
               std::vector<Position> Positions)
{
    
    std::string identifier = "non";
    int counter = 0;
    
    for(counter; counter<Tiles.size(); counter++)
    {
        if((tempposition.getX()   == Positions[counter].getX()) && 
           (tempposition.getY()+1 == Positions[counter].getX()))
            { identifier = "top";}
        if((tempposition.getX()   == Positions[counter].getX()) && 
           (tempposition.getY()-1 == Positions[counter].getX())) 
            {identifier = "bot";}
        if((tempposition.getX()+1 == Positions[counter].getX()) && 
           (tempposition.getY() == Positions[counter].getX()))
            {identifier = "right";}
        if((tempposition.getX()-1 == Positions[counter].getX()) && 
           (tempposition.getY()   == Positions[counter].getX()))
            {identifier = "left";}
    }

    switch(identifier)
    {
        case "top": 
        {
            if(((Tiles[counter].getSide() == Tile::TYPE_CROSS   && 
                Tiles[counter].getColor() == COLOR_WHITE) ||
               (Tiles[counter].getSide()  == Tile::TYPE_CURVE_1 && 
                Tiles[counter].getColor() == COLOR_WHITE) ||
               (Tiles[counter].getSide()  == Tile::TYPE_CURVE_2 && 
                Tiles[counter].getColor() == COLOR_WHITE) )     
                    
                    &&
                    
                ((temptile.getSide()     == Tile::TYPE_CURVE_1 &&
                  temptile.getColor()     == COLOR_RED)  ||
                 (temptile.getSide()      == Tile::TYPE_CURVE_2 &&
                  temptile.getColor()     == COLOR_RED)  ||
                 (temptile.getSide()      == Tile::TYPE_CROSS &&
                  temptile.getColor()     == COLOR_WHITE))
        }
        
        case "bot": 
        {
        
        
        }
        case "right": 
        {
        
        
        }
        case "left": 
        {
        
        
        }
        default:
            return false;
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
        
        
        temptile.setColor(Game::getActivePlayer());
        /*if(checktile(temptile,tempposition, Tiles, Positions)
        {
            addTile()
        }*/
        
        
        
        
        
        
        return 0;
    }