/*
*	Author: Davide Pollicino (@omonimus)
* Date: 26/06/2020
* 
* Summary: Implement binary search algorithm in Javascript
*/


// Search an element in using Binary Search algorithm O(log n) time;
// It works just if the list is already sorted;
function binary_search(arr, target){
	// Define left and right index of the range where to search
  // our target
    let start=0, end=arr.length-1; 
          
    // Iterate while start not meets end 
    while (start<=end){ 
  
        // Get middle index 
        let middle=Math.floor((start + end)/2); 
   
        // If element is present at middle return True 
        if (arr[middle]===target) return true; 
  
        // Else look in left or right half accordingly 
        else if (arr[middle] < target)  
             start = middle + 1; 
        else
             end = middle - 1; 
    } 
    // Target do not exists
    return false;
}

/*
*   @Test
*   output expected: 'false' 
*/
function element_do_not_exists_test(){
	var numbers= [1,2,3,4,5,6,7,8,9,10];
  var target = 14;
  console.log(binary_search(numbers, target));
}


/*
*   @Test
*   output expected: 'true' 
*/
function element_exists_test(){
	var numbers = [1,2,3,6,9,10];
  var target = 3;  
  console.log(binary_search(numbers, target));
}


// Entry point of the application for testing purposes
element_do_not_exists_test();
element_exists_test();
