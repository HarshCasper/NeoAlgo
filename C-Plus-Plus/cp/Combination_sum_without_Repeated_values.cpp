/*
The problem states that Given an array of integer and a target value. 
Return all the unique combination of array where chosen number sum to 
target. You may return combination in any order. (Note that each element
in returned array should occur one time only)
*/

#include <bits/stdc++.h>
using namespace std;

void find(vector<int> arr, vector<vector<int>> &ans, vector<int> &r, int sum, int start)
{
  if (sum < 0)
    return;
  else if (sum == 0)
  {
    ans.push_back(r);
    return;
  }
  for (int i = start; i < arr.size(); i++)
  {
    if (i > start && arr[i] == arr[i - 1])
      continue;
    if (sum - arr[i] < 0)
      break;
    r.push_back(arr[i]);
    find(arr, ans, r, sum - arr[i], i + 1);
    r.pop_back();
  }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
  vector<vector<int>> ans;
  vector<int> r;
  sort(arr.begin(), arr.end());
  find(arr, ans, r, target, 0);
  return ans;
}

int main()
{
  int n;
  cout<<"Enter Number of elements in the array:";
  cin >> n;
  cout<<"Enter elements of array:";
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  int target;
  cout<<"Enter target:";
  cin >> target;
  vector<vector<int>> answer = combinationSum2(arr, target);
  cout<<"\nCombination Sum without Repeated Values are:\n";
  for (int i = 0; i < answer.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < answer[i].size(); j++)
    {
      cout << answer[i][j] << ",";
    }
    cout << "]\n";
  }
}

/*
Test case 1:
Input:
Enter Number of elements in the array:7
Enter elements of array:10 1 2 7 6 1 5
Enter target:8

Output:

Combination Sum without Repeated Values are:
[1,1,6,]
[1,2,5,]
[1,7,]
[2,6,]

Time-Complexity : O(2^n)
Space-Complexity: O(n)

*/
