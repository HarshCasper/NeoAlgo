/*
Introduction 
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that 
adjacent houses have security systems connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Argument/Return Type
Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.
*/

#include <bits/stdc++.h> 
using namespace std;

//Function to find the maximum amount of money you can rob tonight without alerting the police
int MaxMoney(vector<int>&nums) 
{
    int n=nums.size();

    //If there are 0 houses , return 0
    if(n==0) 
        return 0;

    //If there is only one house , return its money
    if(n==1) 
        return nums[0];

    /* If there are atleast 2 houses ,create a dp vector and 
    calculate the maximum amount of money you can rob 
    without alerting the police till that particular house */
    vector<int>dp(n);
    dp[0]=nums[0];
    dp[1]=max(nums[1],dp[0]);
    for(int i=2;i<n;i++)    
    {
        /* At each i th house 
        either ( houses upto i-2 ) + ( i th house )
        or ( houses upto i-1 ) can be robbed */
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
    }

    //Return the required answer which is the maximum amount of money that can be robbed till last house
    return dp[n-1];
}


// Driver code
int main()
{
    //Take input for size of nums vector
    int n;
    cout<<"Enter total no.of houses : ";
    cin>>n;

    //create a vector to take input and store them
    vector<int>nums;

    cout<<"Enter money in each house, with spaces between them : ";

    for(int index=0;index<n;index++)
    {
        //Take the input of each value and push it into the vector
        int value;
        cin>>value;
        nums.push_back(value);
    }   

    //Call the function and print the result
    cout<<"Hence the maximum amount of money you can rob tonight without alerting the police is ";
    cout<<MaxMoney(nums);

    return 0; 
}
    
/*
Input:
1 <= nums.length <= 100
0 <= nums[i] <= 400

Sample Test Case 1  

Input Format : 
Example :
Enter total no.of houses : 5
Enter money in each house, with spaces between them : 2 7 9 3 1

Output Format :
Example : ( Output to the above input example ) 
Hence the maximum amount of money you can rob tonight without alerting the police is 12

Time/Space Complexity
Time Complexity : O(n) 
Space Complexity : O(n) 
*/
