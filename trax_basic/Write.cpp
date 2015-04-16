/*#include "Command.h"
#include "Write.h"
#include "Tile.h"
#include "Position.h"*/

#include "Write.h"
class Command;
class Tile;
class Position;

using std::cout;
using std::cin;
using std::endl;

Write::Write(std::string name) : Command(name) {}
Write::~Write() {}


 int Write::execute(Game& board, std::vector<std::string>& params) {}
 
 int Write::execute(std::vector<Tile> tiles, std::vector<Position> positions, int aplayer) 
{
  char magic[4] = {'T', 'R', 'A', 'X'};
  char activep = aplayer;
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
  
  //int size = 0;
  //int row = 0;
  //int column = 0;
  int x = 0;
  int y = 0;
  int i = 0;
  
  //int side[3][3] = {{0,2,2},{2,1,2},{3,3,2}};
  //int color[3][3] = {{0,2,1},{1,1,2},{2,1,1}};
  
  minx = positions.at(0).getX();
  miny = positions.at(0).getY();
  maxx = positions.at(positions.size() - 1).getX();
  maxy = positions.at(positions.size() - 1).getY();
  
  //open file
  std::string filename = "first.trax"; // muss no geändert werden mit file param
  std::ofstream file(filename.c_str(), std::ios::out | std::ios::binary);
  
  //fehlerbehandlung \ tut3 folien
  
  //Binary Header
  file.write(magic, sizeof(magic));
  file << activep << minx << miny << maxx << maxy;
  
  //Binary Content
  for (y = miny; y <= maxy; y++)
      for (x = minx; x <= maxx; x++)
      {
          if (positions.at(i).getX() == x && positions.at(i).getY() == y)
          {
              switch(tiles.at(i).getSide())
              {
                  case 1: file << cross; break;
                  case 2: file << slash; break;
                  case 3: file << bslash; break;
                  default: cout << "wrong side!" << endl; //kann weggelassen werden
              }
              
              switch(tiles.at(i).getColor())
              {
                  case 1: file << white; break;
                  case 2: file << red; break;
                  default: cout << "wrong color!" << endl; //kann weggelassen werden
              }
              i++;
          }
          else
          {
              file << empty; // empty Side
              file << empty; // empty Color
          }
      }
  //file schließen
}
