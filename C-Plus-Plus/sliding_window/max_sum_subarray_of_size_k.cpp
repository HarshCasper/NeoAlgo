/*
Problem statement :
An array of integers of size 'n' and a number 'k' is given.
We have to detemine the maximum sum of subarray of size k

=> Input format:
   size of array (n)
   n elemnts of array
   k

=> Output format:
   maximum sum
*/

#include<bits/stdc++.h>
using namespace std;

// Returns maximum sum in a subarray of size k
int max_sum_subarray(int n,int arr[],int k) {
    int sum=0;
    int maxx=INT_MIN;
    /*two pointers are needed to represent start and end of the window
      let's denote i as the start and j as the end then window size (k) =j-i+1*/
    int i=0,j=0;
    //pointer should be moved unless j reach the end index of arrray
    while(j<n)
    {   //Compute sum of each window
        sum=sum+arr[j];
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {   //compute maximum of sum and previous sum
            maxx=max(sum,maxx);
            /*Compute sums of remaining windows by
              removing first element of previous
              window */
            sum=sum-arr[i];
            //slide the  window
            i++;
            j++;
        }
    }
    return maxx;
}

int main() {
    //taking input from user
    int n,k;
    cin>>n;
    int arr[n];
    //taking array element from user
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cin>>k;
    cout<<max_sum_subarray(n,arr,k);
}

/*
Test case 1:
Input:-
7
2 5 1 8 2 9 1
3
Output:
19

Time complexity: O(n)
Space complexity: O(1)
*/
