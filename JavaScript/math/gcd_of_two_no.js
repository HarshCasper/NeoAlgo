/*
A program to find Greatest Common Divisor(GCD) of two Numbers.
GCD of two integers is the largest positive integer that divides each of the integers.
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

function gcd(number1, number2) {
  //Smaller of the two number
  var smaller_number = Math.min(number1, number2);

  //Iterating from smaller number till 1
  for (var i = smaller_number; i >= 1; i--) {
    if (number1 % i == 0 && number2 % i == 0) {
      console.log("HCF: " + i);
      break;
    }
  }
}

const main = async () => {
  //Taking Input of First Number
  console.log("Enter the First Number");
  var number1 = Number(await getLine());

  //Taking Input of Second Number
  console.log("Enter the Second Number");
  var number2 = Number(await getLine());

  //Calling gcd function
  gcd(number1, number2);

  //To close the program
  process.exit(0);
};

main();

/*

Time Complexity:O(smaller(n1,n2))
Space Complexity:O(1)

Input:
5 10

Output:
5

Input:
4 7

Output:
1

*/
