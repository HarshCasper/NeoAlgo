/*
 *   Algorithm: Linear Search
 *   Author: Davide Pollicino (@omonimus1)
 *   Date: 25/06/2020
 *   Last Modified by: Davide Pollicino (@omonimus1) 26/06/2020
 *
 *	Linear search: compare every element for the beginning to the en
 *   with our target (element to find). It returns true if the target * is found, false otherwise
 */

/*
 *   Search in a list a target using linear search algorithm
 */
function linear_search(arr, target) {
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] == target) return "Found";
  }
  return "Not Found";
}

/*
 *	@Test : Search an element that exists in the list
 *   Output expected: Found
 */
function linear_search_pass_test() {
  var test1 = [1, 2, 3, 4, 5, 6, 7];
  console.log(linear_search(test1, 6));
}

/*
 *	@Test : Search an element that do not exists in the list
 *   Output expected: 'Not Found'
 */
function linear_search_failure_test() {
  var test1 = [1, 2, 4, 5];
  console.log(linear_search(test1, 9));
}

// Entry file of the js application
linear_search_pass_test();
linear_search_failure_test();
