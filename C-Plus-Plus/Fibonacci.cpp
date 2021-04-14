/*
This is program of fibonacci using iterative approach It 
requires less Computation that does from recursive approach
*/

#include <iostream>
using namespace std;

int fibc(int n)
{
    int x,y,z;
    if(n==0)
      y=0;
    else
      {
        x=0;
        y=1;
        for(int i=1;i<=n-1;i++)
        {
            z=x+y;
            x=y;
            y=z;
         }
       }
 return y; 
}

int main()
{
    int a;
    cin>>a;
    int b = fibc(a);
    cout<<b;
   
   return 0;
}

/*
Time Complexity: O(n)
Space Complexity : O(n)
*/

/*
Input :
2 
Output :
1 
*/