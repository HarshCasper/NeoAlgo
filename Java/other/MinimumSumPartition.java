import java.util.*;

public class MinimumSumPartition {

    // Function to find the minimum sum
    public static int findMinSum(int[] arr, int i, int sumCalculated, int total)
    {
        // check for last element, meaning we have sum of one subset as sumCalculated and the other as
        // total - 2*sumCalculated, so we return their absolute difference
        if (i == 0) {
            return Math.abs((total-sumCalculated) - sumCalculated);
        }

        // returning minimum of when we first take arr[i] in first set and when we take it in 2nd set
        // recursive approach
        return Math.min(findMinSum(arr, i - 1, sumCalculated + arr[i-1], total),
                findMinSum(arr, i-1, sumCalculated, total));
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter size for the array:");
        int size = scanner.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter array elements:");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();

        // find total sum of all array elements
        int arraySum = 0;
        for (int i = 0; i < size; i++) {
            arraySum += arr[i];
        }

        int result = findMinSum(arr, size, 0, arraySum);

        System.out.println("The minimum difference between sum of 2 sets is:" + result);
    }
}
/*
* Sample input/output
* Enter size for the array:
* 6
* Enter array elements:
* 3 1 4 2 2 1
* The minimum difference between sum of 2 sets is:1
*
* Time complexity: O(2^n)
* Space complexity: O(n)
*/
