/*Problem Statement: 
There's a scientist is interested in budding of cells. He has one container which initially contains only a single cell. 
Now he wants n number of cells in his container. 
So he can change the number of cells in container in 3 different ways -:

1.Double the number of cells present in the container.

2.Increase the number of cells in the container by 1.

3.Decrease the number of cells in the container by 1.

Now, all the above operations have different costs associated with them x,y,z respectively for above operations. 
Help him in finding the minimum cost to generate n cells in the container starting from one cell. */

#include <bits/stdc++.h>
using namespace std;

int costToGenerate(int n, int x, int y, int z)
{
    int dp[100];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
        }
        else
        {
            /*Here, an odd number cannot be reached by doubling an odd number,
            therefore, we increase it by 1  and then use case 1*/
            dp[i] = min(dp[i - 1] + y, dp[i + 1 / 2] + x + z);
        }
    }

    return dp[n];
}

int main()
{
    int x, n, y, z;
    cin >> n >> x >> y >> z;
    int dp[100];
    cout << costToGenerate(n, x, y, z) << endl;
    return 0;
}

/*Example: 
1)Input: 5 2 1 3
Output: 4
2)Input: 7 4 2 3
Output: 10
Time Complexity: O(n)
Space Complexity: O(n) */
