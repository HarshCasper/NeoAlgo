/*
Description :
            Given a fence with n posts and k colors , find out the number of ways of painting the fence
            such that atmost 2 adjacent posts have the same color.
            Suppose we have a single post, The number of ways of painting the fence with k colors is k
            Now we consider 2 posts, Then the number of ways of painting the second fence with the same
            color as the first post is k, and the number of ways of painting the second post with a different
            color is k*(k-1) as we have k-1 colors that are different from the first post's color.
            So the total number of ways of painting 2 fences is k*(k-1) + k. Now we consider 3 posts,
            Then the number of ways of painting the third fence same as the second fence is the number of
            ways of painting the second fence with a different color that is k*(k-1). The number of ways of
            painting the third fence using a different color is equal to the total number of ways of
            painting the second fence * (k-1). Hence the total number of ways of painting 3 fences is 
            k*(k-1) + (k+k*(k-1))*(k-1).This way we can find the total number of ways of painting n fences
*/

// C++ Code :

#include <bits/stdc++.h>
using namespace std;

unsigned long long MOD = 1000000007;

// function uses permutations to find the number of ways of painting fences

unsigned long long Countways(int n, int k)
{

    unsigned long long tot, diff, simi;
    simi = k;
    diff = k * (k - 1);
    tot = k * k;
 
    for (int i = 1; i < n - 1; i++)
    {
        simi = diff;
        diff = tot * (k - 1);
        tot = simi + diff;
    }

    return tot % MOD;
}

int main()
{
    int n, k;
    cout << "Enter the number of posts" << endl;
    cin >> n;
    cout<<n<<endl;
    cout << "Enter the number of colors" << endl;
    cin >> k;
    cout<<k<<endl;
    cout << "Number of Possiblities: " << Countways(n, k) << endl;
    return 0;
}

/*
Testcase I/O  1:
Enter the number of posts
3
Enter the number of Colors
5

Number of Possiblities: 120

Testcase I/O  2:
Enter the number of posts
2
Enter the number of Colors
4

Number of Possiblities: 16

Testcase I/O  3:
Enter the number of posts
3
Enter the number of Colors
2

Number of Possiblities: 6


Time complexity - O(n)   [ n = Number of posts ]
Space complexity - O(n)

*/

