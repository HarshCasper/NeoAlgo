/* Max Rectangle = finding Max Area Rectangle in Binary Matrix

  ALGORITHM:
* First create a 2D matrix
* For finding max rectangle 1st find maximum area of histogram
  * maximum area of histogram(MAH):- 1. 1st find nearest smaller element to left(nsl) and nearest smaller element to right(nsr)
                                     2. for width = nsr-nsl-1
                                     3. for area = multiply each element of array with each element of width
                                     4. then find maximum area and return it
* find max_Rectangle =  for every row find MAH and updated the row every time with add the previous row,
                        if any element of the array is zero then dont add for this specific element and 
                        again find MAH for this updated row and everytime compare previous MAH and updated MAH 
                        which is maximum and stored it.
                          When completed the traverse then we will get the Max Area Rectangle in Binary Matrix.  
*/


#include <bits/stdc++.h>
using namespace std;

//finding Maximum Area of Histogram
int MAH(int a[], int n)
{
    int i, ans = 0;
    stack<int> s;
    vector<int> nsl(n), nsr(n);

    //finding nearest smaller to left
    for (i = 0; i < n; i++)
    {
        if (s.empty())
            nsl[i] = -1;
        else if (a[s.top()] < a[i])
            nsl[i] = s.top();
        else
        {
            while (!s.empty() && a[s.top()] >= a[i])
                s.pop();
            if (s.empty())
                nsl[i] = -1;
            else
                nsl[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    // finding nearest smaller element to right
    for (i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            nsr[i] = n;
        else if (a[s.top()] < a[i])
            nsr[i] = s.top();
        else
        {
            while (!s.empty() && a[s.top()] >= a[i])
                s.pop();
            if (s.empty())
                nsr[i] = n;
            else
                nsr[i] = s.top();
        }
        s.push(i);
    }
//ans stored maximum area
    for (i = 0; i < n; i++)
        ans = max(ans, a[i] * (nsr[i] - nsl[i] - 1));
    return ans;
}

//finding max area of rectangle
int max_Rectangle(vector<vector<int>> &v)
{

    int p, q, i, j;
    p = v.size();
    q = v[0].size();
    int temp[q] = {0}, ans = 0;

    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
            v[i][j] != 0 ? (temp[j] += v[i][j]) : (temp[j] = 0);

        ans = max(ans, MAH(temp, q));
    }
    return ans;
}

int main()
{
    int row, col;
    cout << "No of row : ";
    cin >> row;
    cout << "No of column : ";
    cin >> col;
    vector<vector<int>> vec;
    int i, j, temp, max_area;
    for (i = 0; i < row; i++)
    {
        vector<int> row;
        for (j = 0; j < col; j++)
        {
            cin >> temp;
            row.push_back(temp);
        }
        vec.push_back(row);
    }
    max_area = max_Rectangle(vec);
    cout <<"max area is : "<< max_area << endl;
}

/*
INPUT:
No of row : 4
No of column : 4
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0

OUTPUT:
max area is : 8

Time Complexity : O(row x col)
Space Complexity : O(col)

*/