/*The gnome sort is a sorting algorithm which is similar to insertion sort in that it works with one item at a time but gets the item to the proper place by a series of swaps, similar to a bubble sort. The algorithm finds the first place where two adjacent elements are in the wrong order and swaps them.
*/

/*
 Input
array = [10, 34, 6, 323, 7]

// Ouput
SortedArray = [6, 7, 10, 34, 323]
Time complexities:
	Worst Case :O(n2) 
  Best Case :O(n)   
  Average Case:O(n2)
Space Complexity: Auxilary Space:O(1)  
*/

//Function sort the array using gnome sort
void gnomeSort(List arr, var n) {
  if (arr == null || n == 0) return;
  int first = 1;
  int second = 2;

  while (first < n) {
    if (arr[first - 1] <= arr[first]) {
      first = second;
      second++;
    } else {
      int temp = arr[first - 1];
      arr[first - 1] = arr[first];
      arr[first] = temp;
      first -= 1;
      if (first == 0) {
        first = 1;
        second = 2;
      }
    }
  }
}

void main() {
  //Get the array
  List arr = [10, 34, 6, 323, 7];

  //Get size of the array
  int n = arr.length;

  //Sorting of array using gnome sort
  gnomeSort(arr, n);

  //print the result
  print(arr.toString());
}