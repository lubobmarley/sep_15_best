#include <iostream>
#include <string>

#include "Game.h"


using std::cout;
using std::cin;

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
    
    while (running_ == true)
    {
        cout << "sep> ";
        std::getline(cin, str);
        
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

