/*
 Exponential Search Algorithm is an optimized Binary Search to search an element in sorted array.
 It is specifically used when the size of array is infinite.
*/


#include <iostream>

using namespace std;

int BinarySearch(int arr[], int left, int right, int key)
{
        if (right >= left)
        {
                int mid = left + (right - left) / 2;

                if (arr[mid] == key) {
                        return mid;
                }

                // if element is present on left side i.e. smaller than mid
                if (arr[mid] > key) {
                        return BinarySearch(arr, left, mid - 1, key);
                }

                // else element is definitely on the right side
                return BinarySearch(arr, mid+1, right, key);
        }

        return -1;
}

int ExponentialSearch(int *arr, int n, int key)
{

        if (arr[0] == key) {
                return 0;
        }

        // repeated doubling method to find range for binary search
        int i = 1;
        while (i < n && arr[i] <= key) {
                i = i * 2;
        }

        int mini = i < (n-1) ? i : (n-1);

        // BinarySearch called
        return BinarySearch(arr, i / 2, mini, key);
}

int main()
{
        int n;
        cout<<"Enter the size of array"<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter the sorted array"<<endl;

        // inputs the array
        for(int i = 0; i < n; i++){
                cin>>arr[i];
        }

        int key;
        cout<<"Enter the element to search"<<endl;
        cin >> key;

        int search_result = ExponentialSearch(arr, n, key);

        if (search_result != -1) {
                cout << "Element is present at position " << search_result << endl;
        } else {
                cout << "Element is not present in the array" << endl;
        }

        return 0;

}

/*
 Time Complexity : O(log n)
 Space Complexity : O(log n)
*/

/*
 Input:
 Enter the size of array
 8
 Enter the sorted array
 5 12 25 38 52 76 110 155
 Enter the element to search
 52

 Output:
 Element is present at position 4

*/

