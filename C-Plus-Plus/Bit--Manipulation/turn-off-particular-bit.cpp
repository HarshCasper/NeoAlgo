//To turn off the particular bit in a number
//Turn off the kth bit and output the number in decimal form
//Time Complexity: O(1)
//Space Complexity: O(1)

// IDEA
// The idea is to use bitwise <<, & and ~ operators. Using expression "~(1 << (k – 1))“, 
// we get a number which has all bits set, except the k’th bit. If we do bitwise & of this expression with n,
// we get a number which has all bits same as n except the k’th bit which is 0.

/*Sample Input:
Example 1:-
  Input:  n = 15, k = 2
  Output: 13
Example 2:-
  Input:  n = 15, k = 4
  Output: 7
*/
#include <iostream>
using namespace std;
  
int turnKthbitOff(int n, int k)
{
    if (k <= 0) return n;
  
    int bitToTurnOff= ~(1 << (k - 1));
  
    return (n & bitToTurnOff);
}
  
int main()
{
    //Taking input dynamically
    int n,k; 
    cin>>n>>k;

    cout << turnKthbitOff(n, k);
    return 0;
}
