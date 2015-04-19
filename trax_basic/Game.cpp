#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Game.h"
#include "Write.h"


using std::cout;
using std::cin;
using std::endl;

bool correctPart1 (std::string part1)
{
  int i = 0;
  int n = 7;
  bool checkpart1 = true;
  
  while(i < n)
        {
          switch(i)
          {
            case 0: if(part1[i] != 'a' && part1[i] != 'A') checkpart1 = false;
                    break;
            case 1: if(part1[i] != 'd' && part1[i] != 'D') checkpart1 = false;
                    break;
            case 2: if(part1[i] != 'd' && part1[i] != 'D') checkpart1 = false;
                    break;
            case 3: if(part1[i] != 't' && part1[i] != 'T') checkpart1 = false;
                    break;
            case 4: if(part1[i] != 'i' && part1[i] != 'I') checkpart1 = false;
                    break;
            case 5: if(part1[i] != 'l' && part1[i] != 'L') checkpart1 = false;
                    break;
            case 6: if(part1[i] != 'e' && part1[i] != 'E') checkpart1 = false;
                    break;
          }
          i++;
        }
    return checkpart1;
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
        
        if (correctPart1(part1))
          cout << "par1 correct!" << endl;
        else
          cout << "par1 wrong!" << endl;
        
        //Write schreiben("Write");

        
        param.push_back(part2);
        param.push_back(part3);
        //schreiben.execute();
        if (str == "quit" || str == "Quit" || str == "QUIT")
            quit();
    }
}

void Game::togglePlayer()
{
    if (activeplayer_ == COLOR_WHITE)
        activeplayer_ = COLOR_RED;
    else
        activeplayer_ = COLOR_WHITE;
}

int Game::quit()
{
    std::cout << "Bye!" << std::endl;
    running_ = false;
    return 0;
}