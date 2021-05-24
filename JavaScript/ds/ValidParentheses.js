/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    1) Open brackets must be closed by the same type of brackets.
    2) Open brackets must be closed in the correct order.

Time Complexity - O(n)
    
*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Object with respective brackets pairs
const paris = {
  "(": ")",
  "{": "}",
  "[": "]",
};

// Check if string is valid or not
const isValid = (string) => {
  if (string.length === 0) return false;

  const stack = []; // Create stack

  for (let x = 0; x < string.length; x++) {
    if (paris[string[x]]) {
      stack.push(string[x]); // if character exists , push it into the stack
    } else {
      const leftBracket = stack.pop(); // get the top most bracket from stack
      const correctBracket = paris[leftBracket]; // get the right bracket of the left bracket
      if (string[x] !== correctBracket) return false; // return if they don't match
    }
  }

  return stack.length === 0;
};

// Take string as input
let string = prompt("Enter first string  - ");

// Call the algortihm
let isValidString = isValid(string);

if (isValidString) console.log("It's valid");
else console.log("It's not valid");

/*

> node ValidParentheses

1) Enter first string  - {()[]}
It's valid

2) Enter first string  - {)
It's not valid

*/

