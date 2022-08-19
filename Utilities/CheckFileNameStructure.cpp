#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
#include <set>
#include <regex>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

string ReadSystemCommand(char * cm)
{
  FILE *fp;
  char path[1035];
  
  /* Open the command for reading. */
  fp = popen(cm,"r");
  
  if (fp == NULL)
   {
    printf("Failed to run command\n" );
    exit(1);
   }

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) 
  {
    printf("%s", path);
  }

  /* close */
  pclose(fp);

  return path;
}

char* StringToCharArr(string s)
{
    int n = s.length();
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());
 
    return char_array;
}

void CheckFileNameStructure()
{
    cout <<  "For each created general log file verify that the name of the file has the following structure: ria.gen.YYYYMMDDHHmmssSSSZ.log" << endl;

    set<string> FileNames;
    //To hold separate names
    string strFirstFile;
    string strSecondFile;
    string strThirdFile;

    string strRes;
    string command;

    command = "find C:\path\for\files\to\check -name \"ria.gen.*.log\" -type f | rev | cut -d '/' -f1 | rev";

    //Store all gen files names in strRes string
    strRes.assign(ReadSystemCommand(StringToCharArr(command))); //NOTE: Missing part to run system command

    //Split res string into file names
    strFirstFile = strRes.substr(0,30);
    strSecondFile = strRes.substr(31,30);
    strThirdFile = strRes.substr(62,30);

    //Create a set to hold string names for comparison
    FileNames.insert(strFirstFile);
    FileNames.insert(strSecondFile);
    FileNames.insert(strThirdFile);

    //regex to match name
    regex rname("[r][i][a][.][g][e][n][.][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][Z][.][l][o][g]");

    //defining an iterator for the set
    set<string>::iterator it;

    //defining the regex match
    bool bMatch1;

    //find match in values within set
    for(it = FileNames.begin(); it != FileNames.end(); it++)
    {
        bMatch1 = regex_match(*it,rname);
        if (bMatch1 == true)
        {
            cout <<  "The name format is valid for the log file: " << *it << endl;
        }
        else
        {
            cout <<  "The name format is invalid for the log file: " << *it << endl;
        }
        
    }
    
    return;
}


int main() 
{
    CheckFileNameStructure();

    return 0;
}
