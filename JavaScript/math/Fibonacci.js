/*

In mathematics, the Fibonacci numbers, commonly denoted Fn, form a sequence, called the Fibonacci sequence,
such that each number is the sum of the two preceding ones, starting from 0 and 1

Fibonacci Series - 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ....
Below is the program for implementing fibonacci series in 3 different ways 

*/

// Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });

// Number of steps required to complete fora given fibonacci function
let iterativeCount = 0; // iterative function count
let recursiveCount = 0; // recursive function count
let memoizedCount = 0; // memoized function count

// Iterative function ( Looping )
function fibonacciIterative(n) {
  let array = [0, 1];

  for (let i = 2; i < n + 1; i++) {
    iterativeCount++;
    array.push(array[i - 2] + array[i - 1]);
  }

  return array[n];
}

// Recursive function
function fibonacciRecursive(n) {
  recursiveCount++;
  if (n < 2) {
    return n;
  }

  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Memoization ( a technique which attempts to increase function's performance by caching its previously computed results)
function fibonacciMemoized() {
  let cache = {}; // store previously computed results

  return function fib(n) {
    memoizedCount++;
    if (n in cache) {
      return cache[n];
    } else {
      if (n < 2) {
        return n;
      } else {
        cache[n] = fib(n - 1) + fib(n - 2);
        return cache[n];
      }
    }
  };
}

/* Workflow of user input */

// Take the fibonacci number as input
let fibKey = +prompt("Enter number to find fibonacci series value - ");

// Check whether the entered value is number or not
if (isNaN(fibKey)) return console.log("Only numbers are allowed");

// Iterative Result
let result = fibonacciIterative(fibKey);
console.log(
  `Fibonacci Iterative result in ${iterativeCount} steps - ${result}`
);

// Memoization Result
let fasterFib = fibonacciMemoized(fibKey);
result = fasterFib(fibKey);
console.log(`Fibonacci Memoized result in ${memoizedCount} steps - ${result}`);

// Recursive Result
result = fibonacciRecursive(fibKey);
console.log(
  `Fibonacci Recursive result in ${recursiveCount} steps - ${result}`
);

// Sample I/O

/*

> node Fibonacci

Enter number to find fibonacci series value - 25
Fibonacci Iterative result in 24 steps - 75025
Fibonacci Memoized result in 49 steps - 75025
Fibonacci Recursive result in 242785 steps - 75025

*/

