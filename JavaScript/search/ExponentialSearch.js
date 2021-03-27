/*

Exponential search is aka doubling or galloping search works on same concept as of Binary Search i.e for a sorted array.
Algorithm - To find the specific range ( with power of 2 ) & then using binary search technique to find location of search key.

Time Complexity - a) Best Case : O(1) b) Worst Case : O(logi)

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

function exponentialSearch(key) {
  // return it the key is first element of the array
  if (array[0] === key) {
    return console.log("Found", array[0]);
  }

  // Find range by increasing the power(2) i.e. jumping by 2^i for every iteration
  let i = 1; // as 2^0 = 1
  while (i < array.length && array[i] <= key) i *= 2;

  // Pass the range to binary search
  return binarySearch(i / 2, Math.min(i, array.length), key);
}

// Binary search to find the key in specified range
function binarySearch(start, end, key) {
  if (start <= end) {
    // Find mid of given range
    let mid = Math.floor(start + (end - start) / 2);
    if (array[mid] === key) return console.log("Found", array[mid]);

    // Recursively call binary search by changing start/end points of range
    if (array[mid] > key) {
      return binarySearch(start, mid - 1, key);
    } else {
      return binarySearch(mid + 1, end, key);
    }
  } else {
    return console.log("Not found");
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

// Sort the given array ( Exponential Search works for sorted array only )
array.sort((a, b) => {
  return a - b;
});

// Ask the key/number to search in provided array
let key = +prompt("Enter number to search - ");
if (isNaN(key)) return console.log("It should be a number");

// Call the algorithm
exponentialSearch(key);

/*

Sample i/o

> node ExponentialSearch

Enter array length - 5
Enter 1 element - 84
Enter 2 element - 56
Enter 3 element - 78
Enter 4 element - 98
Enter 5 element - 63
Your array -  [ 84, 56, 78, 98, 63 ]
Enter number to search - 12
Not Found

Enter number to search 98
Found 98

*/

