public class RadixSort {
    // required variables
	private static int M = 10, K = 10;
	private static void counting_sort(int[] arr, int  n, int p) {
		int ele = (int)Math.pow(10, p), i;
		int divs = ele / 10;
		// counting array
		int[] count = new int[M];
		for(i = 0; i < M; i++)
			count[i] = 0;
		for(i = 0; i < n; i++)
			count[(arr[i] % ele) / divs] ++;
		for(i = 1; i < M; i++)
			count[i] += count[i-1];
		int[] op = new int[n];
		for(i = n-1; i >= 0; i--) {
		    op[count[(arr[i] % ele) / divs] - 1] = arr[i];
		    count[(arr[i] % ele) / divs] --;
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