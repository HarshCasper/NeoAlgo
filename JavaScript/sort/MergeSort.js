/**
 *
 * Merge sort uses the concept of divide-and-conquer to sort the given list of elements.
 * It breaks down the problem into smaller subproblems until they become simple enough to solve directly.
 * 
 * Time Complexity: O(nlogn)
 * 
 * Space Complexity: O(n) 
 */
function merge(left, right) {
  let arr = [];
  // Break out of loop if any one of the array gets empty
  while (left.length && right.length) {
    // Pick the smaller among the smallest element of left and right sub arrays
    if (left[0] < right[0]) {
      arr.push(left.shift());
    } else {
      arr.push(right.shift());
    }
  }

  // Concatenating the leftover elements
  // (in case we didn't go through the entire left or right array)
  return [...arr, ...left, ...right];
}

function mergeSort(array) {
  const half = array.length / 2;

  // Base case or terminating case
  if (array.length < 2) {
    return array;
  }

  const left = array.splice(0, half);
  return merge(mergeSort(left), mergeSort(array));
}

var array = prompt("Enter Numbers to Sort (Comma Separated) : ").split(",");
// You Can also give static input if prompt() not works for you. like this :
// array = [4, 8, 7, 2, 11, 1, 3];

console.log(mergeSort(array));

/*
 * Sample Input:
 * 96,56,53,85,115,20
 *
 * Sample Output:
 * 20,53,56,85,96,115
 */
