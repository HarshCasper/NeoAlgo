/*

Given two strings s and t, return true if they are equal when both are typed into empty text editors.
'#' means a backspace character.

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Create array of characters from the passed string
const createString = function (string) {
  const builtString = [];
  for (let x = 0; x < string.length; x++) {
    if (string[x] !== "#") {
      builtString.push(string[x]);
    } else {
      builtString.pop();
    }
  }

  return builtString;
};

// Compare two provided strings
const backspaceCompare = function (firstString, secondString) {
  const finalFirstString = createString(firstString);
  const finalSecondString = createString(secondString);

  if (finalFirstString.length !== finalSecondString.length) {
    console.log("Strings don't match");
    return false;
  } else {
    for (let x = 0; x < finalFirstString.length; x++) {
      if (finalFirstString[x] !== finalSecondString[x]) {
        console.log("Strings don't match");
        return false;
      }
    }
  }

  console.log("String match");
  return true;
};

// Take strings as input
let string1 = prompt(
  "Enter first string with or without # as a backspace character - "
);
let string2 = prompt(
  "Enter second string with or without # as a backspace character - "
);

// Call the algortihm
backspaceCompare(string1, string2);

/*

> node BackspaceCompare

Enter first string with or without # as a backspace character - a##c
Enter second string with or without # as a backspace character - #a#c
String match

Enter first string with or without # as a backspace character - a#c
Enter second string with or without # as a backspace character - b
Strings don't match

*/

