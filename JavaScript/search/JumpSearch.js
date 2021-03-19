/*

Jump search is a searching algorithm which works similarly to binary search i.e. it works on sorted array.
Idea - Check fewer elements by jumping a certain number of steps.
Ex., suppose length of array is 9, then jump search will be jumped by √9 i.e 3 steps.
Time Complexity : O(√n)

*/

// Declaring the sorted array to perform searching
let array = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 111, 245, 250, 310];

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

/*
 *   @Test
*/

function test() {
  // Tests
  let target = 13;
  jumpSearch(target); // Found 13

  target = 310;
  jumpSearch(target); // Found 310

  target = 125;
  jumpSearch(target); // Not Found
}

test();

