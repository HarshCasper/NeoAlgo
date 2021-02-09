//(Reduce)
/*reduce() is used to transform an array of strings into a single object 
that shows how many times each string appears in the array.*/

//Example-1(Finding sum using reduce())
const numbers = [1, 2, 3, 4];
const sum = numbers.reduce(function (result, item) {
    return result + item;
}, 0);
console.log(sum);
//Output: 10

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
