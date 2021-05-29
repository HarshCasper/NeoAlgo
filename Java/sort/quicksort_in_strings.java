/*
Quicksort is an efficient sorting algorithm based on divide and conquer strategy.
Quicksort is an inplace sorting algorithm.
It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays,
according to whether they are less than or greater than the pivot.
The program below is an implementation of quicksort on strings
*/

import java.util.Scanner;
class quickSort {
    // swap function swaps the elements in arr at position a and b
    void swap(String arr[], int a, int b) {
        String temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    // divide function partitions the array according to the pivot element
    int divide(String arr[], int left, int right) {
        int loc = left;
        while (left < right) {
            while (arr[loc].compareTo(arr[right]) <= 0 && loc < right) {
                right = right - 1;
            }
            if (arr[loc].compareTo(arr[right]) > 0) {
                swap(arr, loc, right);
                loc = right;
                left = left + 1;
            }
            while (arr[loc].compareTo(arr[left]) >= 0 && loc > left) {
                left = left + 1;
            }
            if (arr[loc].compareTo(arr[left]) < 0) {
                swap(arr, loc, left);
                loc = left;
                right = right - 1;
            }
        }
        return loc;
    }
    // QuickSort function sorts the array in lexicographical order
    void QuickSort(String arr[], int first, int last) {
        if (first < last) {
            int p = divide(arr, first, last);
            QuickSort(arr, first, p - 1);
            QuickSort(arr, p + 1, last);
        }
    }
}
// Driver Code
class code {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("[*] Enter the number of Names in the Array");
        int n =  sc.nextInt();
        System.out.println("[*] Enter the Names in the Array");
        String arr[] = new String[n];
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLine();
        }
        quickSort q = new quickSort();
        q.QuickSort(arr, 0, n - 1);
        System.out.println("[+] The Names of the sorted Array Using Quicksort");
        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
        sc.close();
    }
}

/*
Sample I/O:

[*] Enter the number of Names in the Array
5
[*] Enter the Names in the Array
adithya
rahul
aishwarya
aleena
abdul
[+] The Names of the sorted Array Using Quicksort
abdul
adithya
aishwarya
aleena
rahul

Time complexity : O(n^2)
Space complexity : O(n)
*/
