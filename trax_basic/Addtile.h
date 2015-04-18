

#ifndef ADDTILE_H
#define	ADDTILE_H

#include "Command.h"
#include "Write.h"

class Addtile : public Command
{
    private:
    //--------------------------------------------------------------------------
    // Private copy constructor

    Addtile(const Addtile& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    Addtile& operator=(const Addtile& original);
    
    public:
        
    Addtile(std::string name);
    ~Addtile();
    
    int execute(Game& board, std::vector<std::string>& params);
    int execute(std::vector<std::string> param,
        std::vector<Tile>& tiles, std::vector<Position>& positions, 
        int aplayer, bool graphicon, std::string filename);
};


#endif	/* ADDTILE_H */

