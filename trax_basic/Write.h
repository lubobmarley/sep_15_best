#ifndef WRITE_H
#define	WRITE_H

#include "Command.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class Tile;
class Position;

class Write : public Command
{    
    public:
    //--------------------------------------------------------------------------
    // Constructor
    // Constructs the Command and sets the commandname
    //  
    Write(std::string name) : Command(name) {};
    
    //--------------------------------------------------------------------------
    // Writes the current Gameboard into a binary file
    //
    // @param tiles vector including all set tiles 
    // @param positions vector including the fitting position
    // @param active the active player - red or white
    // @param filename name of the which will be created
    //
    // @return 0 (everthing okay) or 1 (cannot write file)
    //
    int execute(std::vector<Tile> tiles, std::vector<Position> positions,
                int active, std::string filename);
    int execute(Game& board, std::vector<std::string>& params);
};


#endif	/* WRITE_H */
