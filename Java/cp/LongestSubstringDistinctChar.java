/**
 * Longest Substring with K Distinct Characters
 * Given a string, print the longest possible substring that 
 * has exactly K unique characters. 
 */

import java.io.*;
public class LongestSubstringDistinctChar {

    static final int CHAR_COUNT = 26;

    public static String findLongestSubstring(String str, int K) {

        String result = ""; 
        int distinct = 0; //Counter for number of distinct letters encountered

        int charCount[] = new int[CHAR_COUNT]; //Array maintains current count of each letter

        //Variable len stores length of longest valid substring, while start and end
        //are limits of the current window (substring) being considered 
        int len = 0, start=0; 
        for(int end=0; end<str.length();) {

            //Updating count of distinct characters
            if(charCount[str.charAt(end) - 'a'] == 0) 
                distinct++; 

            //Updating count of current letter
            charCount[str.charAt(end) - 'a']++; 
            end++;

            if(distinct == K) {
                if((end-start) > len) {
                    len = end-start; 
                    result = str.substring(start, end); 
                }
            } else if(distinct > K) {

                //If number of distinct characters exceeds K, we shorten the 
                //substring by removing characters from the front
                while(distinct > K && start<end) {
                    if(charCount[str.charAt(start) - 'a'] == 1) {
                        distinct--; 
                    }
                    charCount[str.charAt(start) - 'a']--; 
                    start++;
                }
                if(distinct == K) {
                    if((end-start) > len) {
                        len = end-start; 
                        result = str.substring(start, end); 
                    }
                }

            }
        }

        //In absence of any valid substring, "-1" is returned
        return (len==0)? "-1": result;
    }
    
    public static void main(String[] args) throws IOException {
        InputStreamReader read = new InputStreamReader(System.in);
	    BufferedReader buf = new BufferedReader(read); 

        //Taking input from user
        System.out.println("Enter a String of lower case alphabets: ");
        String str = buf.readLine().trim();  
        System.out.println("Enter number of distinct characters: ");
	    int K = Integer.parseInt(buf.readLine()); 
	    
        //Printing output
        System.out.println("Longest substring with " + K + " distinct characters: "); 
        System.out.println(findLongestSubstring(str, K)); 
    }

}

/*
    Time complexity: O(N)
    Space complexity: O(CHAR_COUNT) (as there are 26 lower case English 
    alphabets, here, CHAR_COUNT = 26)

    TEST CASES

    INPUT
    Enter a String of lower case alphabets:
    abckefcaxyzzxxo
    Enter number of distinct characters: 
    3
    OUTPUT
    Longest substring with 3 distinct characters: 
    xyzzxx

    INPUT
    Enter a String of lower case alphabets:
    kkkkrrrr
    Enter number of distinct characters: 
    4
    OUTPUT
    Longest substring with 4 distinct characters: 
    -1

 */
