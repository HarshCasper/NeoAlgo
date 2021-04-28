/*

Timsort is a hybrid stable sorting algorithm, derived from merge sort and insertion sort, designed to perform well on many kinds of real-world data.
Algorithm - First sort small pieces using Insertion Sort, then merges the pieces using merge of merge sort.
Time Complexity - O(n log n)

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

const RUN = 32;

// Perform merge sort
function mergeSort(array, left, mid, right) {
  // get the left array
  let leftArray = array.slice(left, mid + 1);

  // get the right array
  let rightArray = array.slice(mid + 1, right + 1);

  let arr = [];

  // compare the elements in leftArray & rightArray
  while (leftArray.length && rightArray.length) {
    if (leftArray[0] < rightArray[0]) {
      arr.push(leftArray.shift());
    } else {
      arr.push(rightArray.shift());
    }
  }

  // replace sorted arr with array elements
  array.splice(left, right + 1, [...arr, ...leftArray, ...rightArray]); // [...arr, ...leftArray, ...rightArray] - resultant sorted array
  let merged = [].concat.apply([], array); // concat array containing array
  array = merged; // assign this as new array

  return array;
}

// perform insertion sort
function insertionSort(array, left, right) {
  for (let i = left + 1; i <= right; i++) {
    let temp = array[i];

    let j = i - 1;
    while (j >= left && array[j] > temp) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = temp;
  }
}

function timSort(array, length) {
  // for array less than the length of RUN i.e 32
  for (let i = 0; i < length; i += RUN)
    insertionSort(array, i, Math.min(i + RUN - 1, length - 1));

  // perform mergeSort for array length greater than RUN
  for (let size = RUN; size < length; size = 2 * size) {
    for (let left = 0; left < length; left += 2 * size) {
      // find the mid point
      let mid = left + size - 1;
      let right = Math.min(left + 2 * size - 1, length - 1);

      // call the mergeSort
      if (mid < right) array = mergeSort(array, left, mid, right);
    }
  }

  // return the sorted array
  return array;
}

/* Workflow of user input */

// Take array length as input
let arrayLength = +prompt("Enter array length - ");

// Check whether the entered value is number or not
if (isNaN(arrayLength)) return console.log("Only numbers are allowed");

// Globally declared array
let array = [];

// Take array items
for (let i = 1; i <= arrayLength; i++) {
  array.push(+prompt(`Enter ${i} element - `));

  // Check whether the entered value is number or not
  if (array.includes(NaN)) return console.log("Only numbers are allowed");
}

console.log("Your array - ", array);

// Call the algorithm
let sortedArray = timSort(array, arrayLength);
console.log("Sorted Array - ", sortedArray);

// Sample i/o

/*

> node TimSort

Enter array length - 7
Enter 1 element - 54
Enter 2 element - 78
Enter 3 element - 12
Enter 4 element - 33
Enter 5 element - 99
Enter 6 element - 60
Enter 7 element - 45
Your array -  [
  54, 78, 12, 33,
  99, 60, 45
]
Sorted Array -  [
  12, 33, 45, 54,
  60, 78, 99
]

*/

