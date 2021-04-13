/*

A neon number is a number where the sum of digits of the square of the number is equal to the number.
Below is the implementation to check whether the given number is Neon number or not. 

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
    return console.log("CheckNeonLoop result - Neon number!");
  return console.log("CheckNeonLoop result - Not a Neon number");
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
  if (getSum === number) return console.log("CheckNeon result - Neon number!");
  return console.log("CheckNeon result - Not a Neon number");
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

node NeonNumber

Enter a number - 12
CheckNeon result - Not a Neon number
CheckNeonLoop result - Not a Neon number

Enter a number - 9
CheckNeon result - Neon number!
CheckNeonLoop result - Neon number!

*/


