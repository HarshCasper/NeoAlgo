//INTERPOLATION SEARCH
#include<bits/stdc++.h> //Importing library (This is the special type of library which will include all basic libraries)

using namespace std;

// If the searching element is present it will return its index, else it will return -1. 

int interpolationSearch(int arr[], int n, int x) {
  int low = 0, high = (n - 1); //Assigning lower index as 0 and higher index as n-1

  while (low <= high && x >= arr[low] && x <= arr[high]) {
    if (low == high) {
      if (arr[low] == x) return low;
      return -1;
    }
    // Probing the position with keeping uniform distribution in mind. 
    int pos = low + (((double)(high - low) /
      (arr[high] - arr[low])) * (x - arr[low]));

    // Condition of element to be found 
    if (arr[pos] == x)
      return pos;

    // If x is larger, x is in upper part 
    if (arr[pos] < x)
      low = pos + 1;

    // If x is smaller, x is in the lower part 
    else
      high = pos - 1;
  }
  return -1;
}

int main() //Starting our main function 
{

  int num, x, loc;
  std::cout << "Enter size of an array: ";
  std::cin >> num;
  int arr[num]; //Creating array of the size num
  std::cout << "Enter elements: " << std::endl;

  for (int i = 0; i < num; i++) //Enter the elements in the array
  {
    std::cin >> arr[i];
  }

  //Sorting our array

  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n);

  cout << "\nArray after sorting using "
  "default sort is : \n" << std::endl;
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";

  }
  cout << std::endl;

  //Entering the searching element
  std::cout << "Enter element to be searched: " << std::endl;
  cin >> x; //Element to be searched 
  int index = interpolationSearch(arr, n, x);
  //If element was found 
  if (index != -1)
    cout << "Element found at index " << index; //Returning the index pf the element
  else
    cout << "Element not found."; //Returning -1 as element has not found 

  return 0;
}

/*
SAMPLE INPUT:

5 
1
7
4
9
2 
4

SAMPLE OUTPUT:
Enter size of an array: Enter elements: 

Array after sorting using default sort is : 

1 2 4 7 9 
Enter element to be searched: 
4
Element found at index 2

Time Complexity of Interpolation Search Algorithm
Average Case: O (log log n) 
Worst Case: O(N)

Space Complexity of Interpolation Search Algorithm is O(1)
*/


