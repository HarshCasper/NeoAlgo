import java.util.Scanner;

/*
* Shell Sort is a very efficient sorting algorithm based on insertion sort technique.
* Shell Sort is more effective than insertion sort as
*	sometimes in Insertion Sorting, we shift a large block to insert an item at the right place as per the sorting order,
*	which can be avoided by using the Shell Sort algorithm.
* In Shell Sort, the sorting is done at certain intervals/gaps and everytime, this gap is reduced.
* This way, Shell Sort becomes nearly twice as fast as Insertion Sort.
*/

public class ShellSort 
{ 
	static void printArray(int arr[]) 
	{ 
		//function to print the elements of the array
  
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i] + " "); 
		
		System.out.println(); 
	} 

	int sort(int arr[]) 
	{ 
		int n = arr.length; 

		//initially gap = n/2
		for (int gap = n/2; gap > 0; gap /= 2) 	
		{ 
			for (int i = gap; i < n; i += 1) 
			{
				//decreasing by gap/2
				int temp = arr[i]; 
				int j; 
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
					arr[j] = arr[j - gap]; 
				//swapping the contents of arr[i] and arr[j]
				arr[j] = temp; 
			} 
		} 
		return 0; 
	} 
    
    	private static Scanner sc = new Scanner(System.in);

	public static void main(String args[]) 
	{ 
		//we store the number of elements in n
		System.out.println("Kindly enter the number of elements: ");
		int n = sc.nextInt();
		
		//declaring an array of n elements
        	int arr[] = new int[n];
		
		//taking the input from the user
		for(int i=0;i<n;i++)
		{
			System.out.print("\n" + i + "'th element : ");
			arr[i] = sc.nextInt();
		}
		
		System.out.println("\nArray before sorting"); 
		printArray(arr); 

		ShellSort ob = new ShellSort(); //creating an object of shellsort class so that the methods inside shellsort class can be used
		ob.sort(arr); 

		System.out.println("Array after sorting"); 
		printArray(arr); 
	} 
}
/*

Output:

Kindly enter the number of elements: 5

0'th element : 1
1'th element : 2
2'th element : 5
3'th element : 3
4'th element : 0
Array before sorting
1 2 5 3 0 
Array after sorting
0 1 2 3 5 
*/ 
