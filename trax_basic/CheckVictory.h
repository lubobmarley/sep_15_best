/* 
 * File:   CheckVictory.h
 * Author: markus
 *
 * Created on 18. April 2015, 17:19
 */

#ifndef CHECKVICTORY_H
#define	CHECKVICTORY_H

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Color.h"
#include "Tile.h"
#include "Addtile.h"
#include "Position.h"
#include "Game.h"

class CheckVictory
{
private:
    int red_counter_row_;
    int red_counter_column_;
    int white_counter_row_;
    int white_counter_column_;

public:
    CheckVictory();
    ~CheckVictory();
   
    std::string getPlayerColor(Game game);
    
    void setCounters();
    
    int siegLoop(std::vector<Position> &coord, int counter, int increment, Game game);
    void sieg(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, Game game);
    int tileTop(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, int counter, int increment, Game game);
    int tileBottom(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, int counter, int increment, Game game);
    int tileLeft(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, int counter, int increment, Game game);
    int tileRight(std::vector<Tile> &tile, std::vector<Position> &coord, Position position, int counter, int increment, Game game);
    int unentschieden(Game game);
};
#endif

