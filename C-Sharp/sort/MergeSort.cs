// Merge sort is an efficient, general-purpose, comparison-based sorting algorithm.
// Implementation of merge sort

using System;

namespace MergeSort
{
    class mergeSort
    {
        //The merge step in the sorting problem to sort the elements
        private static void merge(int[] arr, int[] C, int l, int mid, int r)
        {
            int i = l, j = mid + 1, k = l;
            //Compare Elments from arr portion andt sort them in temproray array C
            while (i < mid + 1 && j <= r)
            {
                if (arr[j] < arr[i])
                {
                    C[k] = arr[j++];
                }
                else
                {
                    C[k] = arr[i++];
                }
                k++;
            }
            // if the arr porion sorted but i didn't reach the last element place the rest in C 
            for (; i <= mid; i++)
                C[k++] = arr[i];
            // if the arr porion sorted but j didn't reach the last element place the rest in C 
            for (; j <= r; j++)
                C[k++] = arr[j];
            //Place the sorted elements from C into arr
            for (i = l; i <= r; i++)
                arr[i] = C[i];
        }
        // recursive part in merge sort to break the array into smaller portions
        private static void MergeSort(int[] arr, int[] C, int l, int r)
        {
            if (l < r)
            {
                int mid = l + (r - l) / 2;
                MergeSort(arr, C, l, mid);
                MergeSort(arr, C, mid + 1, r);
                merge(arr, C, l, mid, r);
            }

        }
        //Limit the number of parameters
        public static void MergeSort(int[] arr)
        {
            MergeSort(arr, new int[arr.Length], 0, arr.Length - 1);

        }
        static void Main(string[] args)
        {
            Console.Write("Enter array size: ");
            int n = Convert.ToInt32(Console.ReadLine());
            int[] arr = new int[n];
            for(int i = 0; i<n; i++)
            {
                arr[i] = Convert.ToInt32(Console.ReadLine());
            }
            MergeSort(arr);
            foreach (var i in arr)
            {
                Console.Write(i + " ");
            }
        }
    }
}
/*
Sample Input


Enter array size: 8
Enter arry elements : 23 21 12 34 2 5 7 10

output: 2 5 7 10 12 21 23 34

Complexity:
Merge sort takes time complexity of O(nlogn) and space complexity of O(n)
 
 */
