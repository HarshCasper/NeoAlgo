/*
*   Author: Shishir Bhandari
*   Date: 28/10/2020
*/

// Search an element in an array using Ternary Search algorithm (iterative)
// Prerequisite: Sorted array should be passed
function ternary_search_iterative(leftIndex, rightIndex, key, array) {
    // If left index is greater than right index then the key cannot be searched. 
    while(rightIndex >= leftIndex) {

        // Find two mid values
        let mid1 = leftIndex + ((rightIndex - leftIndex) / 3);
        let mid2 = rightIndex - ((rightIndex - leftIndex) / 3);
        
        // If the key is in one of the mid values, return its index
        if(key == array[mid1])
            return mid1;
        else if(key == array[mid2])
            return mid2;
        
        // Check which part of the array the key is present
        // and update the leftIndex and rightIndex values accordingly
        if(key < array[mid1]) {
            rightIndex = mid1 - 1;  // key lies in the region between leftIndex and mid1
        }
        else if(key > array[mid2]) {
            leftIndex = mid2 + 1;   // key lies in the region between mid2 and rightIndex
        }
        else {
            leftIndex = mid1 + 1;
            rightIndex = mid2 - 1;
        }
    }

    // The key does not exist
    return -1;
}
