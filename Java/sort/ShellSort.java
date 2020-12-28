class ShellSort 
{ 
	static void printArray(int arr[]) 
    { //function to print the elements of the array
        //called twice...one before sorting and once after sorting
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i] + " "); 
		System.out.println(); 
	} 

    int sort(int arr[]) 
    //here basically we compare the elements after some gaps...a bit like insertion sort
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
        int arr[] = {12, 34, 54, 2, 3}; //this is our array
        //we can take a dynamic input from the user if static input is not good
		System.out.println("Array before sorting"); 
		printArray(arr); 

		ShellSort ob = new ShellSort(); //creating an object of shellsort class so that the methods inside shellsort class can be used
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