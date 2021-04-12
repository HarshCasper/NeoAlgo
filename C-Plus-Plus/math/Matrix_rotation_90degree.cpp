/*
This is C++ code for: Rotate the given matrix by 90 degree to right 
For example:
          1 2 3                7 4 1
          4 5 6     ====>      8 5 2
          7 8 9                9 6 3
*/
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &ans)
{
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < ans[i].size(); j++)
        {
            swap(ans[i][j], ans[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(ans[i][j], ans[i][n - j - 1]);
        }
    }
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "Matrix Before Rotation:\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "]\n";
    }
    rotate(arr);
    cout << "Matrix After Rotation:\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "]\n";
    }
}
/*
Sample Input: 
{{1,2,3},{4,5,6},{7,8,9}}

Sample Output:
Matrix Before Rotation:
[1 2 3 ]
[4 5 6 ]
[7 8 9 ]
Matrix After Rotation:
[7 4 1 ]
[8 5 2 ]
[9 6 3 ]

*/
