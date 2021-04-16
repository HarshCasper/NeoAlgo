/*
Given m rows and n column matrix, you have to return the spiral order of
the given matrix.
Example: m=3 n=3

        Matrix[m][n]:
        1 2 3
        4 5 6
        7 8 9
        
        Spiral order:
        ->1->2->3->6->9->8->7->4->5
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
        return {};
    vector<int> ans;
    int cl = 0, cr = matrix[0].size() - 1, ru = 0, rd = matrix.size() - 1;
    while (cl <= cr && ru <= rd)
    {
        for (int i = cl; i <= cr; i++)
        {
            ans.push_back(matrix[ru][i]);
        }
        ru++;
        if (ru > rd)
            break;
        for (int i = ru; i <= rd; i++)
        {
            ans.push_back(matrix[i][cr]);
        }
        cr--;
        if (cl > cr)
            break;
        for (int i = cr; i >= cl; i--)
        {
            ans.push_back(matrix[rd][i]);
        }
        rd--;
        for (int i = rd; i >= ru; i--)
        {
            ans.push_back(matrix[i][cl]);
        }
        cl++;
    }
    return ans;
}
int main()
{
    int m, n;
    cout << "Enter numbers of rows and column:";
    cin >> m >> n;
    vector<vector<int>> matrix;
    cout << "Enter " << m * n << " elements:";
    for (int i = 0; i < m; i++)
    {
        vector<int> r;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            r.push_back(a);
        }
        matrix.push_back(r);
    }
    cout << "Spiral order of the matrix is:\n";
    vector<int> ans = spiralOrder(matrix);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "->" << ans[i];
    }
    cout << "]";
}

/*

Sample Input:
Enter numbers of rows and column:3 3
Enter 9 elements:1 2 3 4 5 6 7 8 9 

Sample Output:
Spiral order of the matrix is:
[->1->2->3->6->9->8->7->4->5]

Time-Complexity:O(m*n)
Space-Complexity: O(m+n)

*/
