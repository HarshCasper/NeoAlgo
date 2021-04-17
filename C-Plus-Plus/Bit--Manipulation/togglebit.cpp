/*
 Program to Toggle kth bit of a number.
 Given a number we want to toggle the kth  bit of a number . 
  
  Ex:-6 (110) and k=2
     after toggling  2nd bit our number would be (100) 4.
 Approach:
  firstly we will left shift the given number k-1 times.
  After then we will xor the left shifted result with given number and return
 */
#include <bits/stdc++.h>
using namespace std;

int  toggle_k_bit(int n,int k)
{
   int temp=1<<(k-1);
   
   return n^temp;
}

int main()
{
    int n,k;
    
    cout<<"Enter the number of which you want to flip the kth bit\n";
    cin>>n;
    cout<<"Enter the position k at which you want to flip the  bit\n";
    cin>>k;

    cout<<"After Toggling the kth bit the number comes out to be = "<< toggle_k_bit(n,k)<<"\n";
    
    
    return 0;
}
/*
Complexity Analysis:

Time Complexity:-O(1)
Space Complexity:-O(1)

Input/Output:

Enter the number of which you want to flip the kth bit
7
Enter the position k at which you want to flip the bit
1
After Toggling the kth bit the number comes out to be = 6

*/

