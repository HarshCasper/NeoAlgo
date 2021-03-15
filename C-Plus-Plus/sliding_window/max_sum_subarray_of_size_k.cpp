/*
Problem statement :
An array of integers of size 'n' and a number 'k' is given.
We have to detemine the maximum sum of subarray of size k
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    //declaring array size and subarray size
    int n,k;
    //taking array size from user
    cin>>n;
    int arr[n];//declaring the array
    //taking array element from user
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //subbarray size as input
    cin>>k;
    //sum stores the sum of k elements
    int sum=0;
    //declaring a variable which will store maximum sum
    //initializing it from INT_MIN
    int maxx=INT_MIN;
    //two pointers are needed to represent start and end of the window
    //let's denote i as the start and j as the end 
    //window size (k) =j-i+1
    int i=0,j=0;
    //pointer should be moved unless j reach the end index of arrray
    while(j<n)
    {   //out of this only that sum is to be used whose window size is k
        sum=sum+arr[j];
        //check whether sum is useful or not
        //if window size less than k increment j to increase the window size
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
       //printing maximum sum 
    cout<<maxx<<endl;

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

    Explaination:
    Window of size 3 is to be made starting from 1st element and then go on sliding it i.e shift it towards right  
    Let's say i and j both points to the 0th ndex of array 
    Now check whether j-i+1<k or not 
    If less than increase j
    If j-i+1==k ,we got the window size 
    Now,we need to maintain it.
    Store the max of sum and maxx which we get after after hitting window size
    i determines the start and j determines the end , therefore whenever we get k , we should start increasing both i and j pointers

    2 5 1 8 2 9 1
    |
    v
    i,j
    j=0 sum=2
    j=1 sum=7
    j=2 sum=8
    j-i+1=3 therefore
    max=8
    sum=8-2=6
    sum=6+6=14
    max(INT_MIN,14)=>14
    sum=9
    sum=11
    max(14,11)=>14
    sum=10
    sum=19
    max(19,14)=>19
    sum=11
    sum=12
    max(19,12)=>19
    **ans=19**

    Time complexity: O(n)
    Space complexity: O(1)
*/