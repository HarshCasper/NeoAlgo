
import java.io.*;
import java.util.*;

public class LongestSubArrayHavingSumk {

	// function to find the length of longest subarray having sum k
	static int lengthOfLongestSubarray(int arr[], int n, int k) {

		// HashMap to store (sum, index)
		HashMap<Integer, Integer> map = new HashMap<>();
		int sum = 0, maxLength = 0;

		// traversing the given array
		for (int i = 0; i < n; i++) {

			// accumulate sum
			sum += arr[i];

			// when subarray starts from index '0'
			if (sum == k)
				maxLength = i + 1;

			// making an entry for 'sum' if it is not present in 'map'
			if (!map.containsKey(sum)) {
				map.put(sum, i);
			}

			// checking if 'sum-k' is present in 'map' or not
			if (map.containsKey(sum - k)) {

				// updating maxLength
				if (maxLength < (i - map.get(sum - k)))
					maxLength = i - map.get(sum - k);
			}
		}

		return maxLength;
	}

	public static void main(String args[]) {
		int[] arr = { 1, 2, 1, 0, 1, 1, 0 };
		int n = arr.length;
		int k = 4;
		System.out.println("Length = " + lengthOfLongestSubarray(arr, n, k));
	}
}

/*
 * output: Length = 4
 *
 * Time complexity = O(n) Space complexity= O(n)
 */