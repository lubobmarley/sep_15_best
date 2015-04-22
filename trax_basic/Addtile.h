

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
    
    //--------------------------------------------------------------------------
    int getOrientation(int& counter, Position tempposition, std::vector<Position> positions);
                        Color colorOutput(int direction, Tile temptile);
    bool checkempty(int x, int y, std::vector<Tile> tiles, std::vector<Position> positions);
    bool checktile(Tile& temptile, Position tempposition, std::vector<Tile> tiles, 
                   std::vector<Position> positions);
    std::vector<Position> swapposition(std::vector<Position> positions, int i, int j);
    std::vector<Tile> swaptiles(std::vector<Tile> tiles, int i, int j);
    bool sort(std::vector<Tile>& tiles, std::vector<Position>& positions);
    int getCorner(int& counter, Position tempposition, std::vector<Position> positions);
    void fillin(int counter, int direction, int corner, std::vector<Tile>& tiles, 
                std::vector<Position>& positions, Tile& temptile, Position& tempposition);
    bool filltile(std::vector<Tile>& tiles, std::vector<Position>& positions);
    
    public:
        
    Addtile(std::string name);
    ~Addtile();
    
    int execute(Game& board, std::vector<std::string>& params);
    int execute(std::vector<std::string> param,
        std::vector<Tile>& tiles, std::vector<Position>& positions, 
        int aplayer, bool graphicon, std::string filename);
};


#endif	/* ADDTILE_H */

