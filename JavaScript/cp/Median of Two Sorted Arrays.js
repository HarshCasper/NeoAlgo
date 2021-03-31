
/*Given two sorted arrays nums1 and nums2 of size m and n 
respectively, return the median of the two sorted arrays.*/
 

var findMedianSortedArrays = function(nums1, nums2) {
 //checking the length of num1
  if(nums1.length==0) {
    return arrayMedian(nums2);
  }
    //checking the length of num2
  if(nums2.length==0) {
    return arrayMedian(nums1);
  }
  //recurring function
  return findMedian(nums1, 0, nums1.length-1,
                   nums2, 0, nums2.length-1,
                   Math.floor((nums1.length+nums2.length)/2)); 
  
  function arrayMedian(arr) {
      //checking the length of arr
    if(arr.length==0)
      return 0;
      //if length of arr is even return the mid element
    if(arr.length%2)
      return arr[Math.floor(arr.length/2)];
      //else return median of 2 mid elements
    return (arr[arr.length/2]+arr[arr.length/2-1])/2;
  }
  function safeGet(ary,idx) {
    if(idx>=0&&idx<ary.length)
      return ary[idx];
    return Number.MIN_VALUE;
  }
  
  function computeIndex(baseAry, baseBegin, baseEnd,
                     baseIndex,
                     otherAry, otherBegin, otherEnd) {
      //call the findInsertionPoint function
    var range = findInsertionPoint(
      otherAry, otherBegin, otherEnd,
      baseAry[baseIndex]);
    
    return {globalIndex: range[0]+1+baseIndex,
            index0: range[0],
            index1: range[1]}
  }
  
  function findInsertionPoint(nums, begin, end, v) {
    var L = begin
      , R = end
      , M;
      //if begin element is less than end element
    while(L<=R) {
        //store mid value in M
      M = Math.floor((L+R)/2);
      if(nums[M] == v)
        return [M,M+1];
      if(nums[M] < v)
        L = M+1;
      else
        R = M-1;
    }
    
    return [R,L];
  }
  //function to find median element
  function findMedian(
     nums1, begin1, end1,
     nums2, begin2, end2,
      targetIndex
  ) {
       var queryIndex = Math.floor((begin1+end1)/2);
       var result = computeIndex(nums1, begin1, end1, 
                 queryIndex,
                 nums2, begin2, end2);
       if(result.globalIndex == targetIndex) {
         if((nums1.length+nums2.length)%2) {
           return nums1[queryIndex];
         }
         
         var anotherMedian = Math.max(
           safeGet(nums1, queryIndex-1),
           safeGet(nums2, result.index0)
         );
         //return the answer
         return (nums1[queryIndex]+anotherMedian)/2;
       }
       
       if(targetIndex < result.globalIndex) {
         return findMedian(
           nums2, begin2, result.index0,           
           nums1, begin1, queryIndex-1,
           targetIndex
         )
       }
       
       return findMedian(
         nums2, result.index1, end2,
         nums1, queryIndex+1, end1,
         targetIndex
       )
     }
};
/*
Time complexity: O(log(m+n))
Space complexity: O(n*n)

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

