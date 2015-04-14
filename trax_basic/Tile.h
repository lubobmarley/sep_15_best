//------------------------------------------------------------------------------
// Tile.h
//
// Group: Group 10, study assistant: Philipp Hafner
//
// Author: Lukas Bodner, 1431293
//------------------------------------------------------------------------------
//

#ifndef TILE_H
#define	TILE_H

#include "Color.h"

class Tile
{
public:
    enum Type
    {
        TYPE_CROSS = 1,
        TYPE_CURVE_1 = 2,
        TYPE_CURVE_2 = 3
    };    
    
    Tile(Type side, Color topcolor) : side_(side), topcolor_(topcolor) { }
    ~Tile();
    
    Color getColor () { return topcolor_;}
    Type getSide() {return side_;}
    
    void setColor(Color topcolor) {topcolor_ = topcolor;}
    void setSide(Type side) {side_ = side;}
    

 private:
    Type side_;
    Color topcolor_;
    
    //Tile(const Tile &);
    //Tile& operator= (const Tile &);
    
};

#endif	/* TILE_H */

