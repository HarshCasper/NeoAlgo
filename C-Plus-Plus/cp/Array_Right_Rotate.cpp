/**
 * copyright 2020 @author omkarlanghe
 * 
 * @file
 * Given an unsorted array arr[] of size N, rotate it by D elements (clockwise).
 * Input:
 * 
 * The first line of the input contains T denoting the number of testcases. First line of each test case contains two space separated elements, N denoting the size of the array and an integer D denoting the number size of the rotation.
 * Subsequent line will be the N space separated array elements.
 * 
 * Output:
 * For each testcase, in a new line, output the rotated array.
 * 
 * Example:
 * Input:
 * 
 * 2                        where 2 is the total number of test cases.
 * 5 2                      where 5 is the size of array and 2 is the rotation factor for test case 1.
 * 1 2 3 4 5                space seperated integers represting elements of an array for test case 1.
 * 10 3                     where 10 is the size of array and 3 is the rotation factor for test case 2.
 * 1 2 5 3 4 6 7 8 9 10     space seperated integers represting elements of an array for test case 2.
 * 
 * Output:
 * 4 5 1 2 3
 * 8 9 10 1 2 3 4 5 6 7
 * 
 * Timecomplexity: O(n) where n is the size of an array.
*/
#include <iostream>
#include <vector>

void right_rotate_array(std::vector<int> *, int, int);
void rotate_by_one_element(std::vector<int> *, int);

/**
 * Function which performs array rotation by one element based on its given rotation factor.
*/
void right_rotate_array(std::vector<int> *arr, int size, int rotation_factor) {
    for (int i = 0 ; i < rotation_factor ; i++) {
        rotate_by_one_element(arr, size);
    }
}

/**
 * Function which shifts array elements by one position to its right.
*/
void rotate_by_one_element(std::vector<int> *arr, int size) {
    int temp = (*arr)[size - 1];
    for (int i = (size - 2) ; i >= 0 ; i--) {
        (*arr)[i+1] = (*arr)[i];
    }
    (*arr)[0] = temp;
}

/** Main function */
int main() {
    int t, size, rotate_factor, input;
    std::cout << "Enter testcases to test : " << std::endl;
    std::cin >> t;

    while (t--) {
        std::cout << "Enter size of an array : " << std::endl;
        std::cin >> size;
        std::cout << "Enter rotation factor to rotate : " << std::endl;
        std::cin >> rotate_factor;
        std::vector<int> ivec;
        std::vector<int> *v = &ivec;

        std::cout << "Enter the elements in an array : " << std::endl;
        for (int i = 0 ; i < size ; i++) {
            std::cin >> input;
            ivec.push_back(input);
        }

        right_rotate_array(v, size, rotate_factor);

        std::cout << "Array after right rotation : " << std::endl;

        for (int i = 0 ; i < size ; i++) {
            std::cout << ivec[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
