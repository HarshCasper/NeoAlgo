/* Problem Statement =>
    Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to
   tile the given board using the 2 x 1 tiles.
    A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically
   i.e., as 2 x 1 tile. */

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

long long numberOfWays(long long length){
    int mod = 1000000007;
    vector<long long> dp(length + 1, 0);

    // Case 1: if n == 1 , only 1 configuration of tile is possible
    dp[1] = 1;

    // Case 2: if n == 2 , only 2 configurations are possible
    dp[2] = 2;
    
    /* Case 3: if n > 2, then we got 2 possible subcases:
        Subcase 1: if we place length wise, call dp[i-2];
        Subcase 2: if we place width wise, call dp[i-1];  */
    for (int i = 3; i <= length; i++){
        dp[i] = ((dp[i - 2] % mod) + (dp[i - 1] % mod)) % mod;
    }
    return dp[length];
}

int main(){
    long long length;
    cout << "Enter the length of the floor: " << endl;
    cin >> length;
    cout << "Number of ways to tile floor of length 2 x " << length << " are: " << numberOfWays(length) << endl;
}

/*  Sample Input:
        n=3
    Sample Output:
        3
    Expected Time Complexity:
        O(n)
    Expected Space Complexity:
        O(n)
*/
