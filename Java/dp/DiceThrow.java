/*  Dice Throw problem is an important problem which can be solved with Naive or Dynamic approach.
    Below is the Java program following Dynamic Approach to find the number of ways to get sum 'x' with 'n'
    dice where every dice has 'm' faces */
import java.util.*;
import java.lang.*;
import java.io.*;

class DiceThrow {
    /* The main function that returns the number of ways to get sum 'x' with 'n' dice and 'm' with m faces. */
    public static long numberOfWays(int m, int n, int x) {
    /* Create a table to store the results of sub-problems.
    One extra row and column are used for simplicity 
    (Number of dice is directly used as row index and sum is directly used as column index). 
    The entries in 0th row and 0th column are never used. */
        long[][] table = new long[n+1][x+1];

        /* Table entries for only one dice */
        for(int j = 1; j <= m && j <= x; j++)
            table[1][j] = 1;
              
    /* Fill rest of the entries in table using recursive relation 
    i: number of dice, j: sum */
        for(int i = 2; i <= n;i ++){
            for(int j = 1; j <= x; j++){
                for(int k = 1; k < j && k <= m; k++)
                    table[i][j] += table[i-1][j-k];
            }
        }
        return table[n][x];
    }

    public static void main (String[] args) {
        int m, n, x;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of faces 'm': ");
        m = sc.nextInt();
        System.out.print("Enter the number of dices 'n': ");
        n = sc.nextInt();
        System.out.print("Enter the sum for which you want ways for: ");
        x = sc.nextInt();
        System.out.println("Number of ways to get the sum "+x+" is: "+numberOfWays(m, n, x));
    }
}

/* Sample Input/Output:
   Input:
   Enter number of faces 'm': 6
   Enter the number of dices 'n': 3
   Enter the sum for which you want ways for: 8

   Output:
   Number of ways to get the sum 8 is: 21

   Time and space complexities:
   Time complexity: O(m * n * x) where m is number of faces, n is number of dice and x is given sum.
   Space complexity: O(n * x) where n is number of dice and x is given sum.
 */
