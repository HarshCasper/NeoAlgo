/*
What is Insertion Sort?
Insertion sort is a method of sorting an array by dividing the array into a 'sorted' portion and 'unsorted' portion. Then we compare the unsorted item to see if it is larger than the previous element, if not we insert the new item. Basically we are looking from left to right and sorting as we go.

Let's start building our insertionSort function.

-----------------------------------------------------------------------------------
|                ALGORITHM                                                         |
|        Step 1 − If it is the first element, it is already sorted. return 1;              |
|        Step 2 − Pick next element                                                        |
|        Step 3 − Compare with all elements in the sorted sub-list                         |
|        Step 4 − Shift all the elements in the sorted sub-list that is greater than the   |
|                 value to be sorted                                                       |
|        Step 5 − Insert the value                                                         |
|        Step 6 − Repeat until list is sorted                                              |
|                                                                                  |
-----------------------------------------------------------------------------------


*/






const insertionSort = arr => {
    const len = arr.length;
    for (let i = 0; i < len; i++) {
      let el = arr[i];
      let j;
  
      for (j = i - 1; j >= 0 && arr[j] > el; j--) {
        arr[j + 1] = arr[j];
      }
      arr[j + 1] = el;
    }
    return arr;
  };

  console.log(insertionSort([1,3,4,1,2]));
  