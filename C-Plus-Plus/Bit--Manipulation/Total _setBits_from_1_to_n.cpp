/*
We are given a positive integer n, we have to 
calculate total number of set bits from 1 to n.
Approach: 
Let n=11;
We have
0    -   0000
1    -   0001
2    -   0010
3    -   0011
4    -   0100
5    -   0101
6    -   0110
7    -   0111
Here we have power(2,3)=8
and total set bits upto largest power 
of 2 upto n is:  x*pow(2,x-1);
where x is largest power of 2 upto n
Then,
8    -   1000       1   000-0
9    -   1001       1   001-1
10   -   1010       1   010-2
11   -   1011       1   011-3
Here we have 1 as left most bit in all numbers
so that is: n-pow(2,x)+1
So it become numbers from 0 to 3
We will recursively call function to calculate that
and add them to answer.
*/

#include <bits/stdc++.h>
using namespace std;

//Function to find largest power of 2 upto n
int largestPowerOf2inRange(int n)
{
    int x = 0;
    while ((1 << x) <= n)
    {
        x++;
    }
    return x - 1;
}

//Function to find total set bits from 1 to n
int TotalSetBits(int n)
{
    if (n <= 0)
        return 0;
    int x = largestPowerOf2inRange(n);
    int a = 1 << (x - 1); // a=pow(2,x-1)
    int b = 1 << x;       // b=pow(2,x)
    int bTill2x = x * a;
    int msb2xton = n - b + 1;
    int rest = n - b;
    int ans = bTill2x + msb2xton + TotalSetBits(rest);
    return ans;
}

int main()
{
    int n;
    cout << "Enter number:\n";
    cin >> n;
    cout << "Total number of set bits upto the given number is:\n";
    cout << TotalSetBits(n);
    return 0;
}

/*
Input:
Enter number:
11
Ouput:
Total number of set bits upto the given number is:
20
Time Complexity: O(logn)
*/