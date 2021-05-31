/*
Town planner Harry  is assigned to build new houses in the ninja town for its citizens. 
The town is in the form of a rectangular grid ‘TOWN[][]’ of (‘M’ * ‘N’) dimensions where 'M' 
is the number of rows and 'N' is the number of columns. Each cell of the grid can be an 'empty location' 
(that can be used for house) denoted by '.' or 'Tree' denoted by 'T'.
Following Are The Conditions Asked By Citizens For Their House Locations :
House should not have a house on its left cell
House should not have a house on its right cell
House should not have a house on its upper-left cell
House should not have a house on its upper-right cell
Return The Maximum Number Of Houses That Can Be Built While Meeting 
The Citizens' Demands And Not Cutting Any Of The Trees.
*/

#include<bits/stdc++.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int countSetBits(int mask)
{
    int count = 0;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        if (mask & (1 << i))
        {
            count++;
        }
    }
    return count;
}

// This bit is on.
bool on(int bit, int mask)
{
    return (1 << bit) & mask;
}

bool checkRowValid(vector<vector<char>> &town, int row, int mask, int n)
{
    for (int i = 0; i < n; i++)
    {
        // If a house is placed on a tree.
        if (on(i, mask) && town[row][i] == 'T'){
            return false;
        }
        // If there is a house on the left of this house.
        if (i > 0 && on(i - 1, mask) && on(i, mask)){
            return false;
        }
        // If there is a house on the right of this house.
        if (i < n - 1 && on(i + 1, mask) && on(i, mask)){
            return false;
        }
    }
    return true;
}

bool checkTwoRowCollision(int mask, int nmask, int n)
{
    for (int i = 0; i < n; i++)
    {
        // If there is a house on the upper left.
        if (i > 0 && on(i, nmask) && on(i - 1, mask)){
            return false;
        }
        // If there is a house on the upper right.
        if (i < n - 1 && on(i, nmask) && on(i + 1, mask)){
            return false;
        }
    }
    return true;
}

int planTown(int m, int n, vector<vector<char>> &town)
{
    // DP array to store previously calculated results.
    vector<vector<int>> dp(1 << 8, vector<int>(8,0));
    int ans = 0;

    // Initialization.
    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (checkRowValid(town, 0, mask, n))
        {
            dp[mask][0] = countSetBits(mask);
            ans = max(ans, dp[mask][0]);
        }
    }

    for (int row = 0; row < m - 1; row++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            // The current row of houses has to be valid.
            if (!checkRowValid(town, row, mask, n)){
                continue;
            }

            // Generate each next row and check correctness.
            for (int nmask = 0; nmask < (1 << n); nmask++)
            {
                // First it has to be valid.
                if (!checkRowValid(town, row + 1, nmask, n)){
                    continue;
                }
                // Then it has to not collide with former row.
                if (!checkTwoRowCollision(mask, nmask, n)){
                    continue;
                }

                dp[nmask][row + 1] = max(dp[nmask][row + 1], dp[mask][row] + countSetBits(nmask));
                ans = max(ans, dp[nmask][row + 1]);
            }
        }
    }

    return ans;
}

int main(){
    
    //int planTown(int m, int n, vector<vector<char>> &town)
    int m, n;
    cout<<"Enter the number of rows: "<<endl;
    cin>>m;
    cout<<"Enter the number of columns: "<<endl;
    cin>>n;
    cout<<"Enter the town grid having 'T' or '.'"<<endl;
    
    vector<vector<char>> town;
    char val;
    for(int i = 0; i < m; i++){
        vector<char> temp;
        for(int j = 0; j < n; j++){
            cin >> val;
            temp.push_back(val);
        }
        town.push_back(temp);
        temp.clear();
    }
    cout<<"The maximum number of houses that can be built are: "<<endl;
    cout<<planTown(m, n, town);
}

/*
    Enter the number of rows: 
    3
    Enter the number of columns: 
    5
    Enter the town grid having 'T' or '.'
    . . . T .
    . T . . .
    T . . T .
    
    Sample Output:
    The maximum number of houses that can be built are: 
    8

    Time Complexity : O(M * 2^N * 2^N * N)
    Space Complexity : O(M * 2^N)
    Where M is the number of rows and N is the number of columns of town
*/
