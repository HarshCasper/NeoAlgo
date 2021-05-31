// Converting min Heap to max Heap

#include<bits/stdc++.h>
using namespace std;
 
// to heapify a subtree 
void MaxHeap(int arr[], int x, int num)
{
    int left = 2*x + 1;
    int right = 2*x + 2;
    int greatest = x;
    if (left < num && arr[left] > arr[x])
        greatest = left;
    if (right < num && arr[right] > arr[greatest])
        greatest = right;
    if (greatest != x)
    {
        swap(arr[x], arr[greatest]);
        MaxHeap(arr, greatest, num);
    }
}
 

void convertMaxHeap(int arr[], int n)
{
    // Start from bottommost and rightmost
    // internal mode and heapify all internal
    // modes in bottom up way
    for (int i = (n-2)/2; i >= 0; --i)
        MaxHeap(arr, i, n);
}
 
// A utility function to print a given array
// of given size
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
 
//Main Function
int main()
{
    // array with elements of Min Heap Tree
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printf("Min Heap array : ");
    printArray(arr, n);
 
    convertMaxHeap(arr, n);
 
    printf("\nMax Heap array : ");
    printArray(arr, n);
 
    return 0;
}
/*
OUTPUT:
Enter the size of the array:8

Enter the array elements:10 19 20 23 25 16 26 51

Min Heap array : 10 19 20 23 25 16 26 51 

Max Heap array : 51 25 26 23 10 16 20 19 

TIME COMPLEXITY: O(N)  [N here is number of elements in array]
SPACE COMPLEXITY: O(N)
*/
