/*
Description
> Given a number n, representing the count of elements.
> Given n numbers.
> Given a number "target".
> Required to calculate and print true or false, if there is a subset the elements of which add 
     up to "target" or not.
     
 */
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        
        int[] arr = new int [n];
          for(int i=0; i < arr.length; i++)
          {
          arr[i] = scn.nextInt();
           }
      
        int tar = scn.nextInt();
      
        boolean [][]dp = new boolean [n+1][tar+1];
        for(int i =0; i<dp.length; i++){
        
         for(int j =0;j<dp[0].length;j++){
           
           if(i==0 && j==0){
             dp[i][j] = true;
            } else if(i==0){
                dp[i][j] = false;
            } else if(j==0) {
               dp[i][j] = true;
            } 
            else {
              if(dp[i-1][j] == true ){ 
              dp[i][j] = true;
               } else {
                         int val = arr[i-1];
                         if(j>=val){
                           if(dp[i-1][j-val] ==true) {
                                  dp [i][j] = true;}
                                             }
                                          }
                                       }
                                   }
                                }
        System.out.println(dp[arr.length][tar]);
       }
  }

/*
Sample Case :-
INPUT
5
4
2
7
1
3
10

OUTPUT
true
*/
