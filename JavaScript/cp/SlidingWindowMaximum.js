/* Sliding Window Maximum is a famous problem where we are given a list of integers
 nums and an integer k, return the maximum values of each sublist of length k. */


/* Function to get the maximum element of each sliding window of size k */
const slidingWindowMaximum = (nums, k) => {

    /* Sliding window */
    let window = [];

    /* Generating the initial window */
    for(let i=0; i<k; i++){
        
        /* Pushing the index to the window if there are no elements */
        if(window.length == 0){
            window.push(i);
            continue;
        }

        /* Getting the last index of our sliding window */
        let index = window[window.length-1];

        /* Arranging the elements in the window in descending order by removing the smaller ones */
        while(nums[i] > nums[index] && window.length > 0){
            window.pop();
            if(window.length > 0)
            index = window[window.length-1];
        }

        /* Pushing the current element to the window */
        window.push(i);
    }

    /* Answer array */
    let array = [];

    /* Storing the first maximum element in the array */
    array[0] = nums[window[0]];

    /* Generating k-1 windows */
    for(let i=k; i<nums.length; i++){

        let index = window[0];

        /* Removing indices which are out of bound */
        while(index <= i-k && window.length > 0){
            window.shift();
            if(window.length > 0)
            index = window[0];
        }

        if(window.length > 0)
        index = window[window.length-1];

        /* Arranging the elements in the window in ascending order by removing the ones which are smaller */
        while(nums[i] > nums[index] && window.length > 0){
            window.pop();
            if(window.length > 0)
            index = window[window.length-1];
        }

        window.push(i);

        /* Pushing the new maximum to the array */
        array[i-k+1] = nums[window[0]];
    }

    /* Returning the answer */
    return array;
}

//Using the readline() function of JavaScript to take input from the user
console.log("Enter the elements of of the array along with the size of the window");

//list is input array
let list = readline()
    .split(" ")
    .map((x) => parseInt(x));

// First n elements represent the elements in the array
let n = list.length-1;

// Last element of the list represents the size of the window k
let k = list[n];

/* Using list slicing and passing the first n elements to the
 function as the first parameter and k as the second parameter */
console.log("Array of maximum element in every window of size ", k, " is" ,slidingWindowMaximum(list.slice(0, n), k));

/* 
Example 1:

Input:

3 2 1 2 3 2

Output:

Array of maximum element in every window of size 2 is [3, 2, 2, 3]

Time Complexity : O(N)
Space Complexity : O(K)
*/

