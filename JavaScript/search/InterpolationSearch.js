/*

Interpolation search is a searching algorithm which works similarly to binary search i.e. it works on sorted array.
Interpolation search finds a particular item by computing the probe position.

If the middle item is greater than the item, then the probe position is again calculated in the sub-array to the right of the middle item.
Otherwise, the item is searched in the subarray to the left of the middle item.

Time Complexity - Ο(log (log n))

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

function interpolationSearch(key) {
  let lowIndex = 0;
  let mid = -1;
  let highIndex = array.length - 1;

  // Check if key lies in the lowerBound & upperBound of array
  while (
    lowIndex <= highIndex &&
    key >= array[lowIndex] &&
    key <= array[highIndex]
  ) {

    // Check if array contains only one element
    if (array.length === 1) {
      if (key === array[lowIndex]) return console.log("Found", array[lowIndex]);
      return console.log("Not Found");
    }

    // Calculate the mid position ( or Probe )
    mid =
      lowIndex +
      Math.floor(
        ((highIndex - lowIndex) / (array[highIndex] - array[lowIndex])) *
          (key - array[lowIndex])
      );

    // Check whether the key is found, if not then update the range i.e lowerBound & upperBound
    if (array[mid] === key) {
      return console.log("Found", array[mid]);
    } else {
      if (array[mid] < key) {
        lowIndex = mid + 1;
      } else if (array[mid] > key) {
        highIndex = mid - 1;
      }
    }
  }

  return console.log("Not Found");
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

// Sort the given array ( Interpolation Search works for sorted array only )
array.sort((a, b) => {
  return a - b;
});

// Ask the key/number to search in provided array
let key = +prompt("Enter number to search - ");
if (isNaN(key)) return console.log("It should be a number");

// Call the algorithm
interpolationSearch(key);

/*

Sample i/o

> node InterpolationSearch

Enter array length - 5
Enter 1 element - 34
Enter 2 element - 56
Enter 3 element - 78
Enter 4 element - 98
Enter 5 element - 23
Your array -  [ 34, 56, 78, 98, 23 ]
Enter number to search - 12
Not Found

Enter number to search 56
Found 56

*/


