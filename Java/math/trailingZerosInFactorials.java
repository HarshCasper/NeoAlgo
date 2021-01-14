
import java.util.*;

public class trailingZerosInFactorials {

// naive approach 
// approach explaination 
// 1. calculate factorial of a Number
//  2. traverse  factorial till fact%10 ==0 and each traver divide it by 10 and increment the counter

    public static int trailingZerosInFactorialsCounter1(int n){
        int fact = 1;
        for(int i=2; i<=n; i++)
            fact *= i;
            int res =0; 
            while(fact%10 ==0){
                res++;
                fact /=10;
            }
            return res;
    }

    // efficient approach
    // 1. trailing  zeros count always occurs mulitple of 5 so,
    // 2. res = res + n/i and i increment i*5 each time
 public static int trailingZerosInFactorialsCounter2(int n){
         int res =0;
        for(int i=5; i<=n; i=i*5)
                res = res+ n/i;
            return res;
    }
    
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
      int val = scn.nextInt(); 
      System.out.println(trailingZerosInFactorialsCounter1(val));
      System.out.println(trailingZerosInFactorialsCounter2(val));
    }
}

// Note : comment naive or efficient approach if run one of them 

// input 5 ,100
//  output 1, 24
//Space Complexity: O(log n) for efficient
//Time Complexity : O(1)

