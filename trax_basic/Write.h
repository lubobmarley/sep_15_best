#ifndef WRITE_H
#define	WRITE_H

#include "Command.h"
#include "Tile.h"
#include "Position.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Write : public Command
{
    private:
    //--------------------------------------------------------------------------
    // Private copy constructor

    //Write(const Write& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    //Write& operator=(const Write& original);
    
    public:
        
    Write(std::string name);
    ~Write();
    
    int execute(std::vector<Tile> tiles, std::vector<Position> positions,
                int active, std::string filename);
    int execute(Game& board, std::vector<std::string>& params);
    
    
};


#endif	/* WRITE_H */

