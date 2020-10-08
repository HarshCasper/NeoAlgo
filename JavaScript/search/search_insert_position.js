/*
 * Date: 08/10/2020
 *
 * Summary: Implement search insert position algorithm in Javascript
 */

const array = [1, 2, 5, 6, 9];
// It works just if the list is already sorted;
function search_insert_position(array, value) {
  // our target
  let index = 0;
  const valueIndex = array.findIndex((num) => num === value);
  if (valueIndex !== -1) {
    index = valueIndex;
    return index;
  }
  for (const element of array) {
    if (element > value) {
      break;
    }
    index++;
  }
  return index;
}

/*
 *   @Test
 *   output expected: 'false'
 */
function element_do_not_exists_test() {
  var numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  var target = 14;
  console.log(search_insert_position(numbers, target));
}

/*
 *   @Test
 *   output expected: 'true'
 */
function element_exists_test() {
  var numbers = [1, 2, 3, 6, 9, 10];
  var target = 3;
  console.log(search_insert_position(numbers, target));
}

// Entry point of the application for testing purposes
element_do_not_exists_test();
element_exists_test();
