/*
Shortest Palindrome Knuth–Morris–Pratt Algorithm 

You are given a string str, you are said that you can convert 
str to a palindrome by adding characters in front of it.
Your task is to return the shortest palindrome 
you can find by performing this type of transformation.
*/

import java.io.*;
import java.util.*;

public class shortestPalindromeFound
{
    //We use Knuth–Morris–Pratt Algorithm to solve this problem
    //KMP is string mapping algorithm that runs in O(n+m) times,
    // where n and m are sizes of the text and string to be searched respectively.
    //we us KMP lookup table to approach the problem

    //function to find the shortest Palindrome
    public String shortestPalindrome(String str)
    {
        //According to question we are only allowed to insert 
        //the characters only at the beginning of the string so, 
        //we can find the largest segment from the beginning that 
        //is a palindrome, and we can easily then reverse the 
        //remaining segment and append it to the beginning 

        //string length
        int size = str.size();
        //reversing the string
        string rev(str);

        reverse(rev.begin(), rev.end());

        //generation of KMP lookup table
        //'#' enables the two strings to not mix up
        string str_new = str + "#" + rev;
        int nNew = str_new.size();
        vector<int> fun(nNew, 0);
        for (int pass = 1; pass < nNew; pass++) 
        {
            int table = fun[pass - 1];
            while (table > 0 && str_new[pass] != str_new[t])
            {
                table = fun[table - 1];
            }
            if (str_new[i] == str_new[table])
            {
                ++table;
            }
            fun[pass] = table;
        }
        //returning reversed string after largest palindrome 
        //from beggininng length
        return rev.substr(0, size - fun[nNew - 1]) + str;
    }

    //driver code 
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        //for input
        System.out.println("Enter the string : ");
        String str = sc.nextLine();
        
        //we pass this string value to the function shortestPalindrome
        //which will calculate the shortest palindrome
        //for output
        System.out.println("Shortest string is : ");
        System.out.print(shortestPalindrome(str));
    }
}

/*
EXAMPLE:-

INPUT--
Enter the string : aacecaaa
OUTPUT--
Shortest string is : aaacecaaa

SPACE COMPLEXITY --> O(N)
TIME COMPLEXITY --> O(N)
*/
