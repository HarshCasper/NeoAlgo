import java.util.*;

public class AggressiveCow {

    private static boolean checkDist(int dist, int cows, int arr[]) {
        int cowInStall = 1;
        int lastPos = arr[0];

        // here we check if the distance we have can be minimum distance or not
        // if yes, we return true
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - lastPos < dist) {
                continue;
            }
            if(++cowInStall == cows) {
                return true;
            }
            lastPos = arr[i];
        }

        return false;
    }

    private static int binSearch(int cows, int arr[]) {
        int left = 0;
        int right = arr[arr.length - 1] - arr[0];

        // using binary search technique to find distances
        while (left <= right) {
            int mid = (left + right)/2;

            if (checkDist(mid, cows, arr)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of stalls and cows:");
        int stalls = sc.nextInt();
        int cows = sc.nextInt();
        int arr[] = new int[stalls];
        System.out.println("Enter stall indexes:");
        for (int i = 0; i < stalls; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        // sorting array so that we can use it in Binary search
        Arrays.sort(arr);

        int result = binSearch(cows, arr);

        System.out.println("Largest minimum distance:" + result);
    }
}
/**
 * Sample input/output:
 * 
 * Enter number of stalls and cows:
 * 5 3
 * Enter stall indexes:
 * 1 2 4 8 9
 * Largest minimum distance:3
 * 
 * Enter number of stalls and cows:
 * 6 4
 * Enter stall indexes:
 * 0 3 4 7 9 10
 * Largest minimum distance:3
 * 
 * Time complexity: O(N log(N))
 * Space complexity: O(N)
 * 
 * Link to the problem: https://www.spoj.com/problems/AGGRCOW/
 */
