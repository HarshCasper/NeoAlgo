/**
 * Length of Longest Substring Without Repeating Characters
 * Given a string, print the longest possible substring that has 
 * no repeating characters, i.e., all its characters are distinct. 
 * Consider a String contains upper and lower case alphabets.
 */

import java.io.*; 
public class LongestSubstringNoRepeatingChar {

    //Function returns true only if each character's count 
    //is <= 1, i.e., substring is valid
    static boolean isDistinct(int[] charCount) {
        for(int i=0; i<52; i++) {
            if(charCount[i] > 1)
                return false; 
        }
        return true; 
    }

    public static int findLongestSubstring(String str) {

        int charCount[] = new int[52]; //Maintains count of each alphabet

        //Variable len stores length of longest valid substring, while start and end
        //are limits of the current window (substring) being considered 
        int len = 0, start=0;
        for(int end=0; end<str.length(); ) {
            char ch = str.charAt(end); 

            if(ch >= 'a' && ch <= 'z') //Lower-case letter
                charCount[ch - 'a']++; 
            else //Upper-case letter
                charCount[ch - 'A' + 26]++;
            end++;

            if(isDistinct(charCount)) {
                len = Math.max(len, end-start);
                continue; 
            }

            //If there are repeating characters, we shorten substring by removing
            //characters from start, till we get a distinct substring.
            while(!isDistinct(charCount)) {
                ch = str.charAt(start); 
                if(ch >= 'a' && ch <= 'z')
                    charCount[ch - 'a']--; 
                else
                    charCount[ch - 'A' + 26]--;
                start++; 
            }
            len = Math.max(len, end-start); 
        }
        return len;
    }
    
    public static void main(String[] args) throws IOException{
        InputStreamReader read = new InputStreamReader(System.in);
	    BufferedReader buf = new BufferedReader(read); 

        //Taking input from user
        System.out.println("Enter a String of alphabets: ");
        String str = buf.readLine().trim();  

        System.out.println("Length of longest substring with no repeating" +
                        " characters: " + findLongestSubstring(str)); 
    }

}

/*
    Time complexity: O(Length of String)
    Space complexity: O(52) (total number of lower and upper case alphabets)

    TEST CASES

    INPUT
    Enter a String of alphabets: 
    pqrsqptrot
    OUTPUT
    Length of longest substring with no repeating characters: 6

    INPUT
    Enter a String of alphabets: 
    trialAndErroR
    OUTPUT
    Length of longest substring with no repeating characters: 9

 */
