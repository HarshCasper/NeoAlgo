/*
The longest bitonic subsequence is a sequence in which the sequence is first increasing then decreasing ,
The below program finds the length of the longest bitonic subsequence.
*/

import java.util.Scanner;

class Code {
    static int longest_bitonic_subsequence(int[] v, int n) {
        // v_increase tracks the longest increasing subsequence
        int[] v_increase = new int[n + 1];
        for (int i = 0; i < n; i++) {
            v_increase[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (v[i] > v[j]) {
                    if (v_increase[i] <= v_increase[j]) {
                        v_increase[i] = v_increase[j] + 1;
                    }
                }
            }
        }
        // v_decrease tracks the longest decreasing subsequence
        int[] v_decrease = new int[n];
        for (int i = 0; i < n; i++) {
            v_decrease[i] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (v[i] > v[j]) {
                    if (v_decrease[i] <= v_decrease[j]) {
                        v_decrease[i] = v_decrease[j] + 1;
                    }
                }
            }
        }
        int max = 0;
        for (int i = 1; i < n; i++) {
            int temp = v_increase[i] + v_decrease[i] - 1;
            if (temp > max) {
                max = temp;
            }
        }
        return max;
    }

    // Driver Code
    public static void main(String[] args) {
        System.out.println("Enter the number of elements in the sequence");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] v = new int[n + 1];
        System.out.println("Enter the elements of the sequence");
        for (int i = 0; i < n; i++) {
            v[i] = sc.nextInt();
        }
        System.out.println("The length of longest bitonic subsequence is : " + longest_bitonic_subsequence(v, n));
    }
}

/*
Sample I/O:

Enter the number of elements in the sequence
10
Enter the elements of the sequence
1 2 6 3 12 14 4 9 10 7
The length of longest bitonic subsequence is : 7

Time Complexity : O(n^2)
Space Complexity : O(n)
*/
