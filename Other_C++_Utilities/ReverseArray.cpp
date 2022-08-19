#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverseArray(int arr[], int n){
   for (int low = 0, high = n - 1; low < high; low++, high--)
   {
      swap(arr[low], arr[high]);
   }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int arr[15];
    cin >> n;
    
    //Read input to an array
    for(int i=0; i<n; i++)
    {
    cin>>arr[i];
    }
    
    //reverse array
    reverseArray(arr, n);
    
    //Write ouput to array
    for(int i=0; i<n; i++)
    {
    cout<<arr[i]<< " ";
    }
    
    return 0;
}