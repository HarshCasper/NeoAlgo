/*

Jump search is a searching algorithm which works similarly to binary search i.e. it works on sorted array.
Idea - Check fewer elements by jumping a certain number of steps.
Ex., suppose length of array is 9, then jump search will be jumped by √9 i.e 3 steps.
Time Complexity : O(√n)

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

function jumpSearch(number) {
  // Number of steps to jump
  let jump = Math.floor(Math.sqrt(array.length));
  let start, end;

  start = 0;
  end = jump;

  // Loop to get the range in which 'number' resides
  while (array[end] <= number && end < array.length) {
    // Upgrade step range
    start = end;
    end = end + jump;

    // if end is greater than array of length
    if (end > array.length - 1) {
      end = array.length;
    }
  }

  // Start looking through the range
  for (let i = start; i <= end - 1; i++) {
    if (array[i] === number) {
      return console.log("Found", array[i]);
    }
  }

  return console.log("Not found");
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

// Sort the given array ( Jump Search works for sorted array only )
array.sort((a, b) => {
  return a - b;
});

// Ask the key/number to search in provided array
let key = +prompt("Enter number to search - ");
if (isNaN(key)) return console.log("It should be a number");

// Call the algorithm
jumpSearch(key);

/*

Sample i/o

> node JumpSearch

Enter array length - 5
Enter 1 element - 23
Enter 2 element - 45
Enter 3 element - 87
Enter 4 element - 12
Enter 5 element - 54
Your array -  [ 23, 45, 87, 12, 54 ]
Enter number to search - 54
Found 54

Enter number to search - 14
Not Found

*/

