/*
 Progarm to Toggle each bit of a number
 Given a number we want to toggle each bit of a number . We can easily
  toggle all bits of a number by doing XOR of each of its bit by 1.
  
  Ex:-6 (110)
     after toggling each bit (001)=1
 */
#include <bits/stdc++.h>
using namespace std;
int  toggle_each_bit(int n)
{
    int res=1;
    while(res<=n)
    {
        //Toggling each bit by xoring with current set bit.
          n = n ^ res;
         //Moving set bit towards next bit.
          res=res << 1;
  
    }
    
    return n;
}

int main()
{
    int n;
    
    cout<<"Enter the number you want to flipped all bits\n";
    cin>>n;
   
    cout<<"After Toggling each bit the number comes out to be = "<< toggle_each_bit(n)<<"\n";
    
    
    return 0;
}
/*
Complexity Analysis:

Time Complexity:-O(1)
Space Complexity:-O(1)

Input/Output:

Enter the number you want to flipped all bits
6
After Toggling each bit the number comes out to be = 1

*/
