/*

A happy number is a number which will yield 1 when it is replaced by the sume of the square of its digits repeatedly.
If the process results in and endless cycles of numbers containing 4, then the number is an unhappy number

Below is the implementation of program with 3 different approaches - 1. Using builtIn methods
                                                                     2. Using single loop + recursion
                                                                     3. Using loops i.e without recursion 
Time Complexity - O(log n)

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Using Built-in methods
function happyNumber(number) {
  // Check if it is 4 ( as it will produce an endless loop )
  if (number === 4)
    return console.log("Using built-in methods - Not a happy number");

  // Ge the digits
  let digits = number.toString().split("");
  let sum = digits.reduce((acc, rem) => acc + rem ** 2, 0); // Get the sum

  // Check if it is happy
  if (sum === 1) return console.log("Using built-in methods - Happy Number");
  else happyNumber(sum); // else pass the sum to algorithm
}

// Using recursion + loop
function happyNumberLoop(number) {
  // Check the endless condition, if so, return
  if (number === 4) return console.log("Using Loop - Not a Happy Number");
  let isHappy = 0;

  // Get the digits & add them to isHappy
  while (number !== 0) {
    let rem = number % 10;
    isHappy += rem ** 2; // Stores the sum of digit
    number = Math.floor(number / 10);
  }

  // Check if it is happy, if so, return happy
  if (isHappy === 1) return console.log("Using Loop - Happy Number");
  else happyNumberLoop(isHappy); // Else pass the obtained sum to same function
}

// Without recursion
function happyNumberWithoutRecursion(number) {
  // An endless condition
  while (true) {
    let isHappy = 0;

    // Get the digits & store sum in isHappy
    while (number !== 0) {
      let rem = number % 10;
      isHappy += rem ** 2;
      number = Math.floor(number / 10);
    }

    // if it is a match, return happy
    if (isHappy === 1) return console.log("Without Recursion - Happy Number");

    // If endless condition, return false
    if (isHappy === 4)
      return console.log("Without Recursion - Not a happy number");

    // Change number to the sum gained
    number = isHappy;
  }
}

let number = +prompt("Enter a number - ");

// Check whether the entered value is number or not
if (isNaN(number)) return console.log("Only numbers are allowed");

// Check if the input number is negative
if (Math.sign(number) === -1) return console.log("Not a neon number");

// call the algorithm
happyNumber(number); // built-in
happyNumberLoop(number); // loop & recursion
happyNumberWithoutRecursion(number); // without recursion

/*

> node HappyNumber

Enter a number - 19
Using built-in methods - Happy Number
Using Loop - Happy Number
Without Recursion - Happy Number

Enter a number - 9
Using built-in methods - Not a happy number
Using Loop - Not a Happy Number
Without Recursion - Not a happy number

*/

