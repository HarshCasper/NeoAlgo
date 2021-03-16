// C++ program to implement Pigeon Hole  Sort

#include <bits/stdc++.h> 
using namespace std; 

// Pigeon hole sort
void pigeon_hole_sort(int arr[], int n) 
{ 

    int min = arr[0], max = arr[0]; 
    //Find the statistical range of the given array
    for (int i = 1; i < n; i++) 
    { 
        if (arr[i] < min) 
            min = arr[i]; 
        if (arr[i] > max) 
            max = arr[i]; 
    } 
    int range = max - min + 1; // Find range 

    // Declare an array with the size of the range.
    int holes[range];
    
    memset(holes, 0, sizeof(holes)); //Initialize the new array with value 0.
    
   //Filling the 'holes' array with the input array values
   for (int j=0; j < n;j++)
          holes[arr[j] - min]++;
 
   // Put the elements back into the array in ascending occurence order.
   int index=0;
   for (int i = 0; i < range; i++)
      while (holes[i]-- > 0)
        {
              arr[index] = i + min;
              index=index+1;
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
    pigeon_hole_sort(arr,n);  

    cout<<"The numbers in sorted order is: ";
    // Print the sorted array
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

/*

Time Complexity: O(n+range), where 'range' is statistical range of the given input values
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
