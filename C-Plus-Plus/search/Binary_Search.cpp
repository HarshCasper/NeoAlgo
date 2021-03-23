#include <iostream>
#include <algorithm>
using namespace std;

//Function which returns true if element found in an array, else returns false.
bool binary_search(int *arr, int search_element, int lb, int ub) {
    while (lb <= ub) {
        int mid = lb + (ub - lb) / 2;
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
    cout << "Enter the number of test cases : " << std::endl;
    cin >> t;

    while (t--) {
        cout << "Enter the size of an array : " << std::endl;
        cin >> n;

        // dynamic memory allocation
        arr = new int[n];

        cout << "Enter the elements in an array : " << std::endl;
        for (int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        cout << "Enter the element to search : " << std::endl;
        cin >> search_element;

        // call to binary search function
        bool result = binary_search(arr, search_element, 0, n);

        if(result) {
            cout << "Element found." << std::endl;
        } else {
            cout << "Element not found." << std::endl;
        }
        // free memory after use
        delete[] arr;
    }
    return 0;
}
