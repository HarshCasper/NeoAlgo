/*
    To find the total amount of water collected, we
    firstly take an input of an array of size n of 
    heights of buildings. After that we will try 
    to find out minimum heights upto which water
    could be stored at that particulat index of building.
    This process has to be done from both left and the 
    right sides. 
    The complexity of the whole process will be O(t*n)
    where, t stands for total number of test cases and n 
    stands for total number of buildings in each test-case

*/
#include<bits/stdc++.h>
using namespace std;

// Function to return amount of water trapped in each test case
void solve()
{
    //taking input of number of buildings
    long long int n;
    cin>>n;
    // Making an array v containing heights of buildings
    long long int v[n];
    for(long long int i=0;i<n;i++)cin>>v[i];

    // Making a left and a right array. 
    long long int left_arr[n],right_arr[n];
    left_arr[0]=v[0];
    right_arr[n-1]=v[n-1];
    // Computing subsequent max elements from left sidewards.
    for(long long int i=1;i<n;i++)
    {
        left_arr[i]=max(v[i],left_arr[i-1]);
    }
    // Computing subsequent max elements from right sidewards.
    for(long long int i=n-2;i>=0;i--)
    {
        right_arr[i]=max(right_arr[i],v[i+1]);
    }
    long long int sum=0;

    // To find the amount of water getting collected inbetween the Buildings:
    // We find minimum between the right and the left array at same indices, 
    // Then Subtract the amount of space taken by the building at that particular index.

    for(long long int i=0;i<n;i++)
    {
        //Take sum of collected water at each index.
        sum+=min(left_arr[i],right_arr[i])-v[i];
        // cout<<sum<<"\n";
    }
    cout<<sum<<"\n";
}

// Driver Code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Taking input of number of test cases
    long long int t;
    cin>>t;
    while(t--)
    {    
        // Calling void function
        solve();
    }
    return 0;
}
/*
    Input:
    3
    3
    2 0 2
    5
    3 0 2 0 4
    12
    0 1 0 2 1 0 1 3 2 1 2 1
    ---------------
    Output:
    2
    7
    6
    ---------------
    Time-Complexity: O(n^2)
    Space-Compleixty: O(1) 

*/

