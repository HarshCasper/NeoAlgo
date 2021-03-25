/*
Given an array A[] of N elements. In one operation, you can select any subarray of length 2 and multiply all 
elements of that subarray by -1. You can do any number of operations (possibly zero). Your task is to maximize 
the sum of all elements of all subarrays of A[].
*/

#include<bits/stdc++.h>
using namespace std;

    int maxSum(int n, vector<int> &arr)
    {
        int sum=0,neg_num=0,maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=abs(arr[i])*(n-i)*(i+1);
            if(arr[i]<0)
            neg_num++;
        }
        
        // if negative elements are even in number then sum will be equal to maximum sum of all element of all subarray of given array .
        if(neg_num %2==0)
        {
            return sum; 
        }
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,sum-2*(i+1)*(n-i)*abs(arr[i]));
        }
        return maxi;    //maximum sum of subarrays
    }

int main()
{
        int N;               // length of array
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)         // input array elements
        cin>>A[i];
        cout<<maxSum(N, A)<<endl;    // function call
    
    return 0;
}  

/*
Input:
         N = 3
         A[] = {-1, -2, -3}
         
 Output: 14

Time Complexity : O(N)
*/
