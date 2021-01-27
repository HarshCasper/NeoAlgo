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
    int n,m;
    cin>>n;
    
    int[] a = new int(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cin>>m;
    int[] p = new int[];
    for(int i = Left , i<Right;i++){
        cin>>p[i];
    }
    
    probRes(a, n, p, m);
    return 0;
    
    
    
    int a[] = {1, 1, 2, 1, 3};
    int n = sizeof(a)/sizeof(a[0]);

    Problem p[] = {{1, 5}, {2, 4}};
    int m = sizeof(p)/sizeof(p[0]);
    
    probRes(a, n, p, m);
    return 0;
} 

// Time Complexity : O((m+m) * √n)
// Space Complexity : O(1)


// I/P
//   n = 5
//   m = 2
//   a = [1, 1, 2, 1, 3]
//   p =  [2,4]


// O/P : Sum of [2, 4] is 6


// I/P
//   n = 18
//   m = 2
//   a = [0, 1, 1, 0, 2, 3, 4, 1, 3, 5, 1, 5, 3, 5, 4, 0, 2, 2]
//   p = [0,8]


// O/P : Sum of [2,6] is 10


