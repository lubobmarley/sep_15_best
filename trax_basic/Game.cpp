#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

#include "Game.h"
#include "Write.h"


using std::cout;
using std::cin;
using std::endl;

bool Game::correctAddtile (std::string part1)
{
  std::string key_word = "addtile";
  std::transform(part1.begin(), part1.end(), part1.begin(), ::tolower);
  
  if (key_word == part1)
    return true;
  else
    return false;
}

bool Game::correctWrite (std::string part1, std::string part2)
{
  std::string key_word = "write";
  std::transform(part1.begin(), part1.end(), part1.begin(), ::tolower);
  
  if (key_word == part1 && part2 != "")
    return true;
  else
    return false;
}

bool Game::correctQuit (std::string str)
{
  std::string key_word = "quit";
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  
  if (key_word == str)
    return true;
  else
    return false;
}

Game::Game()
{
    activeplayer_ = COLOR_WHITE;
    starttile_ = NULL;
}

Game::~Game() {}

void Game::run()
{
    running_ = true;
    std::string str;
    std::vector<std::string> param;
    
    while (running_ == true)
    {
        //waiting for input
        cout << "sep> ";
        std::getline(cin, str);
        
        //extract input
        std::istringstream is(str);
        std::string part1, part2, part3;
        is >> part1 >> part2 >> part3;
        
        //parse input
        if (correctAddtile(part1))
          cout << "Addtile!" << endl;
        else if (correctWrite(part1, part2))
          cout << "Write!" << endl;
        else if (correctQuit(str))
          running_ = false;
        else
          cout << "par1 wrong!" << endl;
               
        param.push_back(part2);
        param.push_back(part3);
        
    }
}

void Game::togglePlayer()
{
    if (activeplayer_ == COLOR_WHITE)
        activeplayer_ = COLOR_RED;
    else
        activeplayer_ = COLOR_WHITE;
}

