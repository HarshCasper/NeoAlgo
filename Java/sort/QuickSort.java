// Program to implement QuickSort Algorithm in Java


import java.util.*;
class Sorting
{
	// function to print the final sorted array in ASCending order
	static void printArray(int arr[])
    	{
        	int n = arr.length;
        	for (int i=0; i<n; ++i)
            		System.out.print(arr[i]+" ");
        	System.out.println();
    	}
	
   	/* 
		This is the calling function that implements QuickSort algorithm, where:
		arr = input array given by user;
		low = starting index;
		high = ending index
	*/
    	static void quickSort(int arr[], int low, int high)
    	{
        	if (low < high)
        	{
            		// pi is partitioning index, arr[pi] is now at right place 
            		int pi = new QuickSort().partition(arr, low, high);
			
            		// Recursively sort elements before partition and after partition
            		quickSort(arr, low, pi-1);
            		quickSort(arr, pi+1, high);
        	}
    	}
	
    	// main() 
    	public static void main(String args[])
    	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int arr[] = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = sc.nextInt();
			
		quickSort(arr, 0, n-1);
		printArray(arr);
	} 
}

class QuickSort
{
   	/* 
		This function takes last element as pivot, places  the pivot element at its correct position in sorted  array, 
		and places all smaller (smaller than pivot) to left of pivot and all greater elements to right  of pivot 
    	*/
    	static int partition(int arr[], int low, int high)
    	{
       		/*
			The value of i is initialized to (low-1) since initially first element is swapped by itself 
			Reason: no greater element has been encountered apart from itself
		*/ 
		int i = (low - 1), j;
        	int pivotElement = arr[high];
        
        	for(j = low; j <= (high - 1); j++){
            		if(arr[j] < pivotElement){
                		i++;
                
                		// swap elements arr[i] and arr[j]
                		int temp = arr[i];
                		arr[i] = arr[j];
                		arr[j] = temp;
            		}
        	}
        
        	// swap pivot element with element at index=(i + 1) since loop ended, to obtain LHS of pivot
        	int temp = arr[i + 1];
        	arr[i + 1] = arr[high];
        	arr[high] = temp;
        
        	return(i + 1);
    	} 
}
