/*
    To find the total amount of water collected, we
    firstly take an input of an array of size n of 
    heights of buildings. After that we will try 
    to find out minimum heights upto which water
    could be stored at that particulat index of building.
    This process has to be done from both left and the 
    right sides. 
    The complexity of the whole process will be O(n)
    where, n stands for total number of buildings in each test-case.

*/
#include<bits/stdc++.h>
using namespace std;

// Function to return amount of water trapped
void solve()
{
    cout<<"Enter number of Buildings: ";
    long long int no_of_buildings;
    //taking input of number of buildings
    cin>>no_of_buildings;
    // Making an array containing heights of buildings
    long long int height[no_of_buildings];
    cout<<"Height of buildings: ";
    for(long long int i=0;i<no_of_buildings;i++){
        
        //Taking input of height of ith-building
        cin>>height[i];
    }

    // Making a left and a right array. 
    long long int left_arr[no_of_buildings],right_arr[no_of_buildings];
    left_arr[0]=height[0];
    right_arr[no_of_buildings-1]=height[no_of_buildings-1];
    // Computing subsequent max elements from left sidewards.
    for(long long int i=1;i<no_of_buildings;i++)
    {
        left_arr[i]=max(height[i],left_arr[i-1]);
    }
    // Computing subsequent max elements from right sidewards.
    for(long long int i=no_of_buildings-2;i>=0;i--)
    {
        right_arr[i]=max(right_arr[i+1],height[i]);
    }
    long long int total_water=0;

    // To find the amount of water getting collected inbetween the Buildings:
    // We find minimum between the right and the left array at same indices, 
    // Then Subtract the amount of space taken by the building at that particular index.

    for(long long int i=0;i<no_of_buildings;i++)
    {
        //Take sum of collected water at each index.
        total_water+=min(left_arr[i],right_arr[i])-height[i];
        // cout<<sum<<"\n";
    }
    cout<<"Total water trapped between buildings: ";
    cout<<total_water<<endl;
}
// Driver Code
int main()
{
    // Calling void function
    solve();
    return 0;
}
/*
    Input:
    Enter number of Buildings: 5
    Height of buildings: 3 0 2 0 4
    ---------------
    Output:
    Total water trapped between buidings: 7
    ---------------
    Time-Complexity: O(n)
    Space-Compleixty: O(1) 
*/
