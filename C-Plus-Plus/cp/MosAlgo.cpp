#include <bits/stdc++.h>
using namespace std;

int b;

struct Problem
{
    int Left, Right;
};

void probRes(int a[], int n, Problem p[], int m)
{
    
    b = (int)sqrt(n);

    
    sort(p, p+m , check);

    int currLeft = 0, currRight = 0;
    int currSum = 0;

    
    for (int i=0; i<m; i++)
    {
        
        int Left = p[i].Left, Right = p[i].Right;
        while (currLeft < Left)
        {
            currSum -= a[currLeft];
            currLeft++;
        }
        while (currLeft > Left)
        {
            currSum += a[currLeft-1];
            currLeft--;
        }
        while (currRight <= Right)
        {
            currSum += a[currRight];
            currRight++;
        }

        while (currRight > Right+1)
        {
            currSum -= a[currRight-1];
            currRight--;
        }

        cout << "Sum of [" << Left << ", " << Right
            << "] is " << currSum << endl;
    }
}

bool check(Problem x, Problem y)
{
    
    if (x.Left/b != y.Left/b)
        return x.Left/b < y.Left/b;

    
    return x.Right < y.Right;
}

int main()
{
    int a[] = {1, 1, 2, 1, 3};
    int n = sizeof(a)/sizeof(a[0]);

    Problem p[] = {{1, 5}, {2, 4}};
    int m = sizeof(p)/sizeof(p[0]);
    
    probRes(a, n, p, m);
    return 0;
} 

// O(m * √n)

// O/P : Sum of [1, 5] is 6
// Sum of [2, 4] is 6



// Some other examples:
// I/P:
// Arr = [0, 1, 1, 0, 2, 3, 4, 1, 3, 5, 1, 5, 3, 5, 4, 0, 2, 2] of 18 elements
// Queries (0-indexed): [0, 8], [2, 5], [2, 11], [16, 17], [13, 14], [1, 17], [17, 17]


// O/P:
// 27
// 6
// 47
// 8
// 9
// 122
// 2
