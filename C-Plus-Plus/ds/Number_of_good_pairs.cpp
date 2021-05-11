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

int numGoodPairs(vector<int> &nums) 
{
    int n = nums.size();
    unordered_map<int ,int> u_map;
    for(int i = 0;i<n;i++)
    {
        u_map[nums[i]]++;
    }
    int ans = 0;
    for(auto i: u_map)
    {
        int y = i.second;
        ans = ans + (y*(y-1))/2;
    }
    return ans;
}
    
int main() 
{
    int n;
    cout<<"Enter the size of the array : ";
    cin >> n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array : ";
    for(int i = 0; i < n; i++)
    {   
        cin >> nums[i];
    }
    int number_of_good_pairs = numGoodPairs(nums);
    cout<<"Number of Good Pairs in the array : "<<number_of_good_pairs<<"\n";
    return 0;
}
/*
Standard Input and Output
Enter the size of the array : 6
Enter the elements of the array : 1 2 3 1 1 3
Number of Good Pairs in the array : 4

Time Complexity:O(n)
Space Complexity:O(n)
*/
