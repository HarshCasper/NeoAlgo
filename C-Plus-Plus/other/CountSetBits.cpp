#include <bits/stdc++.h>
using namespace std;
 
int CountSetBits(unsigned int n)
{
    int count;
    while (n){
        count += n & 1;
        n >>= 1;
    }
    return count;
}
 
int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout <<"The number of set bits or 1s is: " << CountSetBits(n);
    return 0;
}

/*
Sample Input: Enter a number
              9
Sample Output: The number of set bits or 1s is: 2
Time Complexity: (-)(logn)(Theta of logn)
*/