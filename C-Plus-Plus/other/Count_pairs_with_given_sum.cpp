/* Count pairs with given sum

Given an array of array_size integers, and an integer sum,
find the number of pairs of elements in 
the array whose sum is equal to sum.

*/
#include<bits/stdc++.h>

using namespace std;
int countpairs() {
  int array_size, sum, counter = 0, array[array_size];
  cout << "Enter size of array: ";
  cin >> array_size;
  cout << "Enter the required sum: ";
  cin >> sum;
  for (int i = 0; i < array_size; i++) {
    cin >> array[i];
  }
  for (int j = 0; j < array_size - 1; array_size++) {
    for (int k = j + 1; k < array_size; array_size++) {
      if (array[j] + array[k] == sum) {
        counter++;
      }
    }

  }
  cout << "Number of pairs found: " << counter;

}
int main() {
  countpairs();
  return 0;

}

/*
Input:
Enter size of array:4
Enter required sum:6
Enter array elements:1 5 7 1
Output:
Number of pairs found:2

Time Complexity: O(N)
Auxiliary Space: O(N)

*/
