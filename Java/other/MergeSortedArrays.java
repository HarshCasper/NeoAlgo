import java.util.*;

class MergeSortedArrays
{
	private static void merge(int arr1[], int arr2[])
	{
		// Iterate through all elements of arr2[] in reverse 
		for (int i = (arr2.length - 1); i >= 0; i--)
		{
            // In here we compare the different terms of
            // both arrays and place them in respective positions
			int j, last = arr1[arr1.length - 1];
			for (j = arr1.length - 2; j >= 0 && arr1[j] > arr2[i]; j--) {
                arr1[j+1] = arr1[j];
            }
			// If there was a greater element
			if (j != arr1.length - 2 || last > arr2[i])
			{
				arr1[j+1] = arr2[i];
				arr2[i] = last;
			}
		}
	}

	public static void main(String[] args)
	{
        Scanner sc = new Scanner(System.in);

        // taking input array 1
        System.out.println("Enter size of first array:");
        int size1 = sc.nextInt();
        int arr1[] = new int[size1];
        System.out.println("Enter array elements:");
        for (int i=0; i<size1; i++) {
            arr1[i] = sc.nextInt();
        }
        // taking input array 2
        System.out.println("Enter size of second array:");
        int size2 = sc.nextInt();
        int arr2[] = new int[size2];
        System.out.println("Enter array elements:");
        for (int i=0; i<size2; i++) {
            arr2[i] = sc.nextInt();
        }
        sc.close();
        
        merge(arr1, arr2);

        System.out.println("Sorted arrays are:");
        for (int i = 0; i < size1; i++) {
            System.out.print(arr1[i] + " ");
        }
        System.out.println();
        for (int i = 0; i < size2; i++) {
            System.out.print(arr2[i] + " ");
        }
	}
}
/**
 * Sample input/output
 * Enter size of first array:
 * 6
 * Enter array elements:
 * 1 8 9 15 16 18
 * Enter size of second array:
 * 4
 * Enter array elements:
 * 2 4 7 10
 * Sorted arrays are:
 * 1 2 4 7 8 9 
 * 10 15 16 18
 * 
 * Time complexity: O(m*n)
 * where m and n are sizes of the arrays
 * Space complexity: O(1)
 */
