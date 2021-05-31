/**
Amicable numbers are two different numbers so related that the sum of the proper divisors of each is equal 
to the other number. (A proper divisor of a number is a positive factor of that number other than the number 
itself. Given two Numbers A and B, find whether they are Amicable Numbers or not. Print 1 if they are Amicable 
else 0.
 */

import java.io.*;
import java.util.*;

class Code{
    public static void main(String args[]) throws IOException{
        // taking input 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the  a and b")
        // reading input
        String S[] = read.readLine().split(" ")
        int A = Integer.parseInt(S[0]);
        int B = Integer.parseInt(S[1]);
        Sol obj = new Sol();
        // printing the output 
        System.out.println("The  Ampicable pair : ")
        System.out.println(obj.isAicable(A,B));
    }
} 


class Sol {
    //  to get the sum of all proper divisors of a number.
    static long divsum(int n)
    {
        long result = 0;
        for (int i = 2; i <= (int)Math.sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (i == (n / i))
                    result += i;
                else
                    result += (i + n/i);
            }
        }
        return (result + 1);
    }
    
    static int isAmicable(int A , int B) {
        
        // If and only if sum of proper divisors of A is equal to B 

        if(A!=B && divsum(A)==B && divsum(B)==A)    
            return 1;
        else
            return 0;
    }
};

/*
Time complexity : O(sqrt(A,B))
Space complexity : O(1)
*/

/*
Test Case : 
     Test case 1 :
     Enter the a and b
      220  284
    Test case 2 : 
    Amicable Pair : 
    1
*/

