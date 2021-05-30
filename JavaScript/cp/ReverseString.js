/*

Given a string A. Return the string A after reversing the string word by word.
Below is the implementation of program in 3 different ways -
1. Iterative
2. Built-In functions
3. Recursive

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Iterative method
function ReverseStringIterative(str) {
  let arrayString = str.split("");
  let reversedArray = [];

  function addToArray(array) {
    if (array.length > 0) {
      reversedArray.push(array.pop()); // pop the element from array & push it in the reversedArray array
      addToArray(array);
    }

    return;
  }

  // Pass array of strings
  addToArray(arrayString);
  console.log("Reverse String Iterative - ", reversedArray.join(""));
  return reversedArray.join("");
}

// Using in-built methods of JavaScript
function ReverseString(str) {
  str = str === "" ? "" : str.split("").reverse().join("");
  console.log("Reverse String - ", str);
  return str;
}

// Recursive approach
function ReverseStringRecursive(str) {
  if (str === "") {
    return "";
  } else {
    return ReverseStringRecursive(str.substr(1)) + str.charAt(0);
  }
}

// Get the user input
let string = prompt("Enter String to reverse - ");

// Call the algorithm
ReverseStringIterative(string);
ReverseString(string);

// Call the recursive algorithm
let result = ReverseStringRecursive(string);
console.log("Reverse String Recursive - ", result);

/*

> node ReverseString

Enter String to reverse - node
Reverse String Iterative -  edon
Reverse String -  edon
Reverse String Recursive -  edon

*/


