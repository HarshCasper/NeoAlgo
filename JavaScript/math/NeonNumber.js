/*

A neon number is a number where the sum of digits of the square of the number is equal to the number.
Below is the implementation to check whether the given number is Neon number or not. 

Time Complexity - O(log n)
Space Complexity - O(1)

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// using loop
function checkNeonLoop(number) {
  let num = number ** 2; // get the square

  let neon = 0; // store the sum of digits

  // calculat the sum
  while (num !== 0) {
    let rem = num % 10;
    neon += rem;
    num = Math.floor(num / 10);
  }

  // check is neon?
  if (number === neon)
    return console.log("Using Loop result - Neon number!");
  return console.log("Using Loop result - Not a Neon number");
}

// using built-in methods
function checkNeon(number) {
  let num = number ** 2; // get the square

  // convert to string & then create array of strings of digits
  let neon = num.toString().split("");

  // calculate the sum
  let getSum = neon.reduce((acc, item) => {
    return parseInt(item) + acc; // convert string digit to integer
  }, 0);

  // check is neon?
  if (getSum === number) return console.log("Using Built-In methods result - Neon number!");
  return console.log("Using Built-In methods result - Not a Neon number");
}

let number = +prompt("Enter a number - ");

// Check whether the entered value is number or not
if (isNaN(number)) return console.log("Only numbers are allowed");

// Check if the input number is negative
if (Math.sign(number) === -1) return console.log("Not a neon number");

// Call the algorithm
checkNeon(number);
checkNeonLoop(number);

/*

> node NeonNumber

// Example 01
Enter a number - 12
Using Built-In methods result - Not a Neon number
Using Loop result - Not a Neon number

// Example 02
Enter a number - 9
Using Built-In methods result - Neon number!
Using Loop result - Neon number!

*/
