/* Given an array of integers and a an integer k, we are supposed to return an array 
which contains the first negative integer in every window of size k */

/* Function to calculate the first negative integer in every window of size k */
const firstNegativeIntegerInEveryWindowOfSizeK = (array, k) => {

    let window = [];

    /* Generating the initial window */
    for (let i = 0; i < k; i++) {

        /* Storing the index if it is a negative number */
        if (array[i] < 0) {
            window.push(i);
        }
    }

    /* Answer array */
    let ans = new Array(array.length - k + 1);

    /* Storing the answer if there exists a negative number */
    if (window.length > 0) {
        ans[0] = array[window[0]];
    } else {
        ans[0] = 0;
    }

    /* Generating k-1 windows */
    for (let i = k; i < array.length; i++) {

        /* Removing the indices which are out of bound */
        while (window.length > 0 && window[0] < i - k + 1) {
            window.shift();
        }

        /* Storing the index if it is a negative number */
        if (array[i] < 0) {
            window.push(i);
        }

        if (window.length > 0) {
            ans[i - k + 1] = array[window[0]];
        } else {
            ans[i - k + 1] = 0;
        }

    }

    return ans;
}

//Using the readline() function of JavaScript to take input from the user
console.log("Enter the elements of the array and the length of the window k");

  //list is input array
let list = readline()
    .split(" ")
    .map((x) => parseInt(x));

let n = list.length-1;
let k = list[n];

console.log(firstNegativeIntegerInEveryWindowOfSizeK(list.slice(0, n), k));

/*
Example 1:

Input:

nums = [-8, 2, 3, -6, 10]
k = 2

Output:

[-8, 0, -6, -6]

Example 2:

Input:

nums = [1, 2, 3, 4, 5]
k = 5

Output:
[0]

Time Complexity: O(N)
Space Complexity: O(K)
*/

