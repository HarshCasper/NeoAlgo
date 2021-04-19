/*Problem Description
You are given a rod of length N inches and an array of prices that contains prices of all pieces of size smaller than N. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces.
*/

import java.util.Scanner;

class Helper {
    // this method - getValue() will return the final answer to main method 
    public int getValue(int price[], int n) {
        // m variable will help in getting the size array length by using price length 
        int m = price.length ;
        int size[] = new int[m];
        for(int i = 0 ; i < m  ; i++)
            size[i] = i + 1 ;
        // call solve() method for solving the problem
        int ans = solve(price , size, m , n);
        return ans ;
    }
    //solve() method will act as solving the problem
    int solve(int[] price , int[] size , int m , int n  )
    {
        // Create 2-D array to store the value of profit 
        int dp[][] = new int[m+1][n+1] ;        
        for(int i = 0 ; i < m + 1; i++)
        {
            for(int j = 0 ; j < n + 1 ; j++)
            {
                // if size = 0 or there is 0 value for the size
                if(i == 0 || j ==0 )
                {
                    dp[i][j] = 0;                    
                }
                /*  if size is less than the current max size then 
                  get the max price from size or neglect if not needed
                */
                else if(size[i-1] <= j )
                {
                    dp[i][j] = Math.max(price[i-1] + dp[i][j - size[i-1] ] , dp[i-1][j] ) ;
                }
                // if size is greater than current max size , no value is taken from price array
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }    
}
// main class which contains main method
public class Rod_Cutting {	
	 public static void main(String args[]) {
	        Scanner sc = new Scanner(System.in);
	        System.out.println("Enter number of testcase");
	        int test = sc.nextInt();
	        while (test-- > 0) {
	        	System.out.println("Enter length of rod");
	            int n = sc.nextInt();
	            int[] arr = new int[n];
                    // get values of price 
	            System.out.println("Enter price of each length");
	            for (int i = 0; i < n; i++) 
	            	arr[i] = sc.nextInt();
                    // Creating object of another class 
	            Helper help = new Helper();
	            System.out.println(help.getValue(arr, n));
	        }
	    }	 
}
/* Input
Enter number of testcase
1
Enter length of rod
8
Enter price of each length
1 5 8 9 10 17 17 20
Output
22
Explanation :
The maximum value we get is 22 by cutting in two pieces of lengths 2 and 6 . So , 22 is answer.
Time Complexity : O(N^2)
Space Complexity : O(N)
*/
