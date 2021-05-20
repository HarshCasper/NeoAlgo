/*

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

input: heights = [1,8,6,2,5,4,8,3,7]
Output: 49

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

/* Brute Force Solution */
const getMaxWaterContainerBrute = function (heights) {
  let maxArea = 0;

  // Loop through the each points
  for (let a1 = 0; a1 < heights.length; a1++) {
    for (let a2 = a1 + 1; a2 < heights.length; a2++) {
      const height = Math.min(heights[a1], heights[a2]);
      const width = a2 - a1;
      const area = height * width;
      maxArea = Math.max(maxArea, area); // get the max area
    }
  }

  console.log("Max water container can contain (Brute) - ", maxArea);
  return maxArea;
};

/* Optimal Solution */
const getMaxWaterContainerOptimal = function (heights) {
  let a1 = 0,
    a2 = heights.length - 1,
    maxArea = 0;

  while (a1 < a2) {
    const height = Math.min(heights[a1], heights[a2]);
    const width = a2 - a1;
    const area = height * width;
    maxArea = Math.max(maxArea, area);

    if (heights[a1] <= heights[a2]) {
      a1++;
    } else {
      a2--;
    }
  }

  console.log("Max water container can contain (optimal) - ", maxArea);
  return maxArea;
};

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

console.log("Your heights array - ", array);

// Call the algorithm
getMaxWaterContainerBrute(array);
getMaxWaterContainerOptimal(array);

/*

> node WaterContainer

Enter array length - 5
Enter 1 element - 4
Enter 2 element - 3
Enter 3 element - 2
Enter 4 element - 1
Enter 5 element - 4
Your heights array -  [ 4, 3, 2, 1, 4 ]
Max water container can contain (Brute) -  16
Max water container can contain (optimal) -  16

*/

