/*Cocktail sort is the variation of Bubble Sort which traverses the list in both directions alternatively. It is different from bubble sort in the sense that, bubble sort traverses the list in forward direction only, while this algorithm traverses in forward as well as backward direction in one iteration.
*/

/*
 Input
array = [5, 3, 6, 7, 3, 378, 3, 1, -1]

// Ouput
SortedArray = [-1, 1, 3, 3, 3, 5, 6, 7, 378]
Time complexities:
	Worst Case:O(n2) 
  Best Case :O(n2)   
  Average Case:O(n2) 
Space Complexity: Auxilary Space:O(1)  
*/
void cocktailSort(List lst) //function to sort a list
{
  bool swap_done = true;
  do {
    swap_done = false;
    for (int i = 0; i < lst.length - 2; i++) {
      swap_done = swapItemCocktail(lst, i, swap_done);
    }

    if (swap_done) {
      swap_done = false;
      for (int i = lst.length - 2; i >= 0; i--) {
        swap_done = swapItemCocktail(lst, i, swap_done);
      }
    }
  } while (swap_done);
}

bool swapItemCocktail(List lst, int i, bool swap_done) {
  if (lst[i] > lst[i + 1]) {
    swap(lst, i);
    swap_done = true;
  }
  return swap_done;
}

void swap(List lst, int i) {
  int tmp = lst[i];
  lst[i] = lst[i + 1];
  lst[i + 1] = tmp;
}

void main() 
{
  var lst = [5, 3, 6, 7, 3, 378, 3, 1, -1];
  cocktailSort(lst);
  print(lst);
}