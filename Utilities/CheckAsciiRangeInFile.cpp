#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
#include <set>
#include <regex>
#include <algorithm>
#include <dirent.h>

using namespace std;

bool CheckAsciiRange()
{

    cout << "For each general log file verify that all bytes present in the file are within the ASCII range" << endl;

    //bool to check ascii range
    bool isAscii = true;
    //set to store fileNames    
    set<string> FileNames;
    //iterator for FileNames set
    set<string>::iterator it;

    for (it = FileNames.begin(); it!=FileNames.end(); it++)
    {

    //count caracters in ascii range
    int nCharsInAsciiRange;
    //Open each file in the set in binary
    ifstream inFile(*it,ios::binary);
    //define a portion for the buffer
    const streamsize gPortion = 512;
    streamsize strCount;
    char* buffer = new char[gPortion];
    
    while (!inFile.eof())
    {
        inFile.read(buffer,gPortion);
        // Get the last op byte counter:
        strCount = inFile.gcount();
        if (strCount <= 0)
            break;
         // process strCount bytes

        for (nCharsInAsciiRange = 0; nCharsInAsciiRange < strCount && isascii(buffer[nCharsInAsciiRange]); ++nCharsInAsciiRange)
            
            //simply increments nCharsInAsciiRange
            ;
        
        if (nCharsInAsciiRange < strCount)
        {
            isAscii = false;
            break;
        }
    }

    //release space occupied by buffer
    delete [] buffer;
    
    }
    return isAscii;
}

int main()
{
    bool bIsTrue = CheckAsciiRange();
    return 0;   
}