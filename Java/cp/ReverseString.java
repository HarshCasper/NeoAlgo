
/* Program to reverse a string */

import java.io.*;
import java.util.*;
 
// Main class

class Program {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        // Accepting input from user

        System.out.println("Enter string");
        String str = sc.nextLine();

        // revoking the function reverse

        reverse(str);
        
    }

    // Method for reversing the string

    static void reverse(String s){

        // Reversing the string by extracting each element from the end of the string and storing in a variable result

        String result = "";
        for (int i = s.length() - 1; i >= 0; i--)
            result += s.charAt(i);

        // Printing the reversed string

        System.out.println(result);
       
    }

}

/* Time Complexity is O(n)
   Space Complexity is O(n)
   
   Input :
   Hello World
   
   Output :
   dlroW olleH
*/
