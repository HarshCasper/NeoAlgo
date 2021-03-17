
// In this program we will check whether a number is an Armstrong number 
// An Armstrong number is a three-digit number in which 
// the sum of the cube of the digits is equal to the number itself. 
// Hence 153 is an Armstrong number -> 1^3 + 5^3 + 3^3 = 153


process.stdin.setEncoding("utf-8");
var str = "";
process.stdin.on("data", (data) => {
  str += data;
});
process.stdin.on("end", () => {
  str = str.split("\n");
  var number = str[0];
  var temp = number;
  var answer = 0;
  var rem = 0;
  var n = 0;
  while (temp != 0) {
    temp = Math.floor(temp / 10);
    n++;
  }

  temp = number;

  while (temp != 0) {
    rem = Math.floor(temp % 10);
    answer = answer + Math.pow(rem, n);
    temp = Math.floor(temp / 10);
  }

  if (answer == number)
    console.log(number + " is an Armstrong number.");
  else
    console.log(number + " is not an Armstrong number.");

});
// Example
// Input: 371
// Output: 371 is an Armstrong number.
// Explanation 3*3*3+7*7*7+1*1*1 = 371

// Example
// Input: 321
// Output: 321 is not an Armstrong number.
// Explanation 3*3*3+2*2*2+1*1*1 = 44

// Example
// Input: 4321
// Output: 4321 is not an Armstrong number.
// Explanation 4*4*4*4+3*3*3*3+2*2*2*2+1*1*1*1 = 354

// Example
// Input: 1634
// Output: 1634 is an Armstrong number.
// Explanation 1*1*1*1+6*6*6*6+3*3*3*3+4*4*4*4 = 1634

// Example
// Input: 0
// Output: 0 is an Armstrong number.
// Explanation 0 = 0

