/*
In selection sort algorithm, an array is divided into two parts : sorted and unsorted. In this algorithm. we contiuously find minimum element
from unsorted part and we put it at beginning of the sorted subarray. 
*/


#include<iostream>
using namespace std;
void swapping(int &a, int &b) {         //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}


void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}


void selection_sort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;   //get index of minimum data
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
         //placing in correct position
         swap(array[i], array[imin]);
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];           //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   selection_sort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}

/*
Sample Input: Enter the number of elements:
              5
              Enter elements:
              3
              1
              -9
              8
              6
Sammple Output: Array before Sorting 
                 3 1 -9 8 6
                Array after Sorting:
                -9 1 3 6 8
Time Complexity: O(n^2)
Space Complexity: O(1)
*/