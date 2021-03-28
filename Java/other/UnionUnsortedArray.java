/* Program to find the union of two unsorted array */

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class UnionUnsortedArray {

	public static void main() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter n:");
		int n = sc.nextInt();
		int[] array1 = new int[n];
		int[] array2 = new int[n];

		System.out.println("Enter array1 elements:");
		for(int i = 0 ; i < n ; i++)
			array1[i] = sc.nextInt();
			
		System.out.println("Enter array1 elements:");
		for(int i = 0 ; i < n ; i++)
			array2[i] = sc.nextInt();

		unionArray(array1,array2);
	}

	static void unionArray(int[] array1, int[] array2) {
		Map<Integer, Integer> map = new HashMap<Integer,Integer>();
		// insert elements of array1 in the map
		for(int i = 0 ; i < array1.length ; i++)
			map.put(array1[i], i);
		// insert elements of array1 in the map
		for(int i = 0 ; i < array2.length ; i++)
			map.put(array2[i], i);
		System.out.print("Union of two unsorted array : ");
		for(Map.Entry mapElement : map.entrySet())
			 System.out.print(mapElement.getKey() + " ");		 
	}
}

/*
Input:
Enter n:
4
Enter array1 elements:
9 -3 -6 0
Enter array2 elements:
-1 -3 -6 1

Output:
Union of two unsorted array : 0 -1 1 -3 -6 9 
*/
