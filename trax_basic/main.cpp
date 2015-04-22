//------------------------------------------------------------------------------
// main.cpp
//
// Group: Group 43, study assistant: Max Mustertutor
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
 
bool checkGraphikMode(int argcounter, char** argvalues, std::string& filename)
{
    std::string graphicmode = "-g";
      
    if (argcounter == 3)
        if (graphicmode == argvalues[1])
        {
            filename = argvalues[2];
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
  bool graphicon = false;
  std::string filename;
  std::string graphicmode = "-g";
  Game trax;
  
  if (argc == 1 || (argc == 3 && argv[1] == graphicmode))
  {
  graphicon = checkGraphikMode(argc, argv, filename);
  trax.run(graphicon, filename);
  }
  else
  {
      cout << "Usage: " << argv[0] << endl;
      return 2;
  }
  
  
 
   
  return 0;
}