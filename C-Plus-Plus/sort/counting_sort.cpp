/*
 Created by Sarthak-9 on 30-12-2020.
 Count Sort Algorithm for Sorting an array of small integers quickly.

 Worst complexity: O(n+k)
 Average complexity: O(n+k)
 Space complexity: O(n+k)
 where n is the number of elements input in array and k is the range of input.
*/

#include <iostream>

using namespace std;

int Max(long long int A[], long long int n) {
        long long int max = A[0];

        // finds the maximum element of the array
        for (long long int i = 0; i < n; i++) {
                if (A[i] > max) {
                        max = A[i];
                }
        }
        return max;
}

void CountSort(long long int A[], long long int n) {
        long long int max = Max(A, n);
        int* count = new int [max + 1];

        // initializes the count array with all elements to zero
        for (long long int i = 0; i < max + 1; i++) {
                count[i] = 0;
        }

        // updates the count array with frequencies of given numbers
        for (long long int i = 0; i < n; i++) {
                count[A[i]]++;
        }

        long long int i = 0;
        long long int j = 0;

        // updates A with sorted elements
        while (j < max + 1) {
                if (count[j] > 0) {
                        A[i++] = j;
                        count[j]--;
                } else {
                        j++;
                }
        }

        delete [] count;
}

int main() {

        long long int n;
        long long int A[100000];
        cout << "Enter the size of array" << endl;
        cin >> n;
        cout << "Enter the elements" << endl;

        // inputs numbers from the user in an array
        for (long long int i = 0; i < n; i++) {
                cin >> A[i];
        }

        CountSort(A, n);

        cout << "The sorted array is :" << endl;

        // prints the sorted array
        for (long long int i = 0; i < n; i++) {
                cout << A[i] << " ";
        }
        cout << endl;
        return 0;
}

/*
 Input:
 Enter the size of array
 10
 Enter the elements
 45 86 27 38 59 12 86 72 125 38

 Output:
 The sorted array is :
 12 27 38 38 45 59 72 86 86 125
*/