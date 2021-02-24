/*
Brian Kenighan's Algorithm:
Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. 
for example : 
10 in binary is 00001010 
9 in binary is 00001001 
8 in binary is 00001000 
So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count. 
The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer. 
*/
#include <iostream>
using namespace std;

unsigned int countSetBits(int n)
{
        unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
}
int main()
{
    int i;
    cout << "Enter a number" << endl;
    cin >> i;
    cout <<"The number of set bits or 1s is : " << countSetBits(i);
    return 0;
}

/*
Sample Input: Enter a number
              9
Sample Output:The number of set bits or 1s is : 2
Time complexity: O(logn)
*/