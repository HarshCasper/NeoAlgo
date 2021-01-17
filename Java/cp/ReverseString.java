import java.lang.*;
import java.io.*;
import java.util.*;
 
// Class of ReverseString
class ReverseString {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        // Accepting input from user

        System.out.println("Enter string");
        String str = sc.nextLine();
        String result = "";
          
        // Reversing the string by extracting each element from the end of the string and storing in a variable result

        for (int i = str.length() - 1; i >= 0; i--)
            result += str.charAt(i);

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