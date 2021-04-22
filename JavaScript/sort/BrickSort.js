/*

A sorting algorithm which is famously known as odd-even sort ( or Parity sort or Brick sort ) is a modification of bubble sort.
Algorithm -> Divide into the two phases - 
             1. Odd Phase ( Perform bubble sort on odd indexed elements )
             2. Even Phase ( Perform bubble sort on even indexed elements )

Time Complexity -> O(N^2) where, N is the number of elements in the input array

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// perform bubblesort operation w.r.t to the passed indexes
function bubbleSort(array, start, end) {
  let isSorted = true;
  for (let i = start; i <= end; i += 2) {
    if (array[i] > array[i + 1]) {
      [array[i], array[i + 1]] = [array[i + 1], array[i]];
      isSorted = false;
    }
  }

  return isSorted;
}

// perform bricksort
function brickSort(array) {
  let isSorted = false;

  while (!isSorted) {
    isSorted = true;

    isSorted = bubbleSort(array, 1, array.length - 2);
    isSorted = bubbleSort(array, 0, array.length - 2);
  }

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
brickSort(array);
console.log("Sorted array", array);

// Sample I/O

/*

> node BrickSort

Enter array length - 7
Enter 1 element - 56
Enter 2 element - 89
Enter 3 element - 40
Enter 4 element - 60
Enter 5 element - 21
Enter 6 element - 90
Enter 7 element - 10
Your array -  [
  56, 89, 40, 60,
  21, 90, 10
]
Sorted array [
  10, 21, 40, 56,
  60, 89, 90
]

*/


