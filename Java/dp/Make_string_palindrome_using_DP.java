/*
    Given a String, find the minimum number of characters that need to be deleted to make the 
    resultant String a Palindrome and also print these characters.
*/
/*
    Basic Idea to solve this problem:- We find the Longest Common Subsequence of given string and its reverse. The resultant 
    sequence is now just matched with the original string and the missing characters will be the ones that need to be deleted
    from the original string to make it a palindrome.
*/

import java.util.*;

public class Make_string_palindrome_using_DP {
    //Function to calculate maximum out of 2 nos
    public static int maximum(int a, int b){
        return (a>=b) ? a : b;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string:- ");
        
        String s1 = sc.nextLine();

        StringBuilder s = new StringBuilder();
        s.append(s1);
        s.reverse();
        String s2 = s.toString();

        longest_common_subsequence(s1, s2);
    }

    public static void longest_common_subsequence(String s1, String s2){
        //Cost Matrix for finding the Longest Common Subsequence for Original string and its reverse
        int cost[][];
        cost = new int[s1.length() + 1][s2.length()+1];

        //Recurrence Relation for LCS:- 
        // if str1[i-1] == str2[j-1] -> cost[i][j] = 1 + cost[i-1][j-1]
        // else -> max(cost[i-1][j], cost[i][j-1)

        for (int i = 0; i<=s1.length(); i++) {
            for (int j = 0; j<=s2.length(); j++) {
                if(i == 0 || j == 0){
                    cost[i][j] = 0;
                }
                else if(s1.charAt(i-1) == s2.charAt(j-1)){
                    cost[i][j] = 1 + cost[i-1][j-1];
                }
                else {
                    cost[i][j] = maximum(cost[i-1][j], cost[i][j-1]);
                }
            }
        }

        System.out.println("\nLongest length Matrix for two subsequences:- ");
        
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <=s2.length(); j++) {
                System.out.print(cost[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println("\n");
        // Getting the LCS by backtracking the Cost matrix
        String s = extracting_longest_subsequence_using_backtracking(cost, s1, s2).toString();
        print_chars_to_be_removed_for_palindrome(s, s1);
    }

    public static void print_chars_to_be_removed_for_palindrome(String lcs, String original_str){
        int count = 0;
        System.out.print("Characters to be delted:- ");
        for(int i = 0; i<original_str.length(); i++){
            if(lcs.contains("" + original_str.charAt(i))){
                continue;
            }
            else{
                System.out.print(original_str.charAt(i) + " ");
                count++;
            }
        }
        System.out.println("\nMinimum no of characters to be deleted:- " + count);
    }

    public static StringBuilder extracting_longest_subsequence_using_backtracking(int c[][], String s1, String s2){
        String output_str = new String("");
        StringBuilder output = new StringBuilder();
        int i = s1.length();
        int j = s2.length(); 
        //If while traversing the characters at i and j are same then go back diagonally 
        //else find max from (i-1, j) and (i, j-1) and traverse to that position just like how we did while filling the matrix
        //and when the characters of the two strings were not same. 
        while(i > 0 && j > 0){
            if(s1.charAt(i-1) == s2.charAt(j-1)){
                output_str = output_str + "" + s1.charAt(i-1);
                i -= 1;
                j -= 1;
            }
            else if(c[i-1][j] > c[i][j-1]){
                i -= 1;
            }
            else{
                j -= 1;
            }
        }
        output.append(output_str);
        output.reverse();
        return output;
    }
}
/*
    Time Complexity:- O(n*m) where 'n' is length of String 1 and 'm' is the length of String 2
    Space Complexity:- O(n*m) since we are creating the Cost matrix
*/

/*
Sample Testcase: 
Enter the string:- 
NITIXN

Output:-
Longest length Matrix for two subsequences:- 
0       0       0       0       0       0       0       
0       1       1       1       1       1       1       
0       1       1       2       2       2       2       
0       1       1       2       3       3       3       
0       1       1       2       3       4       4       
0       1       2       2       3       4       4       
0       1       2       2       3       4       5       


Characters to be delted:- X
Minimum no of characters to be deleted:- 1
*/