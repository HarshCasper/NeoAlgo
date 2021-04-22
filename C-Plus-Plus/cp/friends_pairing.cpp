/*Problem Statement:
Given N,friends who want to go to a party on bikes.
Each guy can go as single, or as a couple.
Find the number of ways in which N friends can go to the party. */

#include<bits/stdc++.h>
using namespace std;

int friendsPairing(int n)
{
    if(n==0 or n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    int ans1=friendsPairing(1)*friendsPairing(n-1);
    int ans2=friendsPairing(2)*friendsPairing(n-2);

    return ans1+ans2;
}
int main()
{
    int n;
    cout<<"Enter total number of friends: "<<endl;
    cin>>n;
    cout<<"Total ways: "<<friendsPairing(n)<<endl;
    return 0;
}
/*Example:
Input: 
Enter total number of friends: 4
Output:
Total ways: 3
Time Complexity: O(nlogn)
Space Complexity: O(nlogn)
*/

