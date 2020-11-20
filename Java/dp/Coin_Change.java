import java.io.*; 
import java.util.*;

public class demo{                                              
    public static  Integer change(Integer amount, Integer[] coins) {        //Bottomup dp
         if (amount == 0) return 1;                                         //base case if no coin is selected,then there can be one way only ie. not selecting any coin
        
        int[][] dp = new int[coins.length + 1][amount + 1];                 //dp[i][j] represents the amount of coin combinations within first i coins to get j amount
        for (int i = 0; i <= coins.length; i++) dp[i][0] = 1;
        
        for (int i = 1; i <= coins.length; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];                               //dp[i - 1][j] Not selecting the i th coin , let the other coins form j
                } else {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];     //dp[i][j - coins[i - 1]] select i th coin one or multiple times to form j, we take using i th coin into consideration every time
                }
            }
        }
        return dp[coins.length][amount];
    }
 
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        Integer n = sc.nextInt();

        ArrayList<Integer> li = new ArrayList<Integer>(); 
        while(true){
            System.out.println("Please enter coin value: ");  //enter coin values
            li.add(sc.nextInt());
            System.out.println("Do you want to add more yes/no?");
            String answer = sc.next(); 

            if (answer.equals("no")){
                break;
            }
        }
        Integer arr[] = new Integer[li.size()]; //converting arraylist to array
        arr = li.toArray(arr);

        System.out.println(change(n,arr));
    }
}


/*
Sample Test Case
Input:
N = 4
S = {1,2,3}

Explanation
there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}

Output
4

Input
N = 10
S = {2, 5, 3, 6}

Explanation
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}

Output
5
*/
