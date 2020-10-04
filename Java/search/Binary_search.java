import java.util.*;

public class Binary_search {
	//binary search algorithm explanation in its readme file in wiki section
	//this can performed recursively also
	//The average and worst case time complexity is O(log n)
	//The space complexity is O(1).
	static int binSearch(int[] a, int l, int h, int key) {
		while (l<= h) {
			int mid = (l + h) / 2;
			if (key == a[mid])
				return mid + 1; //index starts from zero so position has to be incremented by one.
			else if (key < a[mid])
				h = mid - 1;
			else
				l = mid + 1;
		}
		return -1;
	}
	public static void main(String[] args) {
		//to perform binary search the array must be in sorted order
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the length of the array: ");
		int length = sc.nextInt();
		int arr[] = new int[length];
		System.out.print("Enter array values: ");
		for (int i = 0; i < length; i++) {
			arr[i] = sc.nextInt();
		}
		// to sort the array if not sorted
		Arrays.sort(arr);
		System.out.print("Enter the value whose index needs to be searched: ");
		int value = sc.nextInt();

		int index = binSearch(arr, 0, length - 1, value);
		if (index == -1)
			System.out.println("Element Not found");
		else
			System.out.println("Index of " + value + " is: " + index);
	}
}
/*
Input:
Enter the length of the array: 5
Enter array values: 2 3 4 5 6
Enter the value whose index needs to be searched: 4
Output:
Index of 4 is: 3
*/
