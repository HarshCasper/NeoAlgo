/**
 * Copyright 2020 @author omkarlanghe
 *
 * @file
 * Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S, If not found print -1.
 *
 *  Input :
 *  Testcase1:
    5 12                    =>  where 5 is the size of an array and 12 is the original sum to check.
    1 2 3 7 5               =>  space seperated integers representing elements in an array.

*   Testcase2:
    5 123                   =>  where 5 is the size of an array and 123 is the original sum to check.
    1 2 3 7 5               =>  space seperated integers representing elements in an array.

*   Testcase3:
    10 15                   =>  where 10 is the size of an array and 15 is the original sum to check.
    1 2 3 4 5 6 7 8 9 10    =>  space seperated integers representing elements in an array.
* Output :
    2 4

    -1

    1 5
* Explanation :
    Testcase1: sum of elements from 2nd position to 4th position is 12. (consider 1 based indexing)
    Testcase2: no subarray found whose sum equals to the given sum, hence print -1.
    Testcase3: sum of elements from 1st position to 5th position is 15. (consider 1 based indexing)
*/

#include <iostream>
/**
 * Function to print the index range of subarray equal to the given sum. If no such subarray found, print -1.
 * @param arr array to check
 * @param size size of an array
 * @param original_sum sum to match with the sum of all elements of a sub array.
 * @return void and prints index ranges if sum of sub array equal to the given
 * sum, else prints -1.
 */
void contiguous_sub_array(int *arr, int size, int orignal_sum) {
    int current_sum = 0, match = 0;

    for (int i = 0; i < size; i++) {
        current_sum = 0;
        for (int j = i; j < size; j++) {
            current_sum += arr[j];
            if (current_sum == orignal_sum) {
                match = 1;
                std::cout << (i + 1) << " " << (j + 1) << " ";
                break;
            } else if (current_sum > orignal_sum) {
                current_sum = 0;
                break;
            }
        }
        if (match) {
            break;
        }
    }
    if (match == 0) {
        std::cout << -1 << " ";
    } else {
        match = 0;
    }
    std::cout << std::endl;
}

/**
 * Test cases to test the program
*/
void test() {
    std::cout << "Test 1" << std::endl;
    int arr1[] = {1, 2, 3, 7, 5};
    int original_sum = 12;
    int size = sizeof(arr1) / sizeof(arr1[0]);
    contiguous_sub_array(arr1, size, original_sum);
    std::cout << "Test 1 passed\n ===================== \n";

    std::cout << "Test 2" << std::endl;
    int arr2[] = {1, 2, 3, 7, 5};
    original_sum = 123;
    size = sizeof(arr2) / sizeof(arr2[0]);
    contiguous_sub_array(arr2, size, original_sum);
    std::cout << "Test 2 passed\n ===================== \n";

    std::cout << "Test 3" << std::endl;
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    original_sum = 15;
    size = sizeof(arr3) / sizeof(arr3[0]);
    contiguous_sub_array(arr3, size, original_sum);
    std::cout << "Test 3 passed\n ===================== \n";
}

/** Main function */
int main() {
    test();
    return 0;
}
