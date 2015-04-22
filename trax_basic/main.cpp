//------------------------------------------------------------------------------
// main.cpp
//
// Group: Group 10, study assistant: Philipp Hafner
//
// Authors: Markus Gallacher (1430391)
// Philipp Feldner (1216091)
// Lukas Bodner (1431293)
//------------------------------------------------------------------------------
//
#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "Position.h"
#include "Color.h"
#include "Tile.h"
#include "Command.h"
#include "Addtile.h"
#include "Write.h"

using std::cout;
using std::cin;
using std::endl;
 
//------------------------------------------------------------------------------
// checks if graphicmode is on or off
//
// @param argc argumentcounter
// @param argv argumentvalue
// @filename puts the filename if graphicmode is on
//
// @return true (graphicmode on) or false (graphicmode off)
//
bool checkGraphikMode(int argc, char** argv, std::string& filename)
{
    std::string graphic_mode = "-g";
      
    if (argc == 3)
        if (graphic_mode == argv[1])
        {
            filename = argv[2];
            return true;
        }
    return false;
}

//------------------------------------------------------------------------------
// main function
// entry point for execution
// @param argc argument count
// @param **argv argument values

// @return return value for the OS
//
int main(int argc, char **argv)
{
  bool graphic_on = false;
  std::string filename;
  std::string graphicmode = "-g";
  Game trax;
  
  if (argc == 1 || (argc == 3 && argv[1] == graphicmode))
  {
  graphic_on = checkGraphikMode(argc, argv, filename);
  trax.run(graphic_on, filename);
  }
  else
  {
      cout << "Usage: " << argv[0] << endl;
      return 2;
  }
  
  return 0;
}