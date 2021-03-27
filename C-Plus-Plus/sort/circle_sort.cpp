// C++ program to implement Circle  Sort

#include<bits/stdc++.h> 
using namespace std; 
  
/*
Performs recursive circular swaps and returns true if atleast one swap occurs
*/
bool rec_sort(int arr[], int beg, int end) 
{ 
    bool isSwap = false; 
  
    // If concerned array is empty, Return
    if (beg == end) 
        return false; 
  
    // Storing the values of beg, end to later use in the recursive call
    int begA, endA;
    for(begA = beg, endA = end; begA < endA; begA++, endA--) 
    { 
        //Compares the first and last elements 
        if (arr[begA] > arr[endA]) 
        { 
            swap(arr[begA], arr[endA]); 
            isSwap = true; 
        } 
        
    } 
  
    // If the array has odd number of elements
    if (begA == endA) 
        if (arr[begA] > arr[endA + 1]) 
        { 
            swap(arr[beg], arr[endA+1]); 
            isSwap = true; 
        } 
  
    int mid = (end - beg) / 2; 
    bool isSwapA = rec_sort(arr, beg, beg+mid); 
    bool isSwapB = rec_sort(arr, beg+mid+1, end); 
  
    return (isSwap || isSwapA || isSwapB); 
} 

void circle_sort(int arr[], int n) 
{  
    while (rec_sort(arr, 0, n-1)) 
    {    
        
    } 
} 
  

int main()
{
    int n;
    cout<<"\nHow many numbers do you want to sort? ";
    cin>>n;
    int arr[n];

    if (n <= 0)
    {
        cout<<"The array is Empty!!!";
        return 0;
    }
    // Input the numbers to sort
    cout<<"Enter the numbers: ";
    for (int i = 0; i < n; i++)
        cin>>arr[i];
  
    //Call the sort function 
    circle_sort(arr,n);  

    cout<<"The numbers in sorted order is: ";
    // Print the sorted array
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

/*

Time Complexity: O(n*log(n))
Space Complexity: O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
How many numbers do you want to sort? 5
Enter the numbers: 1 3 5 2 4
The numbers in sorted order is:  1  2  3  4  5

SAMPLE 2
How many numbers do you want to sort? 0
The array is Empty!!!

*/
