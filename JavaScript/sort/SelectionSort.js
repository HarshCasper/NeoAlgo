/***
 *  selection sort is an in-place comparison sorting algorithm.
 *  Time Complexity of algorithm O(n^2) where n is the size of the array.
 *  It is one of the easy sorting algorithm.
 */

function SelectionSort(arr) {
  let size = arr.length;

  if (size === 0) return console.log("Array is Empty"); //If the array is empty

  for (let i = 0; i < size - 1; i++) {
    let curr_min = i; //We take the current index as the index of the minimum element

    for (let j = i + 1; j < size; j++) {
      //If there is any index with value less than curr_min we store it in curr_min
      //This condition is used to arrange array in non-decreasing(ascending) order
      //If you want to use this in non-increasing order(descending) use greather than(>)
      if (arr[j] < arr[curr_min]) curr_min = j;
    }

    //Now we swap the values of i and curr_min

    // [arr[i],arr[curr_min]] = [arr[curr_min],arr[i]]; This can be used to swap for ES6 Javascript

    let temp = arr[curr_min];
    arr[curr_min] = arr[i];
    arr[i] = temp;
  }
}

/***
 * This is the test case
 */

// let arr = [5, 1, 2, 9, 0, 5, 1];
// SelectionSort(arr);
// console.log(arr);
