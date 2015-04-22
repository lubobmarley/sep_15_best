//------------------------------------------------------------------------------
// Write.cpp
//
// Group: Group 10, study assistant: Philipp Hafner
//
// Authors: Markus Gallacher (1430391)
// Philipp Feldner (1216081)
// Lukas Bodner (1431293)
//------------------------------------------------------------------------------
//
#include "Write.h"

using std::cout;
using std::cin;
using std::endl;

int Write::execute(Game& board, std::vector<std::string>& params) {}
 
//------------------------------------------------------------------------------
int Write::execute(std::vector<Tile> tiles, std::vector<Position> positions,
                   int active, std::string filename) 
{
  char magic[4] = {'T', 'R', 'A', 'X'};
  char activep = static_cast<char>(active);
  signed char minx = 0;
  signed char miny = 0;
  signed char maxx = 0;
  signed char maxy = 0;
  char cross = 1;
  char slash = 2;
  char bslash = 3;
  char white = 1;
  char red = 2;
  char empty = 0;
  int x = 0;
  int y = 0;
  int i = 0;
  int counter = 0;
    
  while(counter < positions.size())
  {
    if(maxx < positions.at(counter).getX())
      maxx = static_cast<char>(positions.at(counter).getX());
    
    if(minx > positions.at(counter).getX())
      minx = static_cast<char>(positions.at(counter).getX());
    
    counter++;
  }
  miny = static_cast<char>(positions.at(0).getY());
  maxy = static_cast<char>(positions.at(positions.size() - 1).getY());
  //open file
  std::ofstream file(filename.c_str(), std::ios::out | std::ios::binary);
  if (!file.is_open())
  {
      cout << "Cannot write file " << filename << endl;
      return 1;
  }
  //Binary Header
  file.write(magic, sizeof(magic));
  file << activep << minx << miny << maxx << maxy;
  //Binary Content
  for (y = miny; y <= maxy; y++)
      for (x = minx; x <= maxx; x++)
      {
          if (i < positions.size() && positions.at(i).getX() == x && 
                  positions.at(i).getY() == y) //vl ohne switchcase
          {
              switch(tiles.at(i).getSide())
              {
                  case 1: 
                      file << cross; 
                      break;
                  case 2: 
                      file << slash; 
                      break;
                  case 3: 
                      file << bslash; 
                      break;
              }
              
              switch(tiles.at(i).getColor())
              {
                  case 1: 
                      file << white; 
                      break;
                  case 2: 
                      file << red; 
                      break;
              }
              i++;
          }
          else
          {
              file << empty; // empty Side
              file << empty; // empty Color
          }
      }
  file.close();
  return 0;
}
