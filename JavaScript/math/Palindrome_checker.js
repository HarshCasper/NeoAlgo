/*
Write a program to check whether a given number is palindrome or not.
Palindrome is a number which reads the same backward as forward.
*/

// take input from the user
let no = parseInt(prompt('Enter a no which needs to be checked for palindrome: '));

let temp = no;
let reverse=0;

//To reverse the number
while(temp!==0)
{
    reverse=reverse*10+temp%10;
    temp=parseInt(temp/10);
}

if(no===reverse)console.log("Entered Number is a Palindrome");
else console.log("Entered Number is not a Palindrome");

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