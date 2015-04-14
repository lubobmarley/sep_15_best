#include <iostream>
#include <string>
#include <sstream>

#include "Position.h"

using std::cout;
using std::cin;

Position::~Position() {}

bool Position::parse(std::string input)
{
  int x, y;
  int count_symbol = 0;
  int i = 0;
  char char1, char2, char3, char4;
  
  std::istringstream iss(input);
  
  iss >> char1 >> x >> char2 >> y >> char3 >> char4;
  
  int length = input.length();
  
  while(i < length)
  {
        if (input[i] == ' ' || input[i] == '+')
            count_symbol++;
            
        i++;
  }
  
  if (char1 == '(' && char2 == ',' && char3 == ')' && char4 != ')' 
      && count_symbol == 0)
  {
      x_ = x;
      y_ = y;
      return true;
  }
  else
      return false;
}

std::string Position::toString()
{    
    std::string position;
    std::stringstream buffer;
    
    buffer << "(" << x_ << "," << y_ <<")";
    
    position = buffer.str();
    
    return position;
}
