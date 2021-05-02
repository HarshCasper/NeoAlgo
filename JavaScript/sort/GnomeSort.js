/*

Gnome sort is a simple algorithm which is similar to Insertion sort. The key idea of Gnome is to swap adjacent elements.
Inspired by the standard Dutch Garden Gnome sorting the flower pots. A garden gnome sorts the flower pots as :
Algorithm : 1) If the flower pot just before and after him are in correct order, then he moves one step forward.
            2) If it is not in correct order, he swaps the pots and moves back one step
            3) At the starting when there is no pot before him, he stpes forward and on reaching the end of the pot line, the list is sorted

Time Complexity : O(n ^ 2)

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Perform gnomeSort
function gnomeSort(array) {
  let start = 0;

  // While the start (position counter) is less than array length
  while (start < array.length) {
    if (start === 0) start++;

    // If adjacent elements are sorted, increment
    if (array[start] >= array[start - 1]) start++;
    // If not sorted, swap the elements & decrement the start
    else {
      [array[start], array[start - 1]] = [array[start - 1], array[start]];
      start--;
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
gnomeSort(array);
console.log("Sorted array - ", array);

// Sample I/O

/*

> node Gnome

Enter array length - 7
Enter 1 element - 40
Enter 2 element - 50
Enter 3 element - 21
Enter 4 element - 90
Enter 5 element - 70
Enter 6 element - 30
Enter 7 element - 10
Your array -  [ 40, 50, 21, 90, 70, 30, 10 ]
Sorted array - [ 10, 21, 30, 40, 50, 70, 90 ]

*/

