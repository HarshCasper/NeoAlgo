// Unique BSTs using DP
// For given n, how many structurally unique BST's that store values 1 ... n?
import java.io.*;
import java.util.*;

class Unique_BST {
    // function will return no. of unique bsts
    static int uniqueBST(int n) {
        int count[] = new int[n + 1];
        // for each 'i' number of nodes 
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                // No. of trees if j is a root
                count[i] += Math.max(count[j], 1) * Math.max(count[i - j - 1], 1);
            }
        }
        return count[n];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number:");
        int num = sc.nextInt();
        System.out.println("Number of Unique BSTs " + uniqueBST(num));
    }
}

/* output
Enter the number:
3
Number of Unique BSTs 5
Time complexity : O(n)
*/
