/*Bubble Sort Algorithm is the simplest sorting algorithm in which each element is compared to its adjacent element 
and if first elememt is greater than second element ,then the swapping occurs.
The swapping occurs till the array is sorted.
*/

/*
// Input
array = [5, 1, 4, 2, 8]

// Ouput

SortedArray = [1, 2, 4, 5, 8]
Time complexities:
	Worst Case:O(n2) -When we have to sort the array in opposite order as 
	compared to given like ascending to descending. 
  Best Case:O(n)   - When the array is already sorted.
  Average Case:O(n2) - When elements are in jumbled order.
Space Complexity: Auxilary Space:O(2) because of variable temp and sorted.  
*/
void main() {
  List<int> array = [5, 1, 4, 2, 8];
  List<int> sortedarray = bubbleSort(array);
  print(sortedarray);
}

bubbleSort(List<int> array) {
  int lengthOfArray = array.length;
  for (int i = 0; i < lengthOfArray - 1; i++) {
   
    for (int j = 0; j < lengthOfArray - i - 1; j++) {
      
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;

        
      }
    }
  }
  return (array);
}