/* Algorithm to count the number of 1's in the binary representation of an integer */

/* Implementation using the Recursive Approach */

#include <bits/stdc++.h>
using namespace std;

int countbits(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
         return  1 + countbits(n & (n-1));
    }
    
}

int main()
{
    int n;
    cin>>n;
    cout<< countbits(n)<<endl;
    
    return 0;
}