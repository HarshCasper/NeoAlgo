/*
Description:
the sieve of Eratosthenes is an ancient algorithm for finding all prime numbers 
up to any given limit. It does so by iteratively marking as composite (i.e., not prime)
the multiples of each prime, starting with the first prime number, 2. ... It may be 
used to find primes in arithmetic progressions.

Given a number n, print all primes smaller than or equal to n. It is also given 
that n is a small number.
*/

// Java Script code:


(function (exports) {
    'use strict';
   
    exports.sieveOfEratosthenes = function (limit) {
      var sieve = [];
      var primes = [];
      var k;
      var l;
      sieve[1] = false;
      for (k = 2; k <= limit; k += 1) {
        sieve[k] = true;
      }
      for (k = 2; k * k <= limit; k += 1) {
        if (sieve[k] !== true) {
          continue;
        }
        for (l = k * k; l <= limit; l += k) {
          sieve[l] = false;
        }
      }
      sieve.forEach(function (value, key) {
        if (value) {
          this.push(key);
        }
      }, primes);
      return primes;
    };
  }(typeof exports === 'undefined' ? window : exports));
  


// TIME COMPLEXITY: O(n*log(log(n)))
// SPACE COMPLEXITY: O(n)

// TEST CASE 1:
// Enter the range: 50
// 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

// TEST CASE 2:
// Enter the range: 100
// 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
