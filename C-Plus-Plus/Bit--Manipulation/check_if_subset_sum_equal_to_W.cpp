/*
 given an array w of N<=1000 elements, check whether there's a subset of the array whose 
 sum is exactly equal to W, you have to use only bit manipulation.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    bitset<1000> can;
    int n, w;
    cout << "Enter the total number of elements in the array and the sum you want: \n";
    cin >> n >> w;
    can[0] = true;
    cout << "Enter the values of the array:\n";
    for (int id = 0; id < n; id++)
    {
        int x;
        cin >> x;
        can |= (can << x);
    }
    puts(can[w] ? "YES" : "NO");
}

/*
Sample Input:
Enter the total number of elements in the array and the sum you want: 
4 9
Enter the values of the array:
2 7 8 4
Sample Output: 
YES
*/
