#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    //Set is always ordered and maintains the insertion order of the numbers, last will be first
    //In a vector you can only insert at the end

    //define a new set 
    set<int> S;

    //inser elements into set
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    //iterate through set - result: -10, -1, 2, 1
    cout << "Set value: " << "";
    for (int x: S)
    {
        cout << x << " ";
    }
    cout << endl;

    //define iterator to find number
    set<int>::iterator it;
    it = S.find(-1); 
    
    //if element is not present it will return S.end()
    if (it == S.end())
    {
        cout << "Element not present!" << endl;
    }
    else
    {
        cout << "Element found! and value is: " << " "<< *it << endl;
    }

    //oposing to a vector, this can be done because the set is already sorted
    auto it2 = S.lower_bound(-1); //returns first element of the set that is >= -1, whis is -1
    auto it3 = S.upper_bound(0);  //return first element greater than 0, whis is 1 (works even if the number is not in the set)

    cout << *it2 << " " << *it3 << endl;

    //to find an upper bound that doesn't exist, the result is S.end() because it was unable to find it within the set
    auto it4 = S.upper_bound(2);
    
    if (it4 == S.end())
    {
        cout << "Element not present!" << endl;
    }

    //delete element from set
    S.erase(-1);
    
    for (int l : S)
    {
        cout << l << " ";
    }
    cout << endl;
    return 0;
}
