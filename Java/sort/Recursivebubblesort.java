		// Java program for recursive implementation 
		// of Bubble sort 

		import java.util.Arrays; 

		public class  Recursivebubblesort 
		{ 
			// A function to implement bubble sort 
			static void bubbleSort(int a[], int N) 
			{ 
				// Base case 
				if (N == 1) 
					return; 
			
				// One pass of bubble sort. After 
				// this pass, the largest element 
				// is moved (or bubbled) to end. 
				for (int i=0; i<N-1; i++) 
					if (a[i] > a[i+1]) 
					{ 
						// swap arr[i], arr[i+1] 
						int temp = a[i]; 
						a[i] = a[i+1]; 
						a[i+1] = temp; 
					} 
			
				// Largest element is fixed, 
				// recur for remaining array 
				bubbleSort(a, N-1); 
			} 
			
			// Driver Method 
			public static void main(String[] args) 
			{ 
				int arr[] = {2, 68, 35, 42, 22, 87, 77}; 
			
				bubbleSort(arr, arr.length); 
				
				System.out.println("Sorted array : "); 
				System.out.println(Arrays.toString(arr)); 
			} 

}
