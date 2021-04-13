/*
In our program in each iteration we first do bubble sort on odd indexed elements and then a bubble sort on the even indexed elements.
Will we get a sorted result if we first perform a bubble sort on even indexed element first and then on the odd indexed element
*/

#include<bits/stdc++.h>
using namespace std;

// A function to sort the algorithm using Odd Even sort
void oddEvenSort(int arr[], int n)
{
    // Initially array is unsorted
    bool isSorted = false; 
 
    while (!isSorted)
    {
        isSorted = true;
 
        //Bubble sort on odd indexed element
        for (int i=1; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
             {
                //swap arr[i] and arr[i+1]
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                
                isSorted = false;
              }
        }
 
        // Bubble sort on even indexed element
        for (int i=0; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
            {
                //swap arr[i] and arr[i+1]
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                isSorted = false;
            }
        }
    }
 
    return;
}

signed main()
{
    //Taking Input
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //Applying Sort
    //calling sort function
    oddEvenSort(arr, n);
    cout<<"Sorted Array is :-";
    for (int i = 0; i < n; i++){ 
        cout<<arr[i]<<" ";
    }
    return 0;
}
/* Sample Input
11
35 23 12 17 12 72 31 46 180 88 54
*/
/* Sample Output
Sorted Array is:- 12 12 17 23 31 35 46 54 72 88 180
*/

// Time Complexity -O(n^2)
//Space Complexity -O(1)
