/*
 Introduction:
 Given an array of integers nums. A pair (i,j) is called good if nums[i] == nums[j] and i < j.
 Return the number of good pairs.
 Approach:
 Use a Hash Table to calculate the frequency of each element in the given array.
 count the number of pairs using the formula y(y-1)/2; where y is the frequency for the element.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    unordered_map<int ,int> u_map;
    for(int i = 0; i < n; i++)
    {
        u_map[nums[i]]++;
    }
    int ans = 0;
    for(auto i:u_map)
    {
        int y = i.second;
        ans = ans+(y*(y-1)/2);
    }
    cout << ans << "\n";
}
/*
Input:
6
1 2 3 1 1 3
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Time Complexity:O(n)
Space Complexity:O(n)
*/
