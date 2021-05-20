/*

Comb sort is a sort of improvment over the bubble sort. Rather than comparing adjacent values, it starts with a gap of size more than 1,
& then it shrinks by a factor of 1.3 for every iteration until it reaches the value 1.

Time Complexity - 1) Average -> O(N^2/2^m) where,
                                m is the number of increments
                  2) Best -> O(n log n)
                  3) Worst -> O(n^2)
*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Calculate the gap factor
function getGap(gap) {
  gap /= 1.3;

  if (gap < 1) return 1;
  return gap;
}

// Perform the comb sort
function combSort(array) {
  let gap = array.length;
  let swap = true;

  // While the gap condition
  while (gap !== 1 || swap === true) {
    gap = getGap(gap);

    swap = false;

    // Compare elements & swap them accordingly
    for (let i = 0; i < array.length - gap; i++) {
      if (array[i] > array[i + gap]) {
        [array[i], array[i + gap]] = [array[i + gap], array[i]];
        swap = true;
      }
    }
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
combSort(array);
console.log("Sorted array", array);

// Sample I/O

/*

> Node CombSort

Enter array length - 6
Enter 1 element - 30
Enter 2 element - 89
Enter 3 element - 76
Enter 4 element - 21
Enter 5 element - 55
Enter 6 element - 62
Your array -  [ 30, 89, 76, 21, 55, 62 ]
Sorted array [ 21, 30, 55, 62, 76, 89 ]

*/


