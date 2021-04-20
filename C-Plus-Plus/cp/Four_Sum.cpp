/*
Given n , array of size n (arr[n]) and target, your task is to print
all unique quadruplets [arr[a],arr[b],arr[c],arr[d]] ,such that:
arr[a]+arr[b]+arr[c]+arr[d]=target and a,b,c,d are distinct
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    vector<vector<int>> ans;
    if (nums.size() < 4)
        return ans;
    set<vector<int>> s;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int newt = target - nums[i] - nums[j];
            int l = j + 1, h = n - 1;
            while (l < h)
            {
                if (nums[l] + nums[h] == newt)
                {
                    s.insert({nums[i], nums[j], nums[l], nums[h]});
                    l++;
                    h--;
                }
                else if (nums[l] + nums[h] < newt)
                    l++;
                else
                    h--;
            }
        }
    }
    for (auto x : s)
    {
        ans.push_back(x);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter number of elements:";
    cin >> n;
    cout << "Enter elements:";
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int target;
    cout << "Enter target:";
    cin >> target;
    cout << "Unique quadruplets are:\n";
    vector<vector<int>> ans = fourSum(arr, target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
}

/*
Sample Input:
Enter number of elements:6
Enter elements:1 0 -1 0 -2 2
Enter target:0

Sample Output:
Unique quadruplets are:
[-2 -1 1 2 ]
[-2 0 0 2 ]
[-1 0 0 1 ]


Time-Complexity:O(n^3)
Space-Complexity: O(n)

*/
