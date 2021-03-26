// Find median in a row wise sorted Matrix in C++.

// Formula for calculating the median.
   // median = (1 + r * c) / 2


//CODE :-
#include<bits/stdc++.h>
using namespace std;


// Function to find median in the matrix
int solve()
{
    int r,c;
    cin>>r>>c;

    int a[r][c];
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin>>a[i][j];
        }
    }


    int min = INT_MAX, max = INT_MIN;
    int desired_count = (1+(r*c)/2);
    for (int i=0; i<r; i++)
    {
        // Find the minimum element
        // and update the minimum element
        if (a[i][0] < min)
            min = a[i][0];

        // Find the maximum element
        // and update the maximum element
        if (a[i][c-1] > max)
            max = a[i][c-1];
    }

    int counter =0;
    while(min<max)
    {
        counter=0;
        //Find the middle element
        int mid = (max+min)/2;

        // Find count of element less then equal to mid
        // Using upper_bound function.
        for(int i= 0;i<r;i++)
        {
            counter += upper_bound(a[i], a[i]+c, mid) -  a[i];
        }
        if(counter < desired_count)
            min = mid+1;
        else
            max = mid;
    }
    // return the minumum index.
    return min;
}

int main()
{
    // Input the test cases.
    int t;
    cin>>t;
    while(t--)
    {
        int median = solve();
        cout<<"Median: "<<median<<endl;
    }
    return 0;
}

/*
Test cases :

    Input :

        2
        3 3
        1 3 4
        2 6 9
        3 6 9
        3 3
        1 3 4
        2 5 6
        7 8 9

    Output :

        Median: 4
        Median: 5



    Time complexity: O(r*log(c))
    Space Complexity: O(1)
*/
