//Count Inversion problem with mergesort algorithm where i < j and arr[j] < arr[i] is an inversion
using System;

namespace CountInversionsProblem
{
    class Count_Inversions
    {
        //The merge step to sort the elements and count inversions
        private static int Merge(int[] arr, int[] temp, int leftStart, int mid, int rightEnd)
        {
            int left = leftStart, right = mid + 1, index = left, count = 0;
            //Compare Elments from arr portion and sort them in temproray array temp
            while (left < mid + 1 && right <= rightEnd)
            {
                if (arr[right] < arr[left])
                {
                    temp[index] = arr[right++];
                    count += mid + 1 - left;
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

            return count;
        }
        // recursive part in merge sort to break the array into smaller portions and count inversions
        private static int CountInversions(int[] arr, int[] temp, int leftStart, int rightEnd)
        {
            if (leftStart < rightEnd)
            {
                int count = 0;
                int mid = leftStart + (rightEnd - leftStart) / 2;
                count += CountInversions(arr, temp, leftStart, mid);
                count += CountInversions(arr, temp, mid + 1, rightEnd);
                count += Merge(arr, temp, leftStart, mid, rightEnd);
                return count;
            }
            return 0;

        }
        //Limit the number of parameters
        public static int CountInversions(int[] arr)
        {
            int count = CountInversions(arr, new int[arr.Length], 0, arr.Length - 1);
            return count;
        }
        static void Main(string[] args)
        {
            Console.Write("Enter array size: ");
            int n = Convert.ToInt32(Console.ReadLine());
            int[] arr = new int[n];
            Console.WriteLine("Enter array Elements: ");
            for (int i = 0; i < n; i++)
            {
                arr[i] = Convert.ToInt32(Console.ReadLine());
            }
            int count = CountInversions(arr);
            Console.WriteLine($"\n\nNumber of inversions = {count}");
        }
    }
}
/*
Sample Input


Enter array size: 5
Enter arry elements : 
2
1
3
1
2

input array : 2 1 3 1 2

number of inversions output : 4 
Complexity:
Merge sort takes time complexity of O(nlogn) and space complexity of O(n)
 
 */

