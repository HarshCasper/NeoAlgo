public class ReversalAlgorithm {

	private static void leftReversal(int[] array, int k) {
		if (k == 0) 
            return; 
  
        int n = array.length; 
        k = k % n; 
        
        reverseArray(array, 0, k - 1); 
        reverseArray(array, k, n - 1); 
        reverseArray(array, 0, n - 1); 
	}

	private static void rightReversal(int[] array, int k) {
		if (k == 0) 
            return; 
  
        int n = array.length; 
        k = k % n; 
        
        reverseArray(array, 0, n - 1); 
        reverseArray(array, 0, k - 1); 
        reverseArray(array, k, n - 1); 
	}
	
	private static void reverseArray(int[] array, int start, int end) {
		int temp; 
        while (start < end) { 
            temp = array[start]; 
            array[start] = array[end]; 
            array[end] = temp; 
            start++; 
            end--; 
        } 
	}

	private static void printArray(int[] array) {
		for(int i : array) 
			System.out.print(i+" ");
		System.out.println();
	}

	public static void main(String[] args) {
		int[] array = {1,2,3,4,5,6,7};
		int k = 2;
		// left reversal
		leftReversal(array,k);
		// print array
		printArray(array);
		// right reversal
		rightReversal(array,k);
		//print array
		printArray(array);
	}
}

// Output:
// 3 4 5 6 7 1 2 -> after left rotation of original array
// 1 2 3 4 5 6 7 -> after right rotation of left rotated array