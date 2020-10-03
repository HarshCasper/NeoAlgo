/**
 * @author omkarlanghe
 * Given an array of type positive integers, having ith element as feet and ith + 1 element as inches.
 * Eg: considering arr = [1,2] where 1 equals to feet and 2 equals to inches.
 * Find the maximum height, where height is calculated sum of feet and inches after converting feet into inches.
 * 
 * Input:
 * First line of input contains number of testcases.
 * For each testcase, first line of input N, contains size of an array.
 * Next line contains N number of elements (feet for ith index and inches for ith + 1).
 * 
 * Output:
 * Output maximum height from array.
 *
 * Example:
 * Input:
 * 2
 * 4
 * 1 2 2 1
 * 8
 * 3 5 7 9 5 6 5 5
 * 
 * Output:
 * 25
 * 93
 * 
 * Explanation:
 * Testcase 1: (1, 2) and (2, 1) are respective given heights. 
 * After converting both heigths in to inches, we get 14 and 25 as respective heights. So, 25 is the maximum height.
 * 
 * @source: https://practice.geeksforgeeks.org/problems/maximum-in-struct-array/1
*/

#include <bits/stdc++.h>
using namespace std;

int max_height_in_array(vector<int>, int);

int max_height_in_array(vector<int> arr, int size) {
    int max = 0;
    if ((size & 1) == 0) {  // check for even size.
        for (int i = 0 ; i < size ; i = i+2) {
            if (((arr[i] * 12) + arr[i+1]) > max) {
                max = ((arr[i] * 12) + arr[i+1]);
            }
        }
    } else {  // check for odd size.
        for (int i = 0 ; i < (size - 1) ; i = i+2) {
            if (((arr[i] * 12) + arr[i+1]) > max) {
                max = ((arr[i] * 12) + arr[i+1]);
            }
        }

        // special check for last remaining element at odd th index.
        if ((arr[size-1] * 12) > max) {
            max = (arr[size-1] * 12);
        }
    }
    return (max);
}

int main() {
    int test_cases, size, ele;
    cout << "Enter test cases : " << endl;
    cin >> test_cases;

    while (test_cases--) {
        vector<int> arr;
        cout << "Enter the size of an array : " << endl;
        cin >> size;

        cout << "Enter the elements in an array : " << endl;
        for (int i = 0 ; i < size ; i++) {
            cin >> ele;
            arr.push_back(ele);
        }

        int result = max_height_in_array(arr, size);
        cout << "Maximum height in the given array is : " << result
        << endl;
    }
    return 0;
}
