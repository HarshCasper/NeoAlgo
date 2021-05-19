/**

This algorithm prints the total ways in which a number N can be represented as sum of positive consecutive integers.

Proof: Let the input number be N and k represents number of positive consecutive integers
and x be the first integer. Now, this can be expressed as:

Here k=1,2,3... < sqrt(2*N), and for each value of k there can only be one such sequence at most

=> x+(x+1)+(x+2)+...+(x+(k-1)) = N  
=> k*x + (1+2+3+...+(k-1)) = N
=> k*x + k*(k-1)/2 = N => k*x = N - k*(k-1)/2       ----1

Since, k is a natural number and x is positive

=> N - k*(k-1)/2 > 0
=> 2*N > k*(k-1) => 2*N > k*k
=> k < sqrt(2*N)                                    ----2
       
So, for every value of k, we only need to find a valid starting integer x using ----1
(N-k*(k-1)/2) % k == 0 for x to be a valid starting integer. 

**/

import java.util.*;

public class ConsecutiveNumberSum {
    public static void main(String[] main) {
        Scanner scn = new Scanner(System.in);
        int N = scn.nextInt();

        int res = consecutiveNumberSum(N);
        System.out.println("Total ways: " + res);

        scn.close();
    }

    // function to calculate total ways in which num can be
    // represented as a sum of positive consecutive integers
    public static int consecutiveNumberSum(int N) {
        int count = 0;
        for (int k = 1; k * k < (2 * N); k++) {
            int div = N - (k * (k - 1)) / 2;
            if (div % k == 0) {
                count++;
            }
        }
        return count;
    }
}

/*
 * Test Case
 * 
 * Input: 15 Total ways: 4
 * 
 * 15 can be represented as: 15 = 7+8 = 4+5+6 = 1+2+3+4+5 Total count = 4
 * 
 * Complexities time: O(sqrt(2*N)) space: O(1)
 * 
 */
