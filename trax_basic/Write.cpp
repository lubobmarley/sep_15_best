#include "Write.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

Write::Write(std::string name) : Command(name) {}
Write::~Write() {}

int Write::execute(Game& board, std::vector<std::string>& params) 
{
  char magic[4] = {'T', 'R', 'A', 'X'};
  char active = 2;
  signed char minx = -1;
  signed char miny = -1;
  signed char maxx = 1;
  signed char maxy = 1;
  char cross = 1;
  char slash = 2;
  char bslash = 3;
  char white = 1;
  char red = 2;
  char empty = 0;
  
  int size = 3;
  int row = 0;
  int column = 0;
  
  int side[3][3] = {{0,2,2},{2,1,2},{3,3,2}};
  int color[3][3] = {{0,2,1},{1,1,2},{2,1,1}};
  
  std::string filename = "test.trax";
  std::ofstream file(filename.c_str(), std::ios::out | std::ios::binary);
  
  cout << "Pos. beginn :" << file.tellp() << endl;
  file.write(magic, sizeof(magic));
  cout << "Pos. nach magic :" << file.tellp() << endl;
  file << active << minx << miny << maxx << maxy;
  cout << "Pos. nach header :" << file.tellp() << endl;
  cout << "Pos. ende :" << file.tellp() << endl;
  
   for (row = 0; row < size; row++)
    for (column = 0; column < size; column++)
    {
      switch(side[row][column])
      {
        case 0: file << empty; break;
        case 1: file << cross; break;
        case 2: file << slash; break;
        case 3: file << bslash; break;
        default: cout << "Wrong side!" << endl;
      }
      
      switch(color[row][column])
      {
        case 0: file << empty; break;
        case 1: file << white; break;
        case 2: file << red; break;
        default: cout << "Wrong color!" << endl;
      }
    }
}
