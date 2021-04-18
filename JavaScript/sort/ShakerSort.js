/*

Shaker Sort aka Cocktail aka bidirectional sort aka ripple sort is an extension of bubble sort.
Cocktail extends bubble sort by operating in two directions
Algortihm - 1. Loop through array from left to right -> compare adjacent values & swap accordingly
            2. Loop through array in opposite direction i.e from end to start of array
Time Complexity - 1. Best Case : O(n)
                  2. Worst/Average Case : O(n*n)

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Perform shaker sort
function ShakerSort(array) {
  let start = 1; // start index
  let end = array.length - 1; // end index

  while (start <= array.length / 2) {
    // Loop from left to right
    for (let i = start - 1; i < end; i++) {
      if (array[i] > array[i + 1]) {
        [array[i], array[i + 1]] = [array[i + 1], array[i]];
      }
    }

    end = end - 1;

    // Loop from right to left
    for (let i = end; i >= start; i--) {
      if (array[i] < array[i - 1]) {
        [array[i], array[i - 1]] = [array[i - 1], array[i]];
      }
    }

    start = start + 1;
  }

  console.log("Sorted Array - ", array);
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
ShakerSort(array);

/*

> node ShakerSort 

Enter array length - 7
Enter 1 element - 21
Enter 2 element - 87
Enter 3 element - 65
Enter 4 element - 45
Enter 5 element - 90
Enter 6 element - 32
Enter 7 element - 11

Your array -  [ 21, 87, 65, 45, 90, 32, 11 ]
Sorted Array -  [ 11, 21, 32, 45, 65, 87, 90 ]

*/

