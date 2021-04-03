/*
 * Problem Statement : Find substring of the string.
 * Substring is a contiguous sequence of characters within a string,will find substring of the particular string by 
 * starting(beginning_index) till ending index So, we have used following substring method to find it out.
 * We want substring with ending index then we have to increment it's index by 1.
 */

import java.util.*;
public class Solution 
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        //Taking input from the user i.e string	
        String S = sc.next();
        //Taking user input for finding substring by using substring function	
        int start = sc.nextInt();
        int end = sc.nextInt();
        //Created new String to store the result
        String s = S;
        //substring will start from start index, ended at end
        s = S.substring(start,end+1);
        //Display the result
        System.out.println(s);
	 
    }
}

/*
Input:
HelloWorld
3 6

Output:
loWo

Time complexity = O(n)
Space complexity = O(n)

*/
