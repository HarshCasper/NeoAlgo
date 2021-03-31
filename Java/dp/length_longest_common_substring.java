/*Longest Common Substring
Problem statement: Given two string s1 and s2, find the length of longest common substring of these two strings.
                   Substring - Contegeous sequence of characters within a string.Note that the string are case sensitive.
                   For e.g hello and Hello will have only 4, length of longest common substring since H and h are different.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class LengthOfSubstring{

    // function to return the length of longest common substring
   public static void  LongestCommonSubstring(){
        Scanner sc = new Scanner(System.in);
        
        int cnt = 0;    //cnt is a variable to store the length of common substring
        String s1 = sc.nextLine();                 //input the first string from user
        String s2 = sc.nextLine();                // input the second string from user

        int fin_tab[][] = new int[s1.length() + 1][s2.length() + 1];            // matrix or table to store the length of longest common suffixes of substrings
        // filling the matrix using dynamic programming
        for(int itr1 = 1; itr1 < fin_tab.length; itr1++){                  
            for(int itr2 = 1; itr2 < fin_tab[0].length; itr2++){
                char str1 = s1.charAt(itr1 - 1);
                char str2 = s2.charAt(itr2 - 1);

                if(str1 == str2){
                     fin_tab[itr1][itr2] = fin_tab[itr1-1][itr2-1] + 1;
                }
                else {
                    fin_tab[itr1][itr2] = 0;
                }
                if(fin_tab[itr1][itr2] > cnt){
                    cnt = fin_tab[itr1][itr2];
                }
            }
        }     
        System.out.print("Length is " + cnt);
    }   

	public static void main (String[] stringcom){
            LongestCommonSubstring();   //calling the function for the length
	}
}

/*
Test Case 1:
Input:
helloword
loperd
Output: Length is 2
      
Test Case 2:
Input:
Towerofhanoi
Ofhand
Output: Length is 4
      
Time Complexity: O(size1*size2)

Space Complexity: O(size1*size2)
*/
