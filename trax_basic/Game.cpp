//------------------------------------------------------------------------------
// Game.cpp
//
// Group: Group 10, study assistant: Philipp Hafner
//
// Authors: Markus Gallacher (1430391)
// Philipp Feldner (1216081)
// Lukas Bodner (1431293)
//------------------------------------------------------------------------------
//
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

#include "Game.h"
#include "Position.h"
#include "Write.h"
#include "Addtile.h"

using std::cout;
using std::cin;
using std::endl;

//------------------------------------------------------------------------------
bool Game::correctAddtile (std::string part1)
{
  std::string key_word = "addtile";
  std::transform(part1.begin(), part1.end(), part1.begin(), ::tolower);
  
  if (key_word == part1)
    return true;
  else
    return false;
}

//------------------------------------------------------------------------------
bool Game::correctWrite (std::string part1)
{
  std::string key_word = "write";
  std::transform(part1.begin(), part1.end(), part1.begin(), ::tolower);
  
  if (key_word == part1)
    return true;
  else
    return false;
}

//------------------------------------------------------------------------------
bool Game::correctQuit (std::string str)
{
  std::string key_word = "quit";
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  
  if (key_word == str)
    return true;
  else
    return false;
}

//------------------------------------------------------------------------------
Game::~Game() {}

//------------------------------------------------------------------------------
void Game::run(bool graphic_on, std::string filename)
{
    running_ = true;
    int finished = 0;
    std::string str;
    std::vector<std::string> param;
    std::vector<Tile> tiles;
    std::vector<Position> positions;
    Addtile addtile("addtile");
    Write write ("write");
    
    while (running_ == true)
    {
        //waiting for input
        cout << "sep> ";
        std::getline(cin, str);
        
        //extract input
        std::istringstream is(str);
        std::string part1, part2, part3;
        is >> part1 >> part2 >> part3;
        
        param.push_back(part2);
        param.push_back(part3);
        
        //parse input
        if (correctAddtile(part1))
        {
            if (part2 != "" && part3 != "")
            {
            togglePlayer();
            finished = addtile.execute(param, tiles, positions, 
                    getActivePlayer(), graphic_on, filename);
            }
            else 
                cout << "Error: Wrong parameter count!" << endl;
        }
        else if (correctWrite(part1))
            if (tiles.size() == 0)
                cout << "Board is empty!" << endl;
            else if (part2 != "" && part3 == "")
                write.execute(tiles, positions, getActivePlayer(), part2);
            else
                cout << "Error: Wrong parameter count!" << endl;
        else if (correctQuit(str))
        {
          running_ = false;
          cout << "Bye!" << endl; // sep> Bye! ??
        }
        else if (str == "") {}
        else
          cout << "Error: Unknown command!" << endl;
               
        param.clear();
        
        if (finished == 2)
            running_ = false;
    }
}

//------------------------------------------------------------------------------
void Game::togglePlayer()
{
    if (activeplayer_ == COLOR_WHITE)
        activeplayer_ = COLOR_RED;
    else
        activeplayer_ = COLOR_WHITE;
}