/*The Comb Sort is a variant of the Bubble Sort. Like the Shell sort, the Comb Sort increases the gap used in comparisons and exchanges.
*/

/*
 Input
array = [1, 451, 562, 2, 99, 78, 5]

// Ouput
SortedArray = [1, 2, 5, 78, 99, 451, 562]
Time complexities:
	Worst Case :O(n2) 
  Best Case :O(nlogn)   
  Average Case:Ω(N2/2p)
Space Complexity: Auxilary Space:O(1)  
*/

// function for combsort
void combSort(List list) {
  int gpVal = list.length;
  double shrink = 1.3;
  bool sortedBool = false;

  while (!sortedBool) {
    gpVal = (gpVal / shrink).floor();
    if (gpVal > 1) {
      sortedBool = false;
    } else {
      gpVal = 1;
      sortedBool = true;
    }

    int i = 0;
    while (i + gpVal < list.length) {
      if (list[i] > list[i + gpVal]) {
        swap(list, i, gpVal);
        sortedBool = false;
      }
      i++;
    }
  }
}

// function to swap the values
void swap(List list, int i, int gpVal) {
  int temp = list[i];
  list[i] = list[i + gpVal];
  list[i + gpVal] = temp;
}

void main() {
  //Get the dummy array
  List arr = [1, 451, 562, 2, 99, 78, 5];
  // applying combSort function
  combSort(arr);
  // printing the sortedBool value
  print(arr);
}