/*

Bucket sort aka bin sort, is a sorting algorithm that works by distributing the elements of an array into a number of buckets.
Algorithm -> Bucket sort works as follows -
             1) Set up an array of intially empty "buckets"
             2) Put each object in its bucket
             3) Sort each non-empty bucket
             4) Visit the buckets in order and put all elements back into the original array

Time Complexity - O(n + k), where,
                    1) O(n) is complexity of creating buckets
                    2) O(k) is complexity of sorting the buckets

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

function bucketSort(array, size) {
  // If size is not mentioned then assume it to be a random number, here 7
  if (size === undefined) size = 7;

  // return if array is empty
  if (array.length === 0) return array;

  // Get the min element from array
  let min = Math.min(...array);
  // Get the max element from array
  let max = Math.max(...array);

  // Define number of buckets
  let bucketCount = Math.floor((max - min) / size) + 1;

  // Creating a buckets of array
  const buckets = [];
  for (let i = 0; i < bucketCount; i++) buckets.push([]);

  // Insert elements in the buckets
  for (let k = 0; k < array.length; k++) {
    let key = Math.floor((array[k] - min) / size);
    buckets[key].push(array[k]);
  }

  let sorted = [];
  // Sort elements of each array and push it into the sorted array
  for (let m = 0; m < buckets.length; m++) {
    const arr = buckets[m].sort();
    for (let n = 0; n < arr.length; n++) sorted.push(arr[n]);
  }

  return sorted;
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
let sortedArray = bucketSort(array, arrayLength);
console.log("Sorted array", sortedArray);

// Sample I/O

/*

> node BucketSort

Enter array length - 5
Enter 1 element - 76
Enter 2 element - 54
Enter 3 element - 21
Enter 4 element - 90
Enter 5 element - 44
Your array -  [ 76, 54, 21, 90, 44 ]
Sorted array [ 21, 44, 54, 76, 90 ]

*/

