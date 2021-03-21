/*
Purpose : 
In a trading system a product is bought in the morning and sold out on the same day. 
If a person can make only 2 transactions a day with a condition that second transaction is followed only after first then find the maximum profit the person could get.

Input formate : 
Line1 : Number of test cases
Line2 : Length of the prices array
Line3 : prices array separated with a space

Output formate : 
The maximum profit

Method :
Dynamic programming 

Intuition : 
Storing the maximum possible profit of every subarray in a table named profit 
Finally returning the profit[n-1]


Time complexity : O(N)
Space Complexity : O(N)

Argument: Array 
return : int 

*/

import java.util.Scanner;

class Profit {
    // Returns maximum profit
    // with two transactions on a
    // given list of stock prices,
    // price[0..n-1]
    static int maxProfit(int price[], int n)
    {
        // Create profit array
        // and initialize it as 0
        int profit[] = new int[n];
        for (int i = 0; i < n; i++)
            profit[i] = 0;
 
        /* Get the maximum profit
           with only one transaction
           allowed. After this loop,
           profit[i] contains
           maximum profit from
           price[i..n-1] using at most
           one trans. */
        int max_price = price[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            // max_price has maximum
            // of price[i..n-1]
            if (price[i] > max_price)
                max_price = price[i];
 
            // we can get profit[i]
            // by taking maximum of:
            // a) previous maximum,
            // i.e., profit[i+1]
            // b) profit by buying
            // at price[i] and selling
            // at
            //    max_price
            profit[i] = Math.max(profit[i + 1],
                                 max_price - price[i]);
        }
 
        /* Get the maximum profit
           with two transactions allowed
           After this loop, profit[n-1]
           contains the result
         */
        int min_price = price[0];
        for (int i = 1; i < n; i++) {
            // min_price is minimum
            // price in price[0..i]
            if (price[i] < min_price)
                min_price = price[i];
 
            // Maximum profit is maximum of:
            // a) previous maximum, i.e., profit[i-1]
            // b) (Buy, Sell) at (min_price, price[i]) and
            // add
            // profit of other trans.
            // stored in profit[i]
            profit[i] = Math.max(
                profit[i - 1],
                profit[i] + (price[i] - min_price));
        }
        int result = profit[n - 1];
        return result;
    }
 
    // Driver Code
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int i = sc.nextInt();
        for(int j=0;j<i;j++){
            int n = sc.nextInt();
            int price[]=new int[n];
            String line =br.readLine();
            String[] strs =line.trim().split("\\s+");
            for(int k=0;k<n;k++){
                price[k]= Integer.parseInt(strs[k]);
            }
            System.out.println("Maximum Profit = "
                           + maxProfit(price, n));
        }
    }
 

