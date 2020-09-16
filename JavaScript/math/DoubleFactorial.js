/*
Double factorial of a non-negative integer n, is the product
of all the integers from 1 to n that have the same parity (odd or even) as n.
It is also called as semifactorial of a number and is denoted by !!
*/
// Time complexity for both the approaches(Iterative and Recursive) is O(n)

// Iterative approach
DoubleFactIter = (num) => {
  let ans = 1;
  for (let i = num; i >= 0; i -= 2) {
    // checking for 1 and 0
    if (i <= 1) return ans;
    else ans *= i;
  }
};

// Recursive approach
DoubleFactRecur = (num) => {
  // checking for 1 and 0
  if (num <= 1) return 1;
  // Recursively calling Function
  else return num * DoubleFactRecur(num - 2);
};

console.log(DoubleFactIter(0)); // 1
console.log(DoubleFactRecur(0)); // 1

console.log(DoubleFactIter(1)); // 1
console.log(DoubleFactRecur(1)); // 1

console.log(DoubleFactIter(2)); // 2
console.log(DoubleFactRecur(2)); // 2

console.log(DoubleFactIter(3)); // 3
console.log(DoubleFactRecur(3)); // 3

console.log(DoubleFactIter(4)); // 4
console.log(DoubleFactRecur(4)); // 4

console.log(DoubleFactIter(9)); // 945
console.log(DoubleFactRecur(13)); // 135135
