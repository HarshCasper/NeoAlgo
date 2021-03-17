#include <bits/stdc++.h>
using namespace std;
 //finding missing number,given an array of n - 1 integers which are in the range //between 1 and n

int main()
{
    int a[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(a) / sizeof(a[0]);
    // For xor of all the elements in array
    int x1 = a[0];
 
    // For xor of all the elements from 1 to n+1
    int x2 = 1;
 
    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];
 
    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;
 
    
    cout <<"missing element is "<<(x1 ^ x2);
}