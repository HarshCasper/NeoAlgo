import java.util.*;

public class Search_insert_index {

    static int search(int[] nums, int target) {
        // using binary search since array is sorted.
        int start = 0;
        int end = nums.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (target > nums[mid]) {
                start = mid + 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                return mid;
            }
        }

        return start;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int len, target, index;
        System.out.println("Enter the length of array");
        len = sc.nextInt();
        int arr[] = new int[len];
        System.out.println("Enter the array elements");
        for (int i = 0; i < len; i++)
            arr[i] = sc.nextInt();
        System.out.println("Enter the target value");
        target = sc.nextInt();
        index = search(arr, len);
        System.out.println("Index of the target element is " + index);
    }
}
/*
 * output: Enter the length of array 4 Enter the array elements 1 2 5 6 Enter
 * the target value 3 Index of the target element is 2
 *
 * Time Complexity: O(log(n)) space complexity: O(n)
 */
