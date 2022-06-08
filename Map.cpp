#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    //Map something into something -> int into int
    map<int,int> A;

    //map values
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[1000] = 1;
    A[500] = 90;

    //map char into int
    map<char,int> cnt;

    string x = "alvaro silva";
    
    //count number of ocorrences of a in x
    for (char c : x)
    {
        cnt[c]++;
    } 

    cout << "Number of times a occurs withing the string: " << cnt['a'] << "";
    cout << endl;

    //use an iterator
    map<int,int>::iterator it;

    //Printing the entire map
    for (it = A.begin(); it != A.end();it++)
    {
        //When printing first and second it's printing map<first,second>
        cout << "Printing the map: " << (*it).first << " " << (*it).second << endl;
    }

    //define iterator
    map<int,int>::iterator l;

    //find value for key 3
    l = A.find(3);

    //Printing the elemenent found
    //find the element with key 3 -> 200
    if (l!=A.end())
    {
        cout << "Found value with key <3,?> : " << A.find(3)->second << " ";
        cout << endl;
    }

    //Erasing element with key 500
    A.erase(500);

    //Printing the entire map
    for (it = A.begin(); it != A.end();it++)
    {
        //When printing first and second it's printing map<first,second>
        cout << "Printing the map: " << (*it).first << " " << (*it).second << endl;
    }

    return 0;

    /*
    Note: Map is similar to set.
          You can also find/delete a key in map with A.find(key) and A.erase(key)

    */
}
