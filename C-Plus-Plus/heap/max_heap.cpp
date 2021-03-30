/* 
Formation of max-heap with the help of array and recurtion process.
Heap is a kind of complete binery tree,which is used for sorting and pritority queue purpose.
*/
#include <iostream>
using namespace std;

//function for comparison and swap process
void swap_func(int *arr, int n, int i)
{

    int largest = i;       //parent node
    int l = ((2 * i) + 1); //formula to access left child of parent node
    int r = ((2 * i) + 2); //formula to access right child of parent node

    //parent comaparing with left child,
    //first check if left child exit
    if (l <= n and arr[l] > arr[largest])
        largest = l;
    //parent comaparing with right child,
    //first check if right child exit
    if (r <= n and arr[r] > arr[largest])
        largest = r;
    
    //if parent is smaller then child node value
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
      //call the function recursively
        swap_func(arr, n, largest);
    }
}
//main function for formation of max-heap
void heapify(int *arr, int n)
{
    //first non negative node or parant node 
    int first_node = (n / 2) - 1;

    for (int i = first_node; i >= 0; i--)
    {
        swap_func(arr, n, i);
    }
}
//function to prient the array which is max-heap
void prient(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
//driver code
int main()
{
    int array[] = {4, 56, 2, 3, 7, 8};        // array
    int n = sizeof(array) / sizeof(array[0]); //size of array

    //function for formation of max-heap
    heapify(array, n);
    //function to prient the array which is max-heap
    prient(array, n);
}
/*     
  sample input:
  if array[]= {4, 56, 2, 3, 7, 8};  
             4
           /   \
          56     2
         /  \   /
        3   7  8 

   sample output:
    array  =   56 7 8 3 4 2   
             56
           /   \
          7     8
         /  \   /
        3   7  2

  ->TC =O(n*logn);
  ->SC =O(1);       
*/
