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
   
    std::string getPlayerColor(int active_player);
    
    void setCounters();
    bool sieg(std::vector<Tile> &tile, std::vector<Position> &coord, int active_player);
    bool siegLoop(std::vector<Position> &coord, int counter, int increment, int acrive_player);
    void checkSurrounding(std::vector<Tile> &tile, std::vector<Position> &coord, int active_player);
    bool tileTop(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment, int active_player);
    bool tileBottom(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment, int active_player);
    bool tileLeft(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment, int active_player);
    bool tileRight(std::vector<Tile> &tile, std::vector<Position> &coord, int counter, int increment, int active_player);
    bool unentschieden(std::vector<Tile> &tile);
};
#endif

