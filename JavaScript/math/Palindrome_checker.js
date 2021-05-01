/*
Write a program to check whether a given number is palindrome or not.
Palindrome is a number which reads the same backward as forward.
*/

//In-Built readline module
const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const getLine = (function () {
  const getLineGen = (async function* () {
    for await (const line of rl) {
      yield line;
    }
  })();
  return async () => (await getLineGen.next()).value;
})();

function palindromechecker(no) {
  let temp = no;
  let reverse = 0;

  //To reverse the number
  while (temp !== 0) {
    reverse = reverse * 10 + (temp % 10);
    temp = parseInt(temp / 10);
  }

  if (no === reverse) console.log("Entered Number is a Palindrome");
  else console.log("Entered Number is not a Palindrome");
}

const main = async () => {
  //Taking Input of Number
  console.log("Enter the Number");
  var no = Number(await getLine());

  //Calling palindrome checker function
  palindromechecker(no);

  //To close the program
  process.exit(0);
};

main();

/*

Time Complexity: O(N)
Space Complexity: O(1)

Input 1:
1234321

Output 1:
Entered Number is a Palindrome

Input 2:
12345

Output 2:
Entered Number is not a Palindrome

*/
