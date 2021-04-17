#include<bits/stdc++.h>
using namespace std;

void leftrotate(int arr[],int n)
{
    //storing arr[0] in temp varible
    int temp =arr[0]; 
    for(int i=0;i<n;i++)
    {
    
       //now we are storing 2nd value in 1st place and so on till end of array
        arr[i] = arr[i+1]; 
    }
    
 //now we will place the 1st value back to end and our array will be rotated by one
    arr[n-1] = temp ; 
}

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    
    for(int i=0;i<n;i++)
        // taking array input
        cin>>arr[i];

    //Calling the left rotate array function
    leftrotate(arr, n);        
    
    for(int i=0;i<n;i++)
        //print the rotated array
        cout<<arr[i];
return 0;
}

/*
Time Complexity :-O(n)

input :- 1 2 3 4 5 
output :-2 3 4 5 1
*/