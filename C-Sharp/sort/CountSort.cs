/*
Counting sort is a sorting algorithm that sorts the elements of an array by counting 
the number of occurrences of each unique element in the array. The count is stored in an 
auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.

Counting sort which takes negative numbers as well
*/

using System;
using System.Linq;
class countingSort
{
    static void countSort(int[] arr, int Length)
    {
        int max = arr.Max();
	    int min = arr.Min();
	    int range = max - min + 1;
	
	    //Create a new "counting" array 
        //which stores the count of each unique number
	    int []count = new int[range];
	
	    //Create a new "output" array
	    int []output = new int[Length];
	
	    //loop through array and increment each numbers corresponding index in the countArray  
	    for (int i = 0; i < arr.Length; i++) {
	       count[arr[i] - min]++;
	    }
	
	    //start at second position and add each previous count to the next to get each integers final in the sorted array
	    for (int i = 1; i < count.Length; i++) {
	    
	       //this step we get the index ending positions for numbers
	       count[i] += count[i - 1];
	    }
	
	    for (int i = arr.Length - 1; i >= 0; i--) {
	       output[count[arr[i] - min] - 1] = arr[i];
	       count[arr[i] - min]--;
	    }
	
	    for (int i = 0; i < arr.Length; i++) {
	       arr[i] = output[i];
	    }
    }
  

    public static void Main(string[] args)
    {
	    //Take array size input
        Console.Write("Enter array size: ");
        int Length = Convert.ToInt32(Console.ReadLine());
        
        int[] array = new int[Length]; 
        
        //Take array elements input
        for(int i=0; i<Length; i++){
            Console.Write("Element {0} : ", i);
            array[i] = Convert.ToInt32(Console.ReadLine());
        }
        
        
        //Print array before Count sort
        Console.Write("\nThe Array Before Count Sort is: ");
        for(int i=0; i<Length; i++)
        {
            Console.Write(array[i]+ " ");
        }
	    
	    countSort(array,Length);
	    
	    //Print array after Count sort
	    Console.Write("\nThe Array Before Count Sort is: ");
	    for(int i=0; i<Length; i++)
        {
            Console.Write(array[i]+ " ");
        }
    }
}

/*
Input:

Enter array size: 5
Element 0 : 43
Element 1 : 23
Element 2 : 59
Element 3 : 11
Element 4 : 67

Output:

The Array Before Count Sort is: 43 23 59 11 67 
The Array Before Count Sort is: 11 23 43 59 67 
*/

/*
Time complexity: O(n+k)
Space complexity: O(n+k)
*/