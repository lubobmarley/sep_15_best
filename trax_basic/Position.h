//------------------------------------------------------------------------------
// Position.h
//
// Group: Group 10, study assistant: Philipp Hafner
//
// Author: Lukas Bodner, 1431293
//------------------------------------------------------------------------------
//

#ifndef POSITION_H
#define	POSITION_H

#include <string>


class Position
{
private:
    int x_;
    int y_;
    
   // Position(const Position &);
   // Position& operator= (const Position &);
    
public:
    Position(int x, int y) : x_(x), y_(y) {  }
    ~Position();
    
    bool parse (std::string input);
    std::string toString ();
    
    int getX () const { return x_; }
    int getY () const { return y_; }
    
};



#endif	/* POSITION_H */

