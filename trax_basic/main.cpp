//------------------------------------------------------------------------------
// main.cpp
//
// Group: Group 43, study assistant: Max Mustertutor
//
// Authors: Markus Gallacher ()
// Philipp Feldner ()
// Lukas Bodner (1431293)
//------------------------------------------------------------------------------
//

#include <iostream>
#include <string>
#include "Game.h"
#include "Position.h"
#include "Color.h"
#include "Tile.h"
#include "Addtile.h"
#include "Write.h"

using std::cout;
using std::cin;
using std::endl;
 
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
  std::string graphicmode = "-g";
  std::string filename; 
  
  if (argc == 3)
    if (graphicmode == argv[1])
    {
      graphicon = true;
      filename = argv[2];
    }
  
  if (graphicon)
    cout << "hi" << endl;
    
  Game trax;
  Write schreiben("write");
  trax.run();
  
  
  return 0;
}