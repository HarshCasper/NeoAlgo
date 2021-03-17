/*Insertion sort is a simple sorting algorithm. For n elements it does on the order of n * log(n) comparisons but up to n squared moves. The sorting is performed in-place, without using extra memory.
*/

/*
 Input
array = [19, 48, 5, 7, 99, 10]

// Ouput
SortedArray = [5, 7, 10, 19, 48, 99]
Time complexities:
	Worst Case :O(n logn) 
  Best Case :O(nn log)   
  Average Case:O(n logn)
Space Complexity: Auxilary Space:O(1)  
*/



void main() {
 
  List list = [19, 48, 5, 7, 99, 10];
 
  insertSort(list);
  print(list);
}

void insertSort(List a) {
  for (var i = 1; i < a.length; i++) {
    int j, t = a[i];
    for (j = i - 1; j >= 0 && t < a[j]; j--) {
      a[j + 1] = a[j];
    }
    if (j < i - 1) a[j + 1] = t;
  }
}