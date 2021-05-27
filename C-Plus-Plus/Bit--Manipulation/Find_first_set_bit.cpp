#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    /*  function to find position of first set 
    bit in the given number
     * n: given input for which we want to get
          the position of first set bit
     */
    unsigned int getFirstSetBit(int n){
        return log2(n & -n) + 1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        printf("Input:");
        cin>>n; //input n
        Solution ob;
        printf("Output: %u\n", ob.getFirstSetBit(n));
    }
	return 0;
}

/*
Time Complexity: O(logn)
Space Complexity: O(1)
*/

/*
Example 1:- 
Input: 12
Output: 3

Example 2:- 
Input: 16
Output: 5
*/
