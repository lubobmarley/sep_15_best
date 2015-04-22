#ifndef ADDTILE_H
#define ADDTILE_H

#include "Command.h"
#include "Write.h"

class Addtile : public Command
{
  private:
    // --------------------------------------------------------------------------
    // Private copy constructor

    Addtile(const Addtile& original);

    // --------------------------------------------------------------------------
    // Private assignment operator

    Addtile& operator=(const Addtile& original);

    // --------------------------------------------------------------------------

    // ------------------------------------------------------------------------------
    // getOrientation()
    //
    // @param int& counter, steps through the elements of positions vector
    // @param tempposition, positions to compare with elements from the positions
    // vector
    // @param vector<Position> positions, positions of all tiles that are
    // currently placed on the board
    //
    // @return returns an enum of the facing direction
    //
    int getOrientation(int&                  counter,
                       Position              tempposition,
                       std::vector<Position> positions);

    // ------------------------------------------------------------------------------
    // colorOutput()
    //
    // @param int direction, the direction of which you want to know the
    // color output.
    // @param temtile, the tile you want to look at.
    // @return returns the color of the direction.
    //
    Color colorOutput(int direction, Tile temptile);

    // ------------------------------------------------------------------------------
    // checkempty()
    //
    // @param int x, x coordinate that gets checked
    // @param int y, y coordinate that gets checked
    // @param vector<Position> positions, positions of all tiles that are currently
    // on the board.
    //
    // @return returns true if the coordinates are unused
    //
    bool checkempty(int x, int y, std::vector<Position> positions);

    // ------------------------------------------------------------------------------
    // checktile()
    //
    // @param vector<Tile> tiles,  of all tiles from user input
    // @param vector<Position> positions, of all tiles from user input
    // @param temtile, Tile that is used to store userinput
    // @param tempposition, position of that temptile
    //
    // @return bool, returns if tile may be placed
    //
    bool checktile(Tile&                 temptile,
                   Position              tempposition,
                   std::vector<Tile>     tiles,
                   std::vector<Position> positions);

    // ------------------------------------------------------------------------------
    // swappositions()
    //
    // @param vector<Position> positions, of all tiles from user input
    // @param int i, index to be swapped with j
    // @param int j, index to be swapped with i
    //
    // @return vector<Position> the vector with swapped elements
    //
    std::vector<Position> swapposition(std::vector<Position> positions,
                                       int                   i,
                                       int                   j);

    // ------------------------------------------------------------------------------
    // swaptiles()
    //
    // @param vector<Tile> tiles, of all tiles from user input
    // @param int i, index to be swapped with j
    // @param int j, index to be swapped with i
    //
    // @return vector<Tile> the vector with swapped elements
    //
    std::vector<Tile> swaptiles(std::vector<Tile> tiles, int i, int j);

    // ------------------------------------------------------------------------------
    // sort()
    //
    // @param vector<Tile> tiles,  of all tiles currently on the board
    // @param vector<Position> positions, of all tiles currently on the board

    // @return bool returns true if sorted sucessfully
    //
    bool sort(std::vector<Tile>& tiles, std::vector<Position>& positions);

    // ------------------------------------------------------------------------------
    // getCorner()
    //
    // @param int& counter, steps through the elements of positions vector
    // @param tempposition, positions to compare with elements from the positions
    // vector
    // @param vector<Position> positions, positions of all tiles that are
    // currently placed on the board
    //
    // @return returns an int of the facing direction
    //
    int getCorner(int&                  counter,
                  Position              tempposition,
                  std::vector<Position> positions);

    // ------------------------------------------------------------------------------
    // fillin()
    //
    // @param int counter, the index of the matching element
    // @param int direction, the direction where the fill should take place
    // @param vector<Tile> tiles,  of all tiles currently on the board
    // @param vector<Position> positions, of all tiles currently on the board
    // @param temtile, Tile that is used to store the tile, that should be filled in
    // @param tempposition, position of that temptile
    //
    void fillin(int                    counter,
                int                    direction,
                int                    corner,
                std::vector<Tile>&     tiles,
                std::vector<Position>& positions,
                Tile&                  temptile,
                Position&              tempposition);

    // ------------------------------------------------------------------------------
    // filltile()
    //
    // @param vector<Tile> tiles,  of all tiles currently on the board
    // @param vector<Position> positions, of all tiles currently on the board
    //
    // @return returns true, if a tile was automatically filled in
    //
    bool filltile(std::vector<Tile>& tiles, std::vector<Position>& positions);

  public:
    Addtile(std::string name);
    ~Addtile();

    int execute(Game& board, std::vector<std::string>& params);
    int execute(std::vector<std::string> param,
                std::vector<Tile>& tiles, std::vector<Position>& positions,
                int aplayer, bool graphicon, std::string filename);
};


#endif /* ADDTILE_H */
