import java.util.Scanner;

class RainWaterHarvesting {

    public static int saveWater(int[] arr, int size) {

        int result = 0;

        // traverse the array from second to second last element
        for (int i = 1; i < size - 1; i++) {

            // Find maximum element on its left
            int left = arr[i];
            for (int j = 0; j < i; j++) {
                left = Math.max(left, arr[j]);
            }

            // Find maximum element on its right
            int right = arr[i];
            for (int j = i + 1; j < size; j++) {
                right = Math.max(right, arr[j]);
            }

            // Update maximum water value
            result += Math.min(left, right) - arr[i];
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter array size:");
        int size = scanner.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter array elements:");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();

        System.out.println("Maximum amount of water that can be saved is:" + saveWater(arr, size));
    }
}

/*
* Sample input/output:
* Enter array size:
* 10
* Enter array elements:
* 0 2 1 3 0 1 2 1 2 1
* Maximum amount of water that can be saved is:5
*
* Time complexity: O(n^2)
* space complexity: O(1)
*/
