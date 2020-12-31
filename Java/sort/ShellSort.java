import java.util.Scanner;

/*
*Shell Sort is a very efficient sorting algorithm based on insertion sort technique.
*
*Shell Sort is more effective than insertion sort as
*sometimes in Insertion Sorting, we shift a large block to insert an item at the right place 
*as per the sorting order,
*which can be avoided by using the Shell Sort algorithm.
*
*In Shell Sort, the sorting is done at certain intervals/gaps and everytime, this gap is reduced.
*This way, Shell Sort becomes nearly twice as fast as Insertion Sort.
*/

public class ShellSort 
{
	int shellsort(int arr[], int n) 
	{ 
		//here n is the size of the array
		//initially gap = n/2
		for (int gap = n/2; gap > 0; gap = gap/2) 	
		{ 
			for (int i = gap; i < n; i++) 
			{
				//decreasing the gap
				int k = arr[i];
                		int j = i;
                
				while (j >= gap && arr[j - gap] > k) 
				{
				    arr[j] = arr[j - gap];
				    j = j - gap;
				}
				arr[j] = k;	
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
        	int array[] = new int[n];
		
		//taking the input from the user
		for(int i=0;i<n;i++)
		{
			System.out.print("\n" + i + "'th element : ");
			array[i] = sc.nextInt();
		}
		
		System.out.println("\nArray before sorting"); 
		for (int j=0; j<n; j++) 
			System.out.print(array[j] + " "); 
		
		
		//creating an object of shellsort class so that the methods inside shellsort class can be used
		ShellSort object = new ShellSort(); 
		object.shellsort(array,n);
		
		System.out.println("\nArray after sorting"); 
		for (int k=0; k<n; k++) 
			System.out.print(array[k] + " "); 
		
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

