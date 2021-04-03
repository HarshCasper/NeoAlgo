/*
Introduction 
There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1, 2 or 3 stairs at a time.
Count the number of ways, the person can reach the top.

Argument/Return Type
The first line of input contains n, the number of stairs.
Output the number of ways.
*/

#include <bits/stdc++.h> 
using namespace std;

//Function to calculate total number of ways to reach nth stair.
int TotalWays(int n) 
{

    //Create an array of size n + 1 
    int ans[n + 1];
    
    //Initialize the first 3 variables with the base cases.
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;

   //Run a loop from 3 to n.
   
   for (int i = 3; i <= n; i++)
   {    // If a person is standing at i-th stair, the person can move to i+1, i+2, i+3-th stair. 
        //So, for each i, compute value of ith position as dp[i] = dp[i-1] + dp[i-2] + dp[i-3].
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
   }
   
   //Return the required answer which is the count of the number of ways to reach n th step. 
    return ans[n];
}


// Driver code
int main()
{
    
    int n;
    //Take input for no of stairs
    cout << "Enter total no.of stairs : ";
    cin >> n;


    //Call the function and print the result
    cout << "No of ways to reach nth stair is ";
    cout << TotalWays(n);

    return 0; 
}
    
/*
Input:
Sample Test Case 1  
Input Format : 
Example :
Enter total no.of stairs : 6
Output Format : 
Example : ( Output to the above input example ) 
No of ways to reach nth stair is  24
Time/Space Complexity
Time Complexity : O(n) 
Space Complexity : O(n) 
*/