/* Heap sort is one of the sorting algorithms used to arrange a list of elements in order. Heapsort algorithm uses one of the tree concepts called Binary Heap Tree. 
In this sorting algorithm, I have used Max Heap to arrange list of elements in Descending order.

Step 1 - we construct a complete Binary Tree with given list of Elements using array.
Step 2 - Transform the Binary Tree into Max Heap.
Step 3 - Delete the root element from Max Heap 
Step 4 - Put the deleted element into the Sorted list.

@Author: Arun Kumar G
@Created: 01/07/2020   */

#include <iostream>
using namespace std;

 /* Convert the Given array of elements into Max Heap where "i"th element is parent, 
     "2*i"th element is left child and "2*(i+1)" is right child in array representation */
void CreateMaxHeap(int A[],int n)  
{
    int temp=A[n],i=n;
    while(i>1 && temp > A[i/2])   
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

void DisplayHeap(int A[],int size)   // Display the Sorted elements in heap after deletion
{
    for(int i=1;i<=size;i++)
    {
        cout << A[i] << " ";
    }
    cout <<endl;
    
}

void DeleteHeap(int A[],int n)   // Here we delete only root element which is Max and insert into into last element of Heap Array 
{
    int i,j,tmp,root;
    i=1;
    j=2*i;
    root=A[1];      //Swap the root element with last element in Array
    A[1]=A[n];
    A[n]=root;
    while(j<n-1)
    {
        if(A[j+1] > A[j])   //Inorder to maintain Max heap,Elements in array is arranged
        {
            j=j+1;
        }
        if(A[j] > A[i])
        {
         tmp=A[i];
         A[i]=A[j];
         A[j]=tmp;
         i=j;
         j=2*i;
        }
        else
        {
            break;
        }
        
    }
}

int main()
{
    int A[8]={0,30,25,40,10,50,20,5};
    for(int i=2;i<=7;i++)          
    {
        CreateMaxHeap(A,i);   //Max Heap is created 
    }
    cout << "After performing Heap sort via deletion:" << endl;
    for(int i=7;i>=1;i--)
    {
        DeleteHeap(A,i);
    }
    DisplayHeap(A,7);  // Display Sorted elements in increasing order
    return 0;
}
