/* Description :
     The idea of Radix Sort is to do digit by digit sort starting from least significant 
     digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.
*/

/* JAVA SCRIPT CODE */

(function (exports) {
  'use strict';
  var radixSort = (function () {

    var getDigit = function (number, lsdOffset) {
      var size = number.toString().length;
      var digit;
      if (lsdOffset >= 0 && lsdOffset < size) {
        digit = number.toString()[size - 1 - lsdOffset];
      }
      return digit;
    };
    
    return function (array) {
      var size = array.length;
      var R = 10;   /* Alphabet size ([0-9] for integers) */
      var count;
      var digit;
      var i;
      var j;
      /* Find maximum key size */
      var maxKeySize = (array[0] || '').toString().length;
      for (i = 1; i < size; i += 1) {
        var numStr = array[i].toString();
        if (numStr.length > maxKeySize) {
          maxKeySize = numStr.length;
        }
      }
      for (i = 0; i < maxKeySize; i += 1) {
        /* Initialize count */
        count = [];
        for (j = 0; j < R; j += 1) {
          count[j] = 0;
        }
        /* Count frequency of each array element */
        for (j = 0; j < size; j += 1) {
          digit = getDigit(array[j], i) || 0;
          count[digit] += 1;
        }
        /* Compute cumulates */
        for (j = 1; j < R; j += 1) {
          count[j] += count[j - 1];
        }
        /* Move elements to auxiliary array */
        var aux = [];
        for (j = size - 1; j >= 0; j -= 1) {
          digit = getDigit(array[j], i) || 0;
          count[digit] -= 1;
          aux[count[digit]] = array[j];
        }
        /* Copy elements back from auxilary array */
        for (j = 0; j < size; j += 1) {
          array[j] = aux[j];
        }
      }
      return array;
    };
  })();
  exports.radixSort = radixSort;
})(typeof window === 'undefined' ? module.exports : window);


/*
Test Case 1: 

Unsorted list:
170, 45, 75, 90, 802, 24, 2, 66

Output:
2, 24, 45, 66, 75, 90, 170, 802

Test Case 2:

Unsorted list:
573, 25, 415, 12, 161, 6

Ouput:
6 12 25 161 415 573

Time Complexity : O(n)
Space Complexity : O(n)
*/
