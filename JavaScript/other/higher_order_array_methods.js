

//(Map)
//It will basically create a new array from an existing array applying the method to each member of the array

const numbers = [1, 2, 3, 4];
const doubled = numbers.map(item => item * 2);
console.log(doubled); // [2, 4, 6, 8]


//(Filter)
//The filter() method takes each element in an array and it applies a conditional statement against it.If this conditional returns true, the element gets pushed to the output array. If the condition returns false, the element does not get pushed to the output array.

//Example-1
const numbers = [1, 2, 3, 4];
const evens = numbers.filter(item => item % 2 === 0);
console.log(evens); // [2, 4]

//Example-2
const students = [
    { name: 'Quincy', grade: 96 },
    { name: 'Jason', grade: 84 },
    { name: 'Alexis', grade: 100 },
    { name: 'Sam', grade: 65 },
    { name: 'Katie', grade: 90 }
];

const studentGrades = students.filter(student => student.grade >= 90);
return studentGrades; // [ { name: 'Quincy', grade: 96 }, { name: 'Alexis', grade: 100 }, { name: 'Katie', grade: 90 } ]

//(Reduce)
//reduce() is used to transform an array of strings into a single object that shows how many times each string appears in the array. 

//Example-1(Finding sum using reduce())
const numbers = [1, 2, 3, 4];
const sum = numbers.reduce(function (result, item) {
    return result + item;
}, 0);
console.log(sum); // 10

//Example-2(Finding out pet counts using reduce())
var pets = ['dog', 'chicken', 'cat', 'dog', 'chicken', 'chicken', 'rabbit'];

var petCounts = pets.reduce(function (obj, pet) {
    if (!obj[pet]) {
        obj[pet] = 1;
    } else {
        obj[pet]++;
    }
    return obj;
}, {});

console.log(petCounts);

/*
Output:
 { 
    dog: 2, 
    chicken: 3, 
    cat: 1, 
    rabbit: 1 
 }
 */

//Sort
// sort() as the name suggests basically sorts in ascending or descending order
let numbers = [15, 2, 50, 55, 90, 5, 4, 9, 10];
console.log(numbers.sort((num1, num2) => num1 - num2)); // Sorting numbers in accending order => result is [2, 4, 5, 9, 10, 15, 50, 55, 90]


// Chaining all above four functions(Map, Sort, Filter and Reduce funtions)
let numbers = [15, 2, 50, 55, 90, 5, 4, 9, 10];
let initialValue = 5;
const result = numbers
    .map(number => number * 2)  // [30, 4, 100, 110, 180, 10, 8, 18, 20]// 
    .sort((num1, num2) => num1 - num2) // [4, 8, 10, 18, 20, 30, 100, 110, 180]
    .filter(number => number > 20) // [30, 100, 110, 180]
    .reduce((total, number) => total + number, initialValue); //425

console.log(result); // Answer is 425