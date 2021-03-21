Input Format:
A number n
v1 v2 .. n number of elements
w1 w2 .. n number of elements
A number cap
Output Format:
A number representing the maximum value that can be created in the bag without overflowing it's capacity

Sample Input
5
15 14 10 45 30
2 5 1 3 4
7
Sample Output
75

Source Code:
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn=new Scanner(System.in);
        // total number of count of items
        int n=scn.nextInt();

        // input of values of n items by user
        int[] value=new int[n];
        for(int i=0;i<n;i++){
            value[i]=scn.nextInt();
        }
 
        // input of weights of n items by user
        int[] weight=new int[n];
        for(int i=0;i<n;i++){
            weight[i]=scn.nextInt();
        }
        
        // input of max capacity of sack 
        int capacity=scn.nextInt();

        // defined 2D dp array 
        int[][] dp=new int[n+1][capacity+1];

        /* filling of dp array whose each cell represents that what will the max 
	value that can be stored when the capacity is j */ 
        for(int i=1;i<dp.length;i++){
            for(int j=1;j<dp[0].length;j++){
		/* when the weight of current element is less than or equal to capacity of jth sack that is
		 element is eligible to enter the sack */
                if(j>=weight[i-1] ){ 

                    int remaining= j-weight[i-1];
                    
			//if remaining value is in scope then it is considered otherwose it won't be considered
                    if(dp[i-1][remaining] + value[i-1] > dp[i-1][j] ){
                        dp[i][j] = dp[i-1][remaining] + value[i-1];
                    }else{
                         dp[i][j]=dp[i-1][j]; 
                    }
                }else{ 
			/* when the current element is not eligible to come to sack then
			 value of previous item will be considered */
                    dp[i][j]=dp[i-1][j]; 
                }
            }
        }
	/* the last cell of dp array will give the max value that can
	 be entered in the bag */      
        System.out.println(dp[dp.length-1][dp[0].length-1]);
    }
}