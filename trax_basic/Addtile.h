

#ifndef ADDTILE_H
#define	ADDTILE_H

#include "Command.h"

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
    
};


#endif	/* ADDTILE_H */

