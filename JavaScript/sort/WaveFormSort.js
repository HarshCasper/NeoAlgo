/*

Given an unsorted array, sort the array into a wave form.
Wave form - array[0] >= array[1] <= array[2] >= array[3] <= array[4] >= array[5] and so on
Algorithm - 1. Sort the given array
            2. Swap all adjacent elements 
Time Complexity - O(nLog n), if sorting algorithm like Merge sort is used

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

function mergeSort(array) {
  // Case of only one array element
  if (array.length === 1) {
    return array;
  }

  // get the mid point and divide the array in each half
  const middle = Math.floor(array.length / 2);
  const left = array.slice(0, middle);
  const right = array.slice(middle);

  // Call the algorithm to compare elements of each sub half
  return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
  let arr = [];

  // Compare elements and add accordingly in arr
  while (left.length && right.length) {
    if (left[0] < right[0]) {
      arr.push(left.shift());
    } else {
      arr.push(right.shift());
    }
  }

  // return the arr & the left elements from leftArray + rightArray
  return [...arr, ...left, ...right];
}

// Perform waveSort
function waveSort(array) {
  // Call the merge sort algorithm
  let sortedArray = mergeSort(array);

  // Swap adjacent elements
  for (let i = 0; i < sortedArray.length - 1; i += 2) {
    [sortedArray[i], sortedArray[i + 1]] = [sortedArray[i + 1], sortedArray[i]];
  }

  return sortedArray;
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
let waveArray = waveSort(array);
console.log("Wave form - ", waveArray);

/*

> node WaveFormSort

Enter array length - 7
Enter 1 element - 62
Enter 2 element - 45
Enter 3 element - 21
Enter 4 element - 80
Enter 5 element - 30
Enter 6 element - 90
Enter 7 element - 11
Your array -  [ 62, 45, 21, 80, 30, 90, 11 ]
Wave form -  [ 21, 11, 45, 30, 80, 62, 90 ]

*/
