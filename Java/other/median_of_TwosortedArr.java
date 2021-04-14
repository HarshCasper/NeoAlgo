/*
Median of two sorted arrays

For given two sorted arrays arr1[] and arr2[] of different sizes
size1 and size2 respectively, your task is to return the median
of the two sorted array.
*/

import java.io.*;
import java.util.*;
import java.lang.Math;

class median_of_TwosortedArr
{
    //function to return mediam of the two sorted arrays
    public double medianofSortedArr(int arr1[], int arr2[], int size1, int size2)
    {
        //we assume size2 >= size1  
        if(size1 > size2)
        {
            //making second array to be an array with bigger size 
            int[] temp1 = arr1;
            arr1 = arr2;
            arr2 = temp1;
            //exchanging sizes as well
            int temp2 = size1;
            size1 = size2;
            size2 = temp2;
        }
        int minIdx = 0, maxIdx = size1;
        int mid = (size1 + size2 + 1) / 2;
        while(minIdx <= maxIdx)
        {
            int j = (minIdx + maxIdx) / 2;
            int k = mid - j;
            //for very small values of j
            if(j < minIdx && arr2[k-1] > arr1[j])
            {
                minIdx = j + 1;
            }
            //for very large values of k
            else if(j > minIdx && arr1[j - 1] > arr2[k])
            {
                maxIdx = j - 1;
            }
            // for preferable values of i
            else
            {
                //for maximum element
                int leftptr = 0;
                if(j == 0) 
                    leftptr = arr2[k - 1];
                else if(k == 0) 
                    leftptr = arr1[j - 1];
                else
                    leftptr = Math.max(arr1[j - 1], arr2[k - 1]);
                //otherwise if total size comes out to be 2
                if((size1 + size2) % 2 == 1) 
                    return leftptr;

                //for minimum element 
                int rightptr = 0;
                if(j == 0) 
                    rightptr = arr2[k];
                else if(k == n) 
                    rightptr = arr1[j];
                else 
                    rightptr = Math.min(arr2[k], arr1[j]);
                return (leftptr + rightptr) / 2.0;//the median value can be in fraction so taking double as return type        
            }
        }
        return 0.0;
    }
    
    //driver code
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);

        //taking input
        System.out.println("Enter size of first array: ");
        int size1 = sc.nextInt();
        System.out.println("Enter size of second array: ");
        int size2 = sc.nextInt();
        int arr1[] = new int[size1];
        System.out.println("Enter elements for first array: ");
        for (int i=0; i<size1; i++)
        {
            arr1[i] = sc.nextInt();
        }
        int arr2[] = new int[size2];
        System.out.println("Enter elements for second array: ");
        for (int i=0; i<size2; i++)
        {
            arr2[i] = sc.nextInt();
        }

        //for output
        double requiredMedian = medianofSortedArr(arr1, arr2, size1, size2);
        System.out.println("Median of the two sorted array is: " + requiredMedian);
    }
}

/*
EXAMPLE:-
Input -->
Enter size of first array: 2
Enter size of second array: 2
Enter elements for first array: 2 5
Enter elements for second array: 7 9
Output -->
Median of the two sorted array is: 6.00000
Explanation -->
Mergered array so obtained is [2, 5, 7, 9] and 
median is (5 + 7) / 2 = 6

TIME COMPLEXITY --> O(log(min(size1, size2)))
SPACE COMPLEXITY --> O(1)
*/
