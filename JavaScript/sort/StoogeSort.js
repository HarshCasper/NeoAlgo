/*

Stooge sort is a recursive sorting algorithm.
It is notable for its exceptionally bad time complexity which is slower compared to reasonable sorting algorithms.

Algorithm - 1) If value of the start is larger than the value at the end, swap them
            2) If there are 3 or more elements in the list, then -
                a] Stooge sort the initial 2/3 of the list
                b] Stooge sort the final 2/3 of the list
                c] Stooge sort the initial 2/3 of the list again

Time Complexity - O(n(log3/log1.5)) ( Slower than bubble sort )

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

function stoogeSort(array, start, end) {
  let pivot;

  // Checking condition - whehther there are at least 2 elements or not
  if (end - start + 1 > 2) {
    pivot = Math.floor((end - start + 1) / 3);
    stoogeSort(array, start, end - pivot); // sort the first 2/3
    stoogeSort(array, start + pivot, end); // sort the last 2/3
    stoogeSort(array, start, end - pivot); // sort the first 2/3 again
  }

  // Swap if the leftmost element is larget than rightmost
  if (array[start] > array[end]) {
    [array[start], array[end]] = [array[end], array[start]];
  }
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
stoogeSort(array, 0, arrayLength - 1);
console.log("Sorted Array - ", array);

// Sample I/O

/*

> node StoogeSort

Enter array length - 5
Enter 1 element - 45
Enter 2 element - 86
Enter 3 element - 23
Enter 4 element - 98
Enter 5 element - 66
Your array -  [ 45, 86, 23, 98, 66 ]
Sorted Array -  [ 23, 45, 66, 86, 98 ]

*/

