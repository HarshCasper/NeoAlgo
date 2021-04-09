/*
    Perfect Sum Problem is mainly an extension of Subset Sum Problem.
    Here we not only need to find if there is a subset with
    given sum, but also need to print all subsets with given sum.
    Below is :
    A Java program to count all subsets with given sum.

*/
import java.util.ArrayList;
import java.util.Scanner;
public class PerfectSumProblem
{
 /*
        dynamicArr[i][j] is going to store true if sum j is
        possible with array elements from 0 to i.
 */
    static boolean[][] dynamicArr;
    static void display(ArrayList<Integer> v)
    {
        System.out.println(v);
    }
 /*
        A recursive function to print all subsets with the
        help of dynamicArr[][]. Vector p[] stores current subset.
 */
    static void subsets(int arr[], int i, int sum,
                                ArrayList<Integer> p)
    {
 /*
         If we reached end and sum is non-zero. We print
         p[] only if arr[0] is equal to sun OR dynamicArr[0][sum]
         is true.
 */
        if (i == 0 && sum != 0 && dynamicArr[0][sum])
        {
            p.add(arr[i]);
            display(p);
            p.clear();
            return;
        }
        if (i == 0 && sum == 0)
        {
            display(p);
            p.clear();
            return;
        }
 /*
         If given sum can be achieved after ignoring
         current element.
 */
        if (dynamicArr[i-1][sum])
        {
            // Create a new vector to store path
            ArrayList<Integer> b = new ArrayList<>();
            b.addAll(p);
            subsets(arr, i-1, sum, b);
        }
     /*
         If given sum can be achieved after considering
         current element.
     */
        if (sum >= arr[i] && dynamicArr[i-1][sum-arr[i]])
        {
            p.add(arr[i]);
            subsets(arr, i-1, sum-arr[i], p);
        }
    }
    //   Prints all subsets of arr[0..n-1] with sum 0.
    static void printAllSubsets(int arr[], int n, int sum)
    {
        if (n == 0 || sum < 0)
            return;
        dynamicArr = new boolean[n][sum + 1];
        for (int i=0; i<n; ++i)
        {
            dynamicArr[i][0] = true;
        }
        // Sum arr[0] can be achieved with single element
        if (arr[0] <= sum)
            dynamicArr[0][arr[0]] = true;
        // Fill rest of the entries in dynamicArr[][]
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < sum + 1; ++j)
                dynamicArr[i][j] = (arr[i] <= j) ? (dynamicArr[i-1][j] ||
                        dynamicArr[i-1][j-arr[i]])
                        : dynamicArr[i - 1][j];
        if (dynamicArr[n-1][sum] == false)
        {
            System.out.println("There are no subsets with" +
                    " sum "+ sum);
            return;
        }
 /*
         Now recursively traverse dynamicArr[][] to find all
         paths from dynamicArr[n-1][sum]
 */
        ArrayList<Integer> p = new ArrayList<>();
        subsets(arr, n-1, sum, p);
    }
    //Driver Program to test above functions
    public static void main(String args[])
    {
        int n;
        Scanner sc = new Scanner(System. in );
        System.out.print("Enter the number of elements you want in an array: ");
        n = sc.nextInt();
        int[] arr = new int[n];
        System.out.print("Enter the elements of an array: ");
        for (int i = 0; i < n; i++) {
            //reading dimensions from the user
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter the Sum you want subsets for: ");
        int sum;
        sum = sc.nextInt();
        printAllSubsets(arr, n, sum);
    }
}
/*
  Sample Input/Output:
  Input: Enter the number of elements you want in an array: 5
         Enter the elements of an array: 5 4 3 2 1
         Enter the Sum you want subsets for: 9

  Output: [4, 5]
          [2, 3, 4]
          [1, 3, 5]

  Time and space complexity for this approach:
  Time Complexity: 2^N
  Auxiliary Space: O(1)
*/
