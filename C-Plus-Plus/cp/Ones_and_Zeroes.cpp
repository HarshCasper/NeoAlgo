/*
In this problem an array of
binary strings S and two 
integers M and N are given.
Print the size of the largest
subset of S such that there 
are at most M 0's and N 1's
in the subset.
*/
#include <bits/stdc++.h>
using namespace std;

/*
This function will return 
the size of the largest 
subset having at most max-
Zero 0's and maxOne 1's.
*/

int largestSubsetSize(vector<string>& S, int maxZero, int maxOne)
{
    int size = S.size();
    int i, j, k;
    int DP[size + 1][maxZero + 1][maxOne + 1];
    for (i = 0; i <= size; i++) {
        for (j = 0; j <= maxZero; j++) {
            for (k = 0; k <= maxOne; k++) {
                DP[i][j][k] = 0;
            }
        }
    }

    int ans = 0;
    for (i = 1; i <= size; i++) {
        int O = count(S[i - 1].begin(), S[i - 1].end(), '1');
        int Z = S[i - 1].length() - O;
        for (j = 0; j <= maxZero; j++) {
            for (k = 0; k <= maxOne; k++) {
                DP[i][j][k] = DP[i - 1][j][k];
                if ((j >= Z) && (k >= O))
                    DP[i][j][k] = max(DP[i][j][k], DP[i - 1][j - Z][k - O] + 1);
                ans = max(ans, DP[i][j][k]);
            }
        }
    }

    return ans;
}

int main()
{
    vector<string> S;
    string temp;
    int size, i, maxOne, maxZero;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    for (i = 0; i < size; i++) {
        cin >> temp;
        S.push_back(temp);
    }

    cout << "Enter the value of at most 0's and 1's" << endl;
    cin >> maxOne >> maxZero;
    cout << largestSubsetSize(S, maxZero, maxOne) << endl;
    return 0;
}

/*
Sample Input/Output: 
Input:
Enter the size of the array
4
S=["10","0001","111001","1","0"]
Enter the value of at most 0's and 1's
3 5
Output: 
4

Time Complexity:O(S*N*M)
Space Complexity:O(S*N*M)
where S is the size of Array,
N is the no of '1' and M is
the no of '0'.
*/
