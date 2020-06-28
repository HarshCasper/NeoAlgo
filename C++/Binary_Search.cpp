
/**
 * copyright 2020 @author omkarlanghe
 * @file
 * Implementation of Binary search algorithm.
*/
#include <iostream>

bool binary_search(int *, int, int, int);

/**
 * Function which returns true if element found in an array, else returns false.
*/
bool binary_search(int *arr, int search_element, int lb, int ub) {
    while (lb <= ub) {
        int mid = ((lb + ub) / 2);
        if (arr[mid] == search_element) {
            return (true);
        } else if (arr[mid] > search_element) {
            ub = mid - 1;
        } else {
            lb = mid + 1;
        }
    }
    return (false);
}

/** Main function */
int main() {
    int t, n, search_element;
    int *arr = nullptr;
    std::cout << "Enter the number of test cases : " << std::endl;
    std::cin >> t;

    while (t--) {
        std::cout << "Enter the size of an array : " << std::endl;
        std::cin >> n;

        arr = new int[n]; // dynamic memory allocation

        std::cout << "Enter the elements in an array : " << std::endl;
        for (int i = 0 ; i < n ; i++) {
            std::cin >> arr[i];
        }
        std::cout << "Enter the element to search : " << std::endl;
        std::cin >> search_element;

        // call to binary search function
        bool result = binary_search(arr, search_element, 0, n);

        if(result) {
            std::cout << "Element found." << std::endl;
        } else {
            std::cout << "Element not found." << std::endl;
        }
        delete[] arr; // free memory after use
    }
    return 0;
}
