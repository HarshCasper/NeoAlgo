// EXECUTION OF INSERTION SORT IN C++

/*First we  will  compare first element in the list with its adjacent element.

And at every comparison if the element can be inserted at a particular position, 
then it is inserted by shifting the other elements one position to the right.

The above steps are repeated until all the elements in the list are in their 
appropriate position.i.e. list is in sorted order.*/

#include <iostream>
using namespace std;

// Function to print array.
void display(int arr[], int size) { 
    int i;
    for (i=0; i < size; i++)
    cout<< arr[i]<<"\t";
    cout<<"\n";
}

// swapping elements in the array
void swap(int arr[], int i , int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Main function to run the program
int main()
{
    int size;
    cout << "Enter size of array:" << endl;
    cin >> size;
    int array[size];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    int i, j, k;
    for (i = 1; i < size; i++) 
    {  
        // target = array[i];  
        // j = i - 1;  
        j = i-1;
        k = i;
        /* Here the elements in b/w arrary[0 to i-1]
        which are greater than target are moved
        ahead by 1 position each*/
        while (j >= 0 && array[k] < array[j]) 
        {  
            swap(array, k, j);
            j--;
            k--;
        }
    }
    cout<<"After Insertion sort: \n";
    display(array, size);
    return 0;
}

/**
Enter the size of list:
6
Enter the numbers:
5
0
2
1
4
3
Sorted list:
0
1
2
3
4
5

Time Complexity: O(n*2)
Space Complexity: O(1)
 */
