/*

Fibonacci search technique is a method of searching a sprted array using a divide and conquer algorithm that narrows down possible location with the aid of Fibonacci numbers.
Works similarliy to Binary Search i.e. on Sorted array
Algorithm - Divide the array into two parts that have sizes that are consecutive Fibonacci numbers.
Time Complexity - O(log n)

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

function fibonacciSearch(array, key) {
  let fib0 = 0;
  let fib1 = 1;
  let fibK = fib0 + fib1;

  // Get the smallest fibonaaci number greater than or equal to array length
  while (fibK < array.length) {
    fib0 = fib1;
    fib1 = fibK;
    fibK = fib0 + fib1;
  }

  let offSet = -1;

  // Start comparing the key
  while (fibK > 1) {
    // Get the valid array location
    let i = Math.min(offSet + fib0, array.length - 1);

    // if key is greater than the value, then cut the subarray - [offset, i]
    if (array[i] < key) {
      fibK = fib1;
      fib1 = fib0;
      fib0 = fibK - fib1;
      offSet = i;
    } else if (array[i] > key) {
      // if key is smaller than the value, then cut the subarray - [i + 1, array.length]
      fibK = fib0;
      fib1 = fib1 - fib0;
      fib0 = fibK - fib1;
    } else {
      return console.log(`Element ${array[i]} found at ${i + 1}`);
    }
  }

  // Last element case
  if (fib1 && array[offSet + 1] === key)
    return console.log(`Element ${array[offSet + 1]} found at ${offSet + 2}`);

  return console.log("Element not found");
}

/* Workflow of user input */

// Take array length as input
let arrayLength = +prompt("Enter array length - ");

// Check whether the entered value is number or not
if (isNaN(arrayLength)) return console.log("Only numbers are allowed");

// Globally declared array
let array = [];

// Take array elements
for (let i = 1; i <= arrayLength; i++) {
  array.push(+prompt(`Enter ${i} element - `));

  if (array.includes(NaN)) return console.log("Only numbers are allowed");
}

console.log("Your array - ", array);

// Sort the array before searching
array.sort((a, b) => {
  return a - b;
});
console.log("Sorted array - ", array);

// Get the key to be searched
let key = +prompt("Enter number to search - ");
if (isNaN(key)) return console.log("It should be a number");

// Call the algorithm
fibonacciSearch(array, key);

// Sample I/O

/*

> node FibonacciSearch

Enter array length - 5
Enter 1 element - 55
Enter 2 element - 30
Enter 3 element - 90
Enter 4 element - 12
Enter 5 element - 70
Your array -  [ 55, 30, 90, 12, 70 ]
Sorted array -  [ 12, 30, 55, 70, 90 ]
Enter number to search - 55
Element 55 found at 3

*/

