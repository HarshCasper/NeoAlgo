/*
Created by shubhgupta9
C++ implementation of DNF sort or Dutch National Flag sort

Code for the algorithm goes here:-

This algorithm is used to sort an array of 3 numbers, in our example code we will be taking 
a default unsorted array which consists of 0s,1s and 2s.
*/

#include<bits/stdc++.h>

using namespace std;

//swap function
void swap(int arr[],int a,int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

//Sorting algo 
void DNF(int arr[],int n)
{
    int low = 0; // Will signify from where the 1s will be starting 
    int mid = 0; // Denotes the unknown region 
    int high = n-1; // Will signify from where the 2s will be starting
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr,low,mid);
            low++; mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else 
        {
            swap(arr,mid,high);
            high--;
        }
    }
}

//Main Code
int main()
{
    int arr[] = {1,0,2,1,0,1,2,1,2};
    DNF(arr,9);
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

/*
Example Input:-
1 0 2 1 0 1 2 1 2 

Example Output:-
0 0 1 1 1 1 2 2 2

Time Complexity: O(n)
Space Compexity: O(1)

*/
