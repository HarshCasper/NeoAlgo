/*
Description:
Shellsort, also known as Shell sort or Shell's method, is an in-place comparison sort.
It can be seen as either a generalization of sorting by exchange or sorting by insertion.
The method starts by sorting pairs of elements far apart from each other, then 
progressively reducing the gap between elements to be compared.

The idea of shellSort is to allow exchange of far items. In shellSort, we make the array h-sorted 
for a large value of h. We keep reducing the value of h until it becomes 1. An array is said to be 
h-sorted if all sublists of every h’th element is sorted.
*/

// Java Script Code:

(function (exports) {
    'use strict';
    function compare(a, b) {
      return a - b;
    }

    var shellSort = (function () {
      var gaps = [701, 301, 132, 57, 23, 10, 4, 1];
      /*
       * insertion sort to sort sub-arrays which match for the different gaps.
      */

      return function (array, cmp) {
        cmp = cmp || compare;
        var gap;
        var current;
        for (var k = 0; k < gaps.length; k += 1) {
          gap = gaps[k];
          for (var i = gap; i < array.length; i += gap) {
            current = array[i];
            for (var j = i;
                j >= gap && cmp(array[j - gap], current) > 0; j -= gap) {
              array[j] = array[j - gap];
            }
            array[j] = current;
          }
        }
        return array;
      };
    }());

    exports.shellSort = shellSort;
  }(typeof exports === 'undefined' ? window : exports));


/*

Test Example :

Enter the length of the array: 7
Enter the elements of the array followed by spaces: 7 2 4 9 3 5 1

Sorted array: 1 2 3 4 5 7 9

Time Complexity - O(n^2)
Space Complexity - O(n)

*/