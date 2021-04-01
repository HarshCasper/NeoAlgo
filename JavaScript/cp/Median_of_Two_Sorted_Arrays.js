
/*Given two sorted arrays nums1 and nums2 of size m and n 
respectively, return the median of the two sorted arrays.*/
 
 // Prompt node package for taking user input
const prompt = require("prompt-sync")({ sigint: true });


var findMedianSortedArrays = function(nums1, nums2) {
    //concatenate and sort the arrays
  let nums3 = nums1.concat(nums2).sort(function(a, b){return a-b});
    var mid;
    //checking if the length of array is even
    if(nums3.length % 2 !== 0) {
        //return the mid element
        mid = nums3[nums3.length / 2>>0];
        return mid;
    } 
    //if length is odd return the median of two elements
    else {
        var first = nums3[nums3.length / 2>>0];
        var second = nums3[(nums3.length / 2 >> 0 )-1];
        mid =  first + second;
        return( mid ) / 2;
    }
};
let size1 = +prompt("Enter array 1 length:  ");
let size2 = +prompt("Enter array 2 length:  ");

let arr1 = [];
let arr2 = [];

// Take array items
for (let i = 1; i <= size1; i++) {
  arr1.push(+prompt(`Enter ${i} element - `));

for (let i = 1; i <= size2; i++) {
  arr2.push(+prompt(`Enter ${i} element - `));
console.log(findMedianSortedArrays(arr1,arr2));
/*
Time complexity: O(n)
Space complexity: O(n)

Example 1:

Input:
[1,3]
[2]

Output:
2.00000

Example 2:

Input:
[1,5,7,8,9]
[2,4,4]

Output:
4.50000

*/

