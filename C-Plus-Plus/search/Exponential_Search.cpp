// C++ program to find an element in a 
// sorted array using Exponential search. 

#include<iostream>
using namespace std;

int binarySearch(int array[], int start, int end, int key) {
   if(start <= end) {
      int mid = (start + (end - start) /2); //mid location of the list
      if(array[mid] == key)
         return mid;
      if(array[mid] > key)
         return binarySearch(array, start, mid-1, key);
         return binarySearch(array, mid+1, end, key);
   }
   return -1;
}

int exponentialSearch(int array[], int start, int end, int key){
   if((end - start) <= 0)
      return -1;
      int i = 1; // as 2^0 = 1
      while(i < (end - start)){
         if(array[i] < key)
            i *= 2; //i will increase as power of 2
         else
            break; //when array[i] corsses the key element
   }
   return binarySearch(array, i/2, i, key); //search item in the smaller range
}

int main() {
   int n, searchKey, loc;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n]; //create an array of size n
   cout << "Enter the elements: " << endl;
   for(int i = 0; i< n; i++) {
      cin >> arr[i];
   }
   cout << "Enter the element to search in the list: ";
   cin >> searchKey;
   if((loc = exponentialSearch(arr, 0, n, searchKey)) >= 0)
      cout << "Element found at location: " << loc+1 << endl;
   else
      cout << "Element is not found in the list." << endl;
}

// Sample Output 

// Enter the number of elements: 5
// Enter the elements: 
// 1
// 3
// 4
// 5
// 6
// Enter the element to search in the list: 1
// Element found at location: 1