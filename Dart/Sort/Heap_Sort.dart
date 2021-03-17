/*Heapsort is an in-place sorting algorithm with worst case and average complexity of O(n logn). The basic idea is to turn the array into a binary heap structure, which has the property that it allows efficient retrieval and removal of the maximal element.
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

void sort(List arr) {
  //The length of the list
  int n = arr.length;

  //Build heap (rearrange arrary)
  for (int i = (n / 2 - 1).round(); i >= 0; i--) {
    heapify(arr, n, i);
  }

  // One by one extract an element from heap
  for (int i = n - 1; i >= 0; i--) {
    //Move current root to end
    var temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    //call max heapify on the reduce heap
    heapify(arr, i, 0);
  }
}

void heapify(List arr, var n, var i) {
  //Init largest as root
  var largest = i;
  //left = 2*i + 1
  var l = 2 * i + 1;
  //right = 2*i + 2
  var r = 2 * i + 2;

  // If left child is lager than root
  if (l < n && arr[l] > arr[largest]) largest = l;

  // If right child is larger than largest so far
  if (r < n && arr[r] > arr[largest]) largest = r;

  // If largest is not root
  if (largest != i) {
    var swap = arr[i];
    arr[i] = arr[largest];
    arr[largest] = swap;

    //Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

void main() {
  List list = [19, 48, 5, 7, 99, 10];
  sort(list);
  print(list);
}