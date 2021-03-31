/* This algorithm will print the number which occurs odd number of times in a given array.
It is assumed that there is only one number which occurs odd number of times.
The concept used here is that taking XOR of same number even times gives zero while taking 
XOR of same number odd times gives the number itself. Also, XOR of any number with zero is the original number itself.*/

#include <bits/stdc++.h>
using namespace std;

//Function to find the number with odd occurrences
void odd_number(int arr[], int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    ans=ans^arr[i]; //calculating XOR with each of the array element
    cout<<ans;
    return;
}

//Driver Code
int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
 cin>>arr[i];
 odd_number(arr,n); //Function Calling
 return 0;
}

/* Time Complexity : O(n)
   Space Complexity: O(n)
   Sample Input    : 7
                     1 4 1 8 5 4 5
   Sample Output   : 8 */
