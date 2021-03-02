/*
In this algorithm we keep halving one number and doubling the 2nd one.
While halving, if we get an odd number, we add the 2nd doubled number to the result.
This goes on until the halving makes the first reach 0
It is also known as the Ancient Egyptian Multiplication, used by scribes to do multiplication
without using the multiplication table.
 */

const findProduct = (num1, num2) => {
  if (typeof num1 != "number" || typeof num2 != "number") {
    return "N/A";
  }

  let result = 0;

  // running the loop as long as 2nd number is greater than 0
  while (num2 > 0) {
    // if 2nd becomes odd, we add whatever value of num1
    // we have to result
    if ((num2 & 1) !== 0) {
      result += num1;
    }

    // double first and halve the second
    num1 = num1 << 1;
    num2 = num2 >> 1;
  }

  return result;
};

var product1 = findProduct(1328, 596);
var product2 = findProduct("hello", 96);
console.log("Product 1:" + product1);
console.log("Product 2:" + product2);

/*
Output for above sample input:
Product 1:791488
Product 2:N/A
Time complexity = O(1)
*/
