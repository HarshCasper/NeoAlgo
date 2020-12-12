/** 
Radix sort is based on counting sort
This sort is used for non-negative elements
Assuming the range is fixed, as int capacity
is limited in any language, this sort takes

MAX_INT contains 10 decimal values
If range is not fixed, this sort takes O(kn) time
where k is #decimal places in the number
This works because of the nature of counting sort
Counting sort is a stable sort
**/

public class RadixSort {
    // required variables
	private static int M = 10, K = 10;
	private static void counting_sort(int[] arr, int  n, int p) {
		int element = (int)Math.pow(10, p), i;
		int divs = element / 10;
		// counting array
		int[] count = new int[M];
		for(i = 0; i < M; i++)
			count[i] = 0;
		for(i = 0; i < n; i++)
			count[(arr[i] % element) / divs] ++;
		for(i = 1; i < M; i++)
			count[i] += count[i-1];
		int[] op = new int[n];
		for(i = n-1; i >= 0; i--) {
		    op[count[(arr[i] % element) / divs] - 1] = arr[i];
		    count[(arr[i] % element) / divs] --;
		}
		// copying the array back
		for(i = 0; i < n; i++)
			arr[i] = op[i];
	}

	private static void radix_sort(int[] arr, int n) {
		// apply counting sort for all decimal places
		for(int i = 1; i <= K; i++)
			counting_sort(arr, n, i);
	}

	public static void main(String[] args) {
		int n, i;
		Scanner sc= new Scanner(System.in);
		n = sc.nextInt();
		int[] arr = new int[n];
		// taking ip
		for(i = 0; i < n; i++)
			arr[i] = sc.nextInt();
		// perform the sort
		radix_sort(arr, n);
		for(i = 0; i < n; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
}

/**
Input : 
8
175 45 75 90 802 24 2 66
Output :
2 24 45 66 75 90 175 802

Time complexity : O(n)
Space complexity : O(n)
**/
