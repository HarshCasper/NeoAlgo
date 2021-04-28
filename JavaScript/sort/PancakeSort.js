/*

Unlike a traditional sorting algorithm, which attempts to sort with the fewest comparisons possible,
the pancake sorting algorithm sorts the sequence in as few reversals as possible. Something similar to selection sort.

Algorithm - Start from current size equal to n and reduce current size by one while it's greater than 1.
                1. Find max form the reduced array size.
                2. Compare max with array elements and flip accordingly

Time Complexity - O(n ^ 2)    
            
*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Flip elements
function flip(array, index) {
  let start = 0;
  while (start < index) {
    [array[start], array[index]] = [array[index], array[start]];
    start++;
    index--;
  }
}

// Perform pancake sorting
function panCake(array) {

  // Create chunks of array one by one
  for (let i = array.length; i > 1; --i) {
    let max = array.indexOf(Math.max(...array.slice(0, i))); // get the max of chunk

    if (max !== i - 1) {
      flip(array, max); // flip array by moving max to the beginning
      flip(array, i - 1); // reverse the array
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
panCake(array);
console.log("Sorted array - ", array);

/*

> node PancakeSort

Enter array length - 5
Enter 1 element - 21
Enter 2 element - 50
Enter 3 element - 11
Enter 4 element - 90
Enter 5 element - 45
Your array -  [ 21, 50, 11, 90, 45 ]
Sorted array - [ 11, 21, 45, 50, 90 ]

*/

