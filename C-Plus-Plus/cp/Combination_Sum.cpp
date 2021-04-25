/* C++ Code for Combination Sum Problem.
Problem Statement:
Given an array of integers and a target value, the unique combination of values in array should sum up to the target value. 
The same number can be chosen multiple times.

For Example:
Input: array = [4,2,8,6], target = 8
Output: [2,2,2,2], [4,4], [2,6], [8], [2,2,4]

Constraints:
1. The array should have distinct elements.
2. 1 <= target <= 500
3. 1 <= arr.size() <= 50
4. 1 <= arr[i] <= 200
*/
#include<bits/stdc++.h>
using namespace std;

void combinationSum(vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &combn, int beg)
{
    if(!target) {
        ans.push_back(combn);
        return;
    } 
    for(int i=beg; i!=arr.size() && target >= arr[i]; ++i) {
        combn.push_back(arr[i]);
        combinationSum(arr, target-arr[i], ans, combn, i);
        combn.pop_back();
    }
}
int main() {
    int n; 
    cout << "\nEnter Array Size: "; cin >> n;

    vector<int> arr (n);
    cout << "\nEnter Array Elements: ";
    for(int i=0; i<n; ++i)
        cin >> arr[i];

    int target;
    cout << "\nEnter Target Sum: "; cin >> target;
    //Sorting the array
    sort(arr.begin(), arr.end());
    vector<vector<int> > ans;
    vector<int> combination;
    combinationSum(arr, target, ans, combination, 0);
    for(int i=0; i<ans.size(); ++i) {
        if(ans[i].size() > 0) {
            cout << "\n[";
            for(int j=0; j<ans[i].size(); ++j) 
                if(j == ans[i].size() - 1) cout << ans[i][j]; 
                else cout << ans[i][j] << ", ";
            cout << "]";
        }
    }
    return 0;
}
/* Sample Input
Enter Array Size: 4
Enter Array Elements: 1 2 3 4
Enter Target Sum: 10

Output:
[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
[1, 1, 1, 1, 1, 1, 1, 1, 2]
[1, 1, 1, 1, 1, 1, 1, 3]
[1, 1, 1, 1, 1, 1, 2, 2]
[1, 1, 1, 1, 1, 1, 4]
[1, 1, 1, 1, 1, 2, 3]
[1, 1, 1, 1, 2, 2, 2]
[1, 1, 1, 1, 2, 4]
[1, 1, 1, 1, 3, 3]
[1, 1, 1, 2, 2, 3]
[1, 1, 1, 3, 4]
[1, 1, 2, 2, 2, 2]
[1, 1, 2, 2, 4]
[1, 1, 2, 3, 3]
[1, 2, 2, 2, 3]
[1, 2, 3, 4]
[1, 3, 3, 3]
[2, 2, 2, 2, 2]
[2, 2, 2, 4]
[2, 2, 3, 3]
[2, 4, 4]
[3, 3, 4]
*/
