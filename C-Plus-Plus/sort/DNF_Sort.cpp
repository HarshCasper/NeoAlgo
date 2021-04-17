/* DNF Sort is one of the most popular sorting algoritm. 
For DNF (Dutch National Flag), we sort an array of 0, 1, and 2's in 
linear time that does not consume any extra space. 
We have to keep in mind that this algorithm can be implemented only 
on an array that has three unique elements.*/

#include <iostream>
using namespace std;

// Function to swap array arr[]
void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2}
void dnfSort(int arr[],int n){
    //initialize three pointers
    int low=0;
    int mid=0;
    int high=n-1;
    
    
    // Iterate till all the elements
    // are sorted
    while(mid<=high){
        // If the element is 0, swap arr[low] and arr[mid], low++, mid++
        if(arr[mid]==0){
            swap(arr,low,mid);
            low++; mid++;
        }
        // If the element is 1, mid++
        else if(arr[mid]==1){
            mid++;
        }
        // If the element is 2, swap arr[mid] and arr[high], high--
        else{
            swap(arr,mid,high);
            high--;
        }
    }
    
}


// Driver Code
int main()
{
    int n;
    cout<<"Enter no. of Elements: ";
    //input size of array arr
    cin>>n; 
    
    int arr[n];
    cout<<"Enter Elements: ";
    //For loop to input n elements into the array with space inbetween
    for(int i=0;i<n;i++){
        cin>>arr[i]; 
    }
    
    dnfSort(arr,n); //Call dnf Function
    
    cout<<"Sorted Elements: ";
     //Print the sorted array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

/*
Input:
Enter no. of Elements: 6
Enter Elements: 2 1 0 2 1 0
Output:
Sorted Elements: 0 0 1 1 2 2

Time Complexity: O(N), single pass
Space Complexity: O(1)
*/