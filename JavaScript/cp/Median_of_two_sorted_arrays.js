
/*Given two sorted arrays nums1 and nums2 of size m and n 
respectively, return the median of the two sorted arrays.*/

//function to find median of sorted arrays
var findMedianSortedArrays = function(arr1, arr2) {
    //concatenate and sort the arrays
  let arr3 = arr1.concat(arr2).sort(function(a, b){return a-b});
    var mid;
    //checking if the length of array is even
    if(arr3.length % 2 !== 0) {
        //return the mid element
        mid = arr3[arr3.length / 2>>0];
        return mid;
    } 
    //if length is odd return the median of two elements
    else {
        var first = arr3[arr3.length / 2>>0];
        var second = arr3[(arr3.length / 2 >> 0 )-1];
        mid =  first + second;
        return( mid ) / 2;
    }
};


var inputArray1 = [];
var inputArray2 = [];
var size = prompt("enter size: ");
var size1 = prompt("enter size: ");//Maximum Array size

for(var i=0; i<size; i++) {
	
	//Taking Input from user
	inputArray1[i] = prompt((i+1));
}
for(var i=0; i<size1; i++) {
	
	//Taking Input from user
	inputArray2[i] = prompt((i+1));
}

console.log(findMedianSortedArrays(inputArray1,inputArray2));
/*
Time complexity: O(n)
Space complexity: O(n)

Example 1:
Input:
2 1
1 3
2
Output:
2.00000

Example 2:
Input:
5 3
1 5 7 8 9
2 4 4
Output:
4.50000

*/
