//Sort
// sort() as the name suggests basically sorts in ascending or descending order
let numbers = [15, 2, 50, 55, 90, 5, 4, 9, 10];
console.log(numbers.sort((num1, num2) => num1 - num2));
// Sorting numbers in accending order => result is [2, 4, 5, 9, 10, 15, 50, 55, 90]

// Chaining all above four functions(Map, Sort, Filter and Reduce funtions)
let numbers = [15, 2, 50, 55, 90, 5, 4, 9, 10];
let initialValue = 5;
const result = numbers
    .map(number => number * 2)
    .sort((num1, num2) => num1 - num2)
    .filter(number => number > 20) // 
    .reduce((total, number) => total + number, initialValue); //

console.log(result);

/* Output: [30, 4, 100, 110, 180, 10, 8, 18, 20]
            [4, 8, 10, 18, 20, 30, 100, 110, 180]
            [30, 100, 110, 180]
            425 */
