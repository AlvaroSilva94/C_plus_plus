#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Comparator function -  function that return true/false
bool f(int x, int y)
{
    return x > y;
}

int main()
{
    //Creating a vector
    vector<int> A = {11,2,3,14};
    
    //Access second element of vector
    cout << "Second element of the vector: \n" << A[1] << endl;

    //sorting the vector
    sort(A.begin(), A.end()); //sort in NlogN

    //result: 2,3,11,14
    //O(logN) to search if element exist in vector -> search if 3 is there
    bool isThere = binary_search(A.begin(), A.end(), 3); //return true

    //insert into the vector, 4 times same number
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    //vector: 2,3,11,14,100,100,100,100,123

    //Check if 100 is present there
    isThere = binary_search(A.begin(), A.end(), 100); //returns true

    //find the first occurrence (Note: iterators are pointers)
    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); //returns first element >= 100
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); //returns first element > 100
    //could also use auto it = <code> to not specify type

    //Print result of both iterators
    cout << "Result of it: \n" << *it << "\nResult of it2: \n" << *it2 << endl;
    cout << "Number of ocurrence of 100: " << it2-it << endl;

    //To sort vector in reverse order, pass overloaded comparator function as argument to sort function
    sort(A.begin(), A.end(),f);

    cout << "Vector in reverse order: " << endl;

    //iterate through values
    for (int x: A)
    {
        cout << x << " ";
    }
    cout << endl;

    //if you iterate by reference, you can increase all the values in the vector
    //iterate through values
    cout << "Vector in reverse order + 1: " << endl;
    for (int &x: A)
    {
        x++;
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

 
    /*

    Note: Iteration could also be done like this
    since we can use iterators to print vectors.
    
    vector<int>::iterator it3;

    for (it3 = A.begin(); it3 != A.end(); it3++)
    {
        cout << *it3 << " ";
    }
    cout << endl;

    Note: -  To insert elements in random order and do queries (ex: last number greater than x)
             is best to use a set instead of a vector

          - Operations like upper_bound only work when vector is completly sorted.

    */