#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
#include <set>
#include <regex>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <string>

using namespace std;

string HexToAscii(string strHex)
{
   const char lookup[32] =
  {0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0};

  string strOutputString;
  strOutputString.reserve(strHex.size()/2);

  const char* temp = strHex.c_str();

  unsigned char position, charLastPos = 1;
  while(*temp)
  {
    position <<= 4;
    position |= lookup[*temp&0x1f];
    if(charLastPos ^= 1) 
      strOutputString += position;
    temp++;
  }
  return strOutputString;
}

int main()
{
    HexToAscii("AB0C5342F");
    return 0;
}

