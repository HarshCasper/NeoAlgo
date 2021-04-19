/*
Perfect number is a positive integer which is equal to the sum of its proper positive divisors.
For example: 6 is the first perfect number
Proper divisors of 6 are 1, 2, 3
Sum of its proper divisors = 1 + 2 + 3 = 6.
Hence 6 is a perfect number.
*/

const prompt = require("prompt-sync")({ sigint: true });
let n = +prompt("Enter a number to check whether it is a perfect number or not: ");
let sum = 0;

for (let i = 1; i < n; i++) 
{
    if (n % i == 0) 
        sum += i;
}

if (sum == n) 
    console.log(`${n} is a perfect number.`);
else 
    console.log(`${n} is not a perfect number.`);

/*

Time Complexity: O(n)
Space Complexity: O(1)

node JavaScript/math/Perfect_Number.js

sample 1: Enter a number to check whether it is a perfect number or not: 6
Output: 6 is a perfect number.

sample 2: Enter a number to check whether it is a perfect number or not: 7
output: 7 is not a perfect number.

*/
