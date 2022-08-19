//Exercise to give me the interval that contains the value "check"
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    //Defining set of pair
    set<pair<int,int>> S;

    //Inserting values
    S.insert({2,3});
    S.insert({10, 20});
    S.insert({30, 400});
    S.insert({401, 450});

    //check value
    int check = 50;

    //defining upper bound
    //Note: for values > greater value defined, returns S.end()
    auto it = S.upper_bound({check, INT16_MAX});
    
    //trying to go one step back
    it --;

    //defining a pair to compare 
    pair<int,int>current = *it;

    if(current.first <= check && check <= current.second)
    {
        cout << "The pair is present: " << current.first << " " << current.second <<endl;
    }
    return 0;
}

/*
    Note: Pair {a,c} is smaller than pair {b,d} if:
                        - (a < b) or (a==b and c < d)

          
*/