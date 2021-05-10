/*
C# Program to Perform a Heap Sort
Heap Sort is a popular and efficient sorting algorithm.Heap sort is a comparison
based sorting technique based on Binary Heap data structure. It is similar to 
selection sort where we first find the minimum element and place the minimum 
element at the beginning. We repeat the same process for the remaining elements.
*/

using System;
public class HeapSort
{
    static void Sort(int[] array, int length)
    {
        //Build max heap
        for (int i = length / 2 - 1; i >= 0; i--)
        {
            Heapify(array, length, i);
        }
        for (int i = length - 1; i >= 0; i--)
        {
            //Swap
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;
            //Heapify root element
            Heapify(array, i, 0);
        }
    }

    //Rebuilds the heap
    static void Heapify(int[] array, int length, int i)
    {
        //Find largest among root and children
        int max = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < length && array[left] > array[max])
        {
            max = left;
        }
        
        if (right < length && array[right] > array[max])
        {
            max = right;
        }
        
        //If root is not largest, swap with largest and continue heapifying
        if (max != i)
        {
            int swap = array[i];
            array[i] = array[max];
            array[max] = swap;
            Heapify(array, length, max);
        }
    }

    public static void Main()
    {
        //Take array size input
        Console.Write("Enter array size: ");
        int length = Convert.ToInt32(Console.ReadLine());
        
        int[] array = new int[length]; 
        
        //Take array elements input
        for(int i=0; i<length; i++){
            Console.Write("Element {0} : ", i);
            array[i] = Convert.ToInt32(Console.ReadLine());
        }
        
        
        //Print array before Heap sort
        Console.Write("\nThe Array Before Heap Sort is: ");
        for(int i=0; i<length; i++)
        {
            Console.Write(array[i]+ " ");
        }
        
        Sort(array,length);
        
        //Print array after Heap sort
        Console.Write("\nThe Array After Heap Sort is: ");
        for (int i=0; i<length; i++)
        {
            Console.Write(array[i]+ " ");
        }
    }
}

/*
Input:

Enter array size: 5
Element 0 : 34
Element 1 : 73
Element 2 : 17
Element 3 : 61
Element 4 : 45

Output:

The Array Before Heap Sort is: 34 73 17 61 45 
The Array After Heap Sort is: 17 34 45 61 73
*/

/*
Time complexity: O(nLogn)
Space complexity: O(1)
*/