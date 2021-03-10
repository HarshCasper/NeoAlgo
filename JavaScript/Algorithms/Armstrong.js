
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
// Input 321
// Output:- 371 is an Armstrong number.
// Explanation 3*3*3+7*7*7+1*1*1 = 371
