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

int Min(long long int A[], long long int n) {
        long long int min = 100000;

        // finds the maximum element of the array
        for (long long int i = 0; i < n; i++) {
                if (A[i] < min) {
                        min = A[i];
                }
        }
        return min;
}

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
        long long int min = Min(A, n);
        int* count = new int [max- min + 1];

        // initializes the count array with all elements to zero
        for (long long int i = 0; i < n; i++) {
                count[A[i]-min] = 0;
        }

        // updates the count array with frequencies of given numbers
        for (long long int i = 0; i < n; i++) {
                count[A[i]-min]++;
        }

        int k = 0;

        for (int j = max; j >= min; j--)
        {
                for (int i = 0; i < count[j - min]; i++)
                {
                        A[k++] = j;
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
        for (long long int i = n-1; i >=0; i--) {
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
 -80 77 256 -125 910 746 -244 910 1012 488

 Output:
 The sorted array is :
 -244 -125 -80 77 256 488 746 910 910 1012
*/