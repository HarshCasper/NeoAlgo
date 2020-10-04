import java.util.*;

public class Linear_search {
	//It iterates through the array to find key.
	//The average and worst case time complexity O(n).
	//The worst case space complexity is O(1).
	static int linSearch(int[] a, int k, int length) {
		for (int i = 0; i < length; i++) {
			if (a[i] == k)
				return i + 1; //returns position
		}
		return -1; //returns -1 if not found
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the length of the array: ");
		int length = sc.nextInt();
		int arr[] = new int[length];
		System.out.print("Enter array values: ");
		for (int i = 0; i < length; i++) {
			arr[i] = sc.nextInt();
		}
		System.out.print("Enter the value whose index needs to be searched: ");
		int value = sc.nextInt();
		System.out.println("Index of " + value + " is: " + linSearch(arr, value, length));
	}
}
/*
Input:
Enter the length of the array: 5
Enter array values: 2 7 8 9 1
Enter the value whose index needs to be searched: 9 
output:
Index of 9 is: 4
*/
