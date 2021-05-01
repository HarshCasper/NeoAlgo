/*
C# Program to Perform a Selection Sort

Selection sort is an algorithm of sorting an array where it loop from the start 
of the loop, and check through other elements to find the minimum value.
After the end of the first iteration, the minimum value is swapped with the current element.
The iteration then continues from the 2nd element and so on.
*/
using System;

class SelectionSort
{
    static void Main(string[] args)
    {
        //Take array size input
        Console.Write("Enter array size: ");
        int array_size = Convert.ToInt32(Console.ReadLine());
        
        int[] array = new int[array_size]; 
        
        //Take array elements input
        for(int i=0; i<array_size; i++){
            Console.Write("Element {0} : ", i);
            array[i] = Convert.ToInt32(Console.ReadLine());
        }
        
        //Print array before Selection sort
        Console.Write("\nThe Array Before Selection Sort is: ");
        for(int i=0; i<array_size; i++)
        {
            Console.Write(array[i]+ " ");
        }
        
        int MinIndex = 0;//current index of the current minimum wwe are looking for
        int temp = 0; //temparory variable for swapping the value of the current min index
 
        //MainIndex is the pointer for each lowest we need to find
        for(int MainIndex=0; MainIndex<array_size-1; MainIndex++)
        {
            //MinIndex is now the current spot in the main list
            MinIndex = MainIndex;
            
            //remaining goes threw the remainder of the list finding the index of the next lowest value
            for(int RemainingIndex=MainIndex+1; RemainingIndex<array_size; RemainingIndex++)
            {
                //if the Remaining element is the less then the MinIndex we move the index to that spot
                //will swap values after going through the entire list
                if (array[RemainingIndex] < array[MinIndex])
                {
                    //Update minimum amount index
                    MinIndex = RemainingIndex;
                }
            }
 
            //We now have the index of the lowest number in the remaining list. Swap it withthe current i element in the list  
            temp = array[MinIndex];
            array[MinIndex] = array[MainIndex];
            array[MainIndex] = temp;
        }
 
        Console.Write("\nThe Array After Selection Sort is: ");
        for (int i=0; i<array_size; i++)
        {
            Console.Write(array[i]+ " ");
        }
    }
}
/*
Input:

Enter array size: 5
Element 0 : 67
Element 1 : 34
Element 2 : 56
Element 3 : 12
Element 4 : 73

Output:
The Array Before Selection Sort is: 67 34 56 12 73 
The Array After Selection Sort is: 12 34 56 67 73

*/

/*
Time Complexity: O(n2)
Space Complexity: O(1)
*/