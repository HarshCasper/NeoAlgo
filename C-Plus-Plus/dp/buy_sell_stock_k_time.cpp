/*
 * PROBLEM STATEMENT: You are required to print the maximum profit you can make if you are allowed k transactions at-most.
 * One transaction needs to be closed before opening another transaction ie we can only have - buy->sell->buy->sell.
 *
 * INPUT:
 * int n - the number of days for which transactions are to be made
 * int k - the number of non-overlapping transactions to be made
 * int A[n] - array containing the price for each day of the stock
 *
 * OUTPUT: Output a single integer which is the maximum profit made if allowed k transactions at most.
 *
 */

#include <iostream>
#include<bits/stdc++.h>


using namespace std;


void solve(int n, int k, int P[]){

    int dp[k + 1][n];
    memset(dp, 0, sizeof dp); //very important to initialise 0 to avoid garbage values during comparison.


    /*
    *
    * So here we prepare a double dimensional array called dp which will have:
    * rows--> best profit made upto a column_number day by making nth transaction
    * columns--> representing the best profit made by using row_number of transactions
    *
    *                          ith day     ___     ___     ___
    *          jth_transaction
    *          0                           0       0       0
    *          1                           v11     v12     v13
    *          2
    *          .
    *          .
    *          k
    *
    *
    *
    *          Now any (i,j) element in the above matrix represents the best profit made until ith day using j transactions.
    *          The (i,j) result will depend upon the (i-1,j) cell and all the cell of j-1 column before i ie in j-1 from 0 to i-1,
    *          because we can either make the final transaction on (i,j) after previous day (i-1,j)'s best transaction or after
    *          the k-1th transaction on any i-1'th day.
    *          So we compare the buying and selling point of the above and check for the best profit made till today.
    *
    *          We run nested for loops to implement above logic. Here we keep track of maximum profit made till today and
    *          maximum profit made on the same day, and we store only the maximum profit made till today in our dp[][].
    *
    */




    for (int transaction = 1; transaction <= k; transaction++) {
        for (int day = 1; day < n; day++) {

            int max = dp[transaction][day - 1];

            for (int prevday = 0; prevday < day; prevday++) {
                int prev_profit = dp[transaction - 1][prevday];
                int curr_profit = P[day] - P[prevday];

                if (prev_profit + curr_profit > max)
                    max = prev_profit + curr_profit;
            }

            dp[transaction][day] = max;
        }
    }

    cout << dp[k][n - 1] << endl;


}




int main() {

    int n, k;
    cin >> n >> k; // taking inputs for number of days and the number of transactions.

    int P[n];

    for (int i = 0; i < n; i++)
        cin >> P[i];

    solve(n,k,P); // Calling the function to output the answer.

}