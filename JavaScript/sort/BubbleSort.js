/**
 * time complexity O(n*n) - space complexity O(1)
 */

function BubbleSort(arr) {
  for (let i = 0; i < arr.length; i++) {
    // outer loop
    let isSwapped = false; //  create a boolean to keep track of whether or not there was a successful comparison made
    for (let j = 0; j < arr.length - 1; j++) {
      // inner loop
      if (arr[j] > arr[j + 1]) {
        // check if the current value is greater than next value
        [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]; // Swap the current value and next value
        isSwapped = true; // Set swap variable to true
      }
    }
    if (!isSwapped) {
      // if there's no swap, the arr is fully sorted and can exit there, we break.
      break;
    }
  }

  return arr; // return the sorted array
}

console.log(BubbleSort([4, 2, 1, 3]));
// output should be => [1, 2, 3, 4]

console.log(BubbleSort([-4, 18, 2, 0, 6]));
// output should be => [-4, 0, 2, 6, 18]
