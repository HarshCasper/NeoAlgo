// C++ program to implement Comb  Sort

/*
Comb sort is an improvised Bubble sort. Bubble sort removes its inversion one by one whereas In Comb sort,
more than one inversion is removed by one swap and hence it is more efficient than Bubble sort.
*/

#include <bits/stdc++.h> 
using namespace std; 

// Comb sort
void comb_sort(int arr[], int n)
{
    int flag= 1, space = n; 
    
    while (space > 1 || flag == 1) 
    {
        // Here empirically found shrink factor 1.3 is used.
        space = (space * 10) / 13;
        
        //Assigning space its minimum value of 1
        if(space < 1)
            space = 1;
    
        flag = 0;
        
        // Compare elements with the space value
        for (int i = 0; i < (n - space); i++) 
        {
            if (arr[i] > arr[i + space]) 
            {
                swap(arr[i],arr[i+space]);
                flag= 1;
            }
        }
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
    comb_sort(arr,n);  

    cout<<"The numbers in sorted order is: ";
    // Print the sorted array
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

/*

Time Complexity: O(n^2), though in average works better than bubble sort
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
