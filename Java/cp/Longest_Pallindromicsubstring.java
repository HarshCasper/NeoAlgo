
/* This is a Java program  to find the longest palindromicsubstring from a word using dynamic programming approach

Pallindromic substring means a part of a word which reads the same backward as forward.
There may be more than one pallindromic substring in a word but this program gives the longest pallindromic
substring in terms of length.
*/
import java.util.*;
 
class PallindromicSubstr{

    public static String expandbothside(String str, int low, int high)
    {
        int len = str.length();
     
        // expand in both directions
        while (low >= 0 && high < len &&
            (str.charAt(low) == str.charAt(high))) {
                low--;
                high++;
            }
            return str.substring(low + 1, high);
    }
     
        
        public static String longestPallindromeSubstr(String str, int len)
        {
            // `max_str` stores the maximum length palindromic substring     
            String max_str = "", curr_str;
     
            // `max_length` stores the maximum length of palindromic     
            int max_len = 0, curr_len;
     
            for (int i = 0; i < len; i++)
            {
                // find the longest odd length palindrome with `str[i]` as a midpoint
     
                curr_str = expandbothside(str, i, i);
                curr_len = curr_str.length();    
     
                // update maximum length palindromic substring if odd length palindrome has a greater length
     
                if (curr_len > max_len)
                {
                    max_len = curr_len;
                    max_str = curr_str;
                }

                curr_str = expandbothside(str, i, i + 1);
                curr_len = curr_str.length();
     
                // update maximum length palindromic substring if even length palindrome has a greater length
     
                if (curr_len > max_len)
                {
                    max_len = curr_len;
                    max_str = curr_str;
                }
            }
     
            return max_str;
        }
 
public static void main(String[] args)
{
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter word");
    String str = sc.nextLine();
    System.out.print("\nLength of longest pallindrome substring is: "
         + longestPallindromeSubstr(str,str.length() - 1));
}
}

/* Time complexity is O(n*n)
Space complexity is O(1)

Input :
Enter word
mallammalayalamaaabbaa

output:
Length of longest pallindrome substring is: malayalam
*/
