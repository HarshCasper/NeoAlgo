
/*Given two sorted arrays nums1 and nums2 of size m and n 
respectively, return the median of the two sorted arrays.*/
 

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
var size1 = prompt("Enter size of first array: ");
var size2 = prompt("Enter size of second array: ");
var arr1 = new Array[size1];
var arr2 = new Array[size2];
prompt("Enter elements in first array: ")
for(var i = 0;i<size1;i++){
    arr1[i] = prompt();
}
prompt("Enter elements in second array: ")
for(var i = 0;i<size2;i++){
    arr2[i] = prompt();
}
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

