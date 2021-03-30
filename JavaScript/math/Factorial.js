/*
Write a program to calculate the factorial of given no. The factorial of a non-negative integer n, 
denoted by n!, is the product of all positive integers less than or equal to n.
*/

// take input from the user
let no = parseInt(prompt('Enter a no whose factorial needs to be calculated: '));

// checking if number is negative
if (no < 0) {
    console.log('No is negative');
}
// if number is positive or zero
else {
    let fact = 1;
    for (i = 1; i <= no; i++) {
        fact *= i;
    }
    console.log(`The factorial of ${no} is ${fact}.`);
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

Input 1:
5
Output 1:
120

Input 2:
4

Output 2:
24

*/