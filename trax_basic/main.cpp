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
  trax.run();
  //Command *c_ptr = new Write("Write");
  
  Write write("write");
    
  //test write function
  
  //text binary
  
  /*std::vector<Tile> tiles;
  std::vector<Position> positions;
  
  tiles.push_back(Tile(Tile::TYPE_CURVE_2, COLOR_WHITE));
  tiles.push_back(Tile(Tile::TYPE_CROSS, COLOR_RED));
  tiles.push_back(Tile(Tile::TYPE_CURVE_2, COLOR_RED));
  tiles.push_back(Tile(Tile::TYPE_CURVE_2, COLOR_WHITE));
  tiles.push_back(Tile(Tile::TYPE_CURVE_1, COLOR_RED));
  tiles.push_back(Tile(Tile::TYPE_CURVE_2, COLOR_RED));
  
  positions.push_back(Position(-1,0));
  positions.push_back(Position(0,0));
  positions.push_back(Position(0,1));
  positions.push_back(Position(1,1));
  positions.push_back(Position(1,2));
  positions.push_back(Position(2,2));
  trax.togglePlayer();
  write.execute(tiles, positions, trax.getActivePlayer());*/
  
  
  /*cout << "tile " << tiles.size() << endl;
  cout << "pos " << positions.size() << endl;
  
  cout << "C: " << tiles.at(2).getColor() << endl;
  cout << "S: " << tiles.at(2).getSide() << endl;
  cout << "PX: " << positions.at(2).getX() << endl;
  cout << "PY " << positions.at(2).getY() << endl;*/
  
  
    
  return 0;
}