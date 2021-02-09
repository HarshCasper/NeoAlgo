//(Map)
//It will basically create a new array from an existing array applying the method to each member of the array

const numbers = [1, 2, 3, 4];
const doubled = numbers.map(item => item * 2);
console.log(doubled);
//Output: [2, 4, 6, 8]

const numbers = [1, 2, 3, 4];
const sub = numbers.filter(item => item - 2);
console.log(sub);
//Output: [-1, 0, 1, 2]
