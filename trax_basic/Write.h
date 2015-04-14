#ifndef WRITE_H
#define	WRITE_H

#include "Command.h"

class Write : public Command
{
    private:
    //--------------------------------------------------------------------------
    // Private copy constructor

    Write(const Write& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    Write& operator=(const Write& original);
    
    public:
        
    Write(std::string name);
    ~Write();
    
    int execute(Game& board, std::vector<std::string>& params);
    
};


#endif	/* WRITE_H */

