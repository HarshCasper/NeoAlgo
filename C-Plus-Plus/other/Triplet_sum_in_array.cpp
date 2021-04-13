/*Triplet Sum in an array

Given an array arr of size n and an integer X.
Find if there's a triplet in the array 
which sums up to the given integer X.

*/
#include<bits/stdc++.h>

using namespace std;
int tripletSum() {
  int size_of_array, sum, array[size_of_array], cnt = 0;
  cout << "Enter size of array: ";
  cin >> size_of_array;
  cout << "Enter the sum: ";
  cin >> sum;
  cout << "Enter array elements: ";
  for (int i = 0; i < size_of_array; i++) {
    cin >> array[i];
  }
  int first_number, second_number, third_number;
  for (first_number = 0; first_number < size_of_array - 2; first_number++) {
    for (second_number = first_number + 1; second_number < size_of_array - 1; second_number++) {
      for (third_number = second_number + 1; third_number < size_of_array; third_number++) {
        if (array[first_number] + array[second_number] + array[third_number] == sum) {
          cnt++;
        }

      }
    }
  }
  if (cnt >= 1) {
    cout << "1" << endl;
  } else {
    cout << "0" << endl;
  }
}

int main() {
  tripletSum();
  return 0;
}
/*
Input:
Enter size of array: 5
Enter the sum: 10
Enter array elements: 1 2 4 3 6
Output:
1

Space Complexity-O(1)
Time Complexity-0(N^2)
*/
