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
    static int  LongestCommonSubstring(char a[], char b[], int x, int y){

        int arr[][] = new int[x + 1][y + 1];            // matrix or table to store the length of longest common suffixes of substrings
        int ans = 0;                                   // ans is a variable which stores the length of longest common substring till now
        for(int i = 0; i <= x; i++){                  // filling the matrix using dynamic programming
            for(int j = 0; j <= y; j++){
                if(i == 0 || j == 0){
                    arr[i][j] = 0;
                }
                else if(a[i-1] == b[j-1]){
                    arr[i][j] = arr[i-1][j-1] + 1;
                    ans = Integer.max(ans, arr[i][j]);
                }
                else{
                    arr[i][j] = 0;
                }
            }
        }
        return ans;                                     // returning the length
    }   

	public static void main (String[] args) throws java.lang.Exception{
	        Scanner sc = new Scanner(System.in); 
            String s1 = sc.nextLine();                 //input the first string
            String s2 = sc.nextLine();                // input the second string
            
            int size1 = s1.length();                // length of first string
            int size2 = s2.length();                //length of second string
 
            System.out.println(LongestCommonSubstring(s1.toCharArray(), s2.toCharArray(), size1, size2));   //calling the function for the length
	}
}

/*
Test Case 1:
Input:
helloword
loperd
Output: 2
      
Test Case 2:
Input:
Towerofhanoi
Ofhand
Output: 4
      
Time Complexity: O(size1*size2)

Space Complexity: O(size1*size2)
*/
