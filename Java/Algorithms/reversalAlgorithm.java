import java.util.Scanner;

/* Reversal algorithm is used to rotate the array by k elements. */

public class ReversalAlgorithm {

	/* In this algorithm, arrays are divided into subarrays and reversed individually, and joined together. In the final step, the array is reversed to get the rotated array. */

	private static void leftReversal(int[] array, int k) {
		if (k == 0) 
            return; 
  
        int n = array.length; 
        k = k % n; 
        
        reverseArray(array, 0, k - 1); 
        reverseArray(array, k, n - 1); 
        reverseArray(array, 0, n - 1); 
	}

	/* In this algorithm, array is reversed after which the array is divided into subarrays and individually reversed. */

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
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter n:");
		int n = sc.nextInt();
		int[] array = new int[n];
		System.out.println("Enter array elements:");
		for(int i = 0 ; i < n ; i++)
			array[i] = sc.nextInt();
		System.out.println("Enter k:");	
		int k = sc.nextInt();	

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

/*
Input:
Enter n:
7
Enter array elements:
1 2 3 4 5 6 7
Enter k:
3

Output:
3 4 5 6 7 1 2 -> after left rotation of original array
1 2 3 4 5 6 7 -> after right rotation of left rotated array
*/
