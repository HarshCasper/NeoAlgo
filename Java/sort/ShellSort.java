class ShellSort 
{ 
	static void printArray(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i] + " "); 
		System.out.println(); 
	} 

	int sort(int arr[]) 
	{ 
		int n = arr.length; 

		for (int gap = n/2; gap > 0; gap /= 2) 
		{ 
			for (int i = gap; i < n; i += 1) 
			{ 
				int temp = arr[i]; 
				int j; 
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
					arr[j] = arr[j - gap]; 
				arr[j] = temp; 
			} 
		} 
		return 0; 
	} 

	public static void main(String args[]) 
	{ 
		int arr[] = {12, 34, 54, 2, 3}; 
		System.out.println("Array before sorting"); 
		printArray(arr); 

		ShellSort ob = new ShellSort(); 
		ob.sort(arr); 

		System.out.println("Array after sorting"); 
		printArray(arr); 
	} 
}
/*
Output:
Array before sorting
12 34 54 2 3       
Array after sorting
2 3 12 34 54  
*/