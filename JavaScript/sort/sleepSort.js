/*
sleepSort -> It is a unique sorting technique in which javascript's  timeout function is used.
To know what timeout function is , refer to this article : https://developer.mozilla.org/en-US/docs/Web/API/WindowOrWorkerGlobalScope/setTimeout

Drawbacks and constraints of sleepSort:
1. Sleepsort technique cannot be used in case of negative numbers, because it prints some unwanted result(unsorted array).
2. It might not be very useful in case of large integers in the array as large integers could cause a long duartion timeout. 
*/

let numbers = [10,50,3,7,1,75]
numbers.forEach(num => {
  setTimeout(() => {console.log(num)}, num)     // Here creating timeout of duration  = element of array 
});

// Output : 1 3 7 10 50 75

// Above code prints an unwamted result when array contains both 0 and 1 as its elemnnts, i.e. 1 gets printed before 0 which is an unsorted condition, but to prevent this we can multiply the timeout with some constant e.g. 2*num or 3*num, but this can cause large timeout for some large elements of the array.

let numbers2 = [10,50,3,7,1,75,0]
numbers2.forEach(num => {
  setTimeout(() => {console.log(num)}, 2*num)     // Here creating timeout of duration  = 2 * element of array 
});

// Output : 0 1 3 7 10 50 75
