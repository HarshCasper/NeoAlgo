/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

There are two ways of solving this problem -
1. Brute Force Approach
2. Optimal Solution

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Optimal soltuion
let twoSumOptimal = function (nums, target) {
  let pairs = [];
  const indicies = {}; // Object to cache elements

  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];

    // If element is present then add it to the pairs
    if (indicies[target - num]) {
      pairs.push([indicies[target - num], num]);
    }

    // Store the element
    indicies[num] = num;
  }

  if (pairs.length === 0) console.log("No match");
  else console.log("Optimal Solution - ", pairs);

  return pairs;
};

// Brute force approach
let twoSumBruteForce = (nums, target) => {
  let pairs = []; // to store all the pairs

  // Loop through the elements
  for (let i = 0; i < nums.length; i++) {
    const num = target - nums[i];

    for (let j = 0; j < nums.length; j++) {
      if (num === nums[j] && i !== j) {
        pairs.push([nums[i], nums[j]]); // push the match
      }
    }
  }

  if (pairs.length === 0) console.log("No match");
  else console.log("Brute Force Solution - ", pairs);

  return pairs;
};

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

// Get the sum target value
let sumTarget = +prompt("Enter sum target - ");

// Check whether the entered value is number or not
if (isNaN(sumTarget)) return console.log("Only numbers are allowed");

console.log("Your array - ", array);
console.log("Your sumTarget - ", sumTarget);

// Call the brute force algorithm
twoSumBruteForce(array, sumTarget);

// Call the optimal algorithm
twoSumOptimal(array, sumTarget);

// Sample I/O

/*

> node TwoSum

Enter array length - 5
Enter 1 element - 3
Enter 2 element - 5
Enter 3 element - 7
Enter 4 element - 1
Enter 5 element - 4
Enter sum target - 8
Your array -  [ 3, 5, 7, 1, 4 ]
Your sumTarget -  8
Brute Force Solution -  [ [ 3, 5 ], [ 5, 3 ], [ 7, 1 ], [ 1, 7 ] ]
Optimal Solution -  [ [ 3, 5 ], [ 7, 1 ] ]

*/


