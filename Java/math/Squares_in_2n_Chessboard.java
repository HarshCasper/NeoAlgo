/**
Find total number of Squares in a N*N cheesboard.
 */

import java.io.*;
import java.util.*;

class Code{
    public static void main(String args[]) throws IOException{
        // taking input 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the num")
        Long num = Long.parseLong(read.readLine());
        Sol obj = new Sol();
        System.out.println("The square : ")
        System.out.println(obj.squares(num));
    }
}
class Sol {
    // using maths logic
    static Long squares(Long n) {
       return  (long) (n*(n+1)*(2*n+1))/6;
    }
};

/*
Time complexity : O(N)
Space complexity : O(1)
*/

/*
Input :
Enter the number :  1
Output :
The square is : 1
*/
