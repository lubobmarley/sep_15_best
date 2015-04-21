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

Game game;

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
   
    std::string getPlayerColor();
    
    void setCounters();
    void sieg();
    void siegLoop(std::vector<Position> &coord, int counter, int increment);
    void checkSurrounding(std::vector<Tile> &tile, std::vector<Position> &coord);
    void tileTop(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment);
    void tileBottom(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment);
    void tileLeft(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment);
    void tileRight(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment);
    void unentschieden();
};
#endif

