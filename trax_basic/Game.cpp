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
        cout << "sep> ";
        std::getline(cin, str);
        
        std::istringstream is(str);
        std::string part1, part2, part3;
        is >> part1 >> part2 >> part3;
        
        if (correctAddtile(part1))
          cout << "Addtile!" << endl;
        else if (correctWrite(part1, part2))
          cout << "Write!" << endl;
        else
          cout << "par1 wrong!" << endl;
               
        param.push_back(part2);
        param.push_back(part3);
        
        if (str == "quit" || str == "Quit" || str == "QUIT")
            running_ = false;
    }
}

void Game::togglePlayer()
{
    if (activeplayer_ == COLOR_WHITE)
        activeplayer_ = COLOR_RED;
    else
        activeplayer_ = COLOR_WHITE;
}

