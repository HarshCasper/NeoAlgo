/*Problem Statement:
Given a wall of size 4XN, and tiles of sizes(1,4) and (4,1).
In how many ways can you build a wall */

#include<bits/stdc++.h>
using namespace std;

int buildWall(int n)
{
    if(n<=3)
    {
        return 1;
    }
    int ans1=buildWall(n-1);
    int ans2=buildWall(n-4);

    return ans1+ans2;
}

int main()
{
    int n;
    cout<<"Enter the size of the wall: "<<endl;
    cin>>n;
    cout<<"The number of ways are: "<<buildWall(n)<<endl;
    return 0;
}
/*
Example:
Input:-
Enter the size of the wall:
4

Output:-
The number of ways are: 2

Time Complexity: O(n)
Space Complexity: O(n)
*/

