// Implementation of MergeSort a comparison-based sorting algorithm. It works on the principle of Divide and Conquer.

using System;

namespace MergeSortAlgorithm
{
    class Merge_Sort
    {
        //The merge step to sort the elements
        private static void Merge(int[] arr, int[] temp, int leftStart, int mid, int rightEnd)
        {
            int left = leftStart, right = mid + 1, index = left;
            //Compare Elments from arr portion and sort them in temproray array temp
            while (left < mid + 1 && right <= rightEnd)
            {
                if (arr[right] < arr[left])
                {
                    temp[index] = arr[right++];
                }
                else
                {
                    temp[index] = arr[left++];
                }
                index++;
            }
            // if the arr porion sorted but i didn't reach the last element place the rest in temp 
            for (; left <= mid; left++)
                temp[index++] = arr[left];
            // if the arr porion sorted but j didn't reach the last element place the rest in temp 
            for (; right <= rightEnd; right++)
                temp[index++] = arr[right];
            //Place the sorted elements from temp into arr
            for (left = leftStart; left <= rightEnd; left++)
                arr[left] = temp[left];
        }
        // recursive part in merge sort to break the array into smaller portions
        private static void MergeSort(int[] arr, int[] temp, int leftStart, int rightEnd)
        {
            if (leftStart < rightEnd)
            {
                int mid = leftStart + (rightEnd - leftStart) / 2;
                MergeSort(arr, temp, leftStart, mid);
                MergeSort(arr, temp, mid + 1, rightEnd);
                Merge(arr, temp, leftStart, mid, rightEnd);
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
            Console.WriteLine("Enter array Elements: ");
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
Enter arry elements : 
23
21
12
34
2
5
7
10

input array : 23 21 12 34 2 5 7 10

merge sorted arry output: 2 5 7 10 12 21 23 34

Complexity:
Merge sort takes time complexity of O(nlogn) and space complexity of O(n)
 
 */
