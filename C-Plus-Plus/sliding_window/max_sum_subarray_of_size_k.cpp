/*
Problem statement :
An array of integers of size 'n' and a number 'k' is given.
We have to detemine the maximum sum of subarray of size k
*/

#include<bits/stdc++.h>
using namespace std;

//defining a function to calculate maximum_sum_subarray
int max_sum_subarray(int n,int arr,int k){
     //sum stores the sum of k elements
    int sum=0;
    //declaring a variable which will store maximum sum and initializing it from INT_MIN
    int maxx=INT_MIN;
    /*two pointers are needed to represent start and end of the window
      let's denote i as the start and j as the end then window size (k) =j-i+1*/
    int i=0,j=0;
    //pointer should be moved unless j reach the end index of arrray
    while(j<n)
    {   //out of this only that sum is to be used whose window size is k
        sum=sum+arr[j];
        /*check whether sum is useful or not
        if window size less than k increment j to increase the window size*/
        if(j-i+1<k)
            j++;
        //window size becomes same as k
        else if(j-i+1==k)
        {   //find maximum of sum and previous sum
            maxx=max(sum,maxx);
            //subtract previous arr[i] which id included after shifting window
            sum=sum-arr[i];
            //slide the  window
            i++;
            j++;
        }
       }
    //returning max
    return maxx;
}

int main(){
    //declaring array size and subarray size
    int n,k;
    //taking array size from user
    cin>>n;
    //declaring the array
    int arr[n];
    //taking array element from user
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //subbarray size as input
    cin>>k;
    //printing maximum sum by calling a function
    cout<<max_sum_subarray(n,arr,k);
}

/*
 => Input format:
    size of array (n)
    n elemnts of array
    k

 => Output format:
    maximum sum

 => Test case 1:
    Input:-
    7
    2 5 1 8 2 9 1
    3

    Output:
    19

    Time complexity: O(n)
    Space complexity: O(1)
*/
