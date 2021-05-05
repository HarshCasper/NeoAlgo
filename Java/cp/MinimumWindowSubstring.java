/**
 * Minimum Window Substring 
 *          OR
 * Smallest Window in a String Containing All Characters of Another String
 * Given two strings string1 and string2, find the smallest substring in 
 * string1 containing all characters of string2. 
 */

import java.io.*;
public class MinimumWindowSubstring {
    
    static final int CHAR_COUNT = 26; 

    //Checking if all characters in pattern are contained in substring
    //or not
    public static boolean isValid(int[] str, int[] pattern) {
        for(int i=0; i<CHAR_COUNT; i++) {
            if(str[i] < pattern[i])
                return false; 
        }
        return true; 
    }

    public static String findSmallestSubstring(String str, String pattern) {

        //To store count of characters in str and pattern, respectively
        int strCount[] = new int[CHAR_COUNT];
        int ptrCount[] = new int[CHAR_COUNT]; 

        //Counting number of occurrences of each character in pattern
        for(int i=0; i<pattern.length(); i++) 
            ptrCount[pattern.charAt(i) - 'a']++; 

        int end, start;
        end = start = 0;
        String result = "-1"; //If no valid substring is found, "-1" is returned

        //start and end are pointers for start and end of substring
        while(end < str.length()) {

            //When substring does not contain all characters of pattern, we 
            //expand substring by adding characters from the end
            if(!isValid(strCount, ptrCount)) {
                strCount[str.charAt(end) - 'a']++; 
                end++; 
                continue; 
            } 

            //Updating substring contained in result
            if(result.equals("-1") || result.length() > (end - start))
                result = str.substring(start, end); 

            //To get length of smallest valid substring, we shorten the substring 
            //from front (i.e., eliminate characters from start)
            strCount[str.charAt(start) - 'a']--; 
            start++; 
        }

        //For the substrings which end at (str.length() - 1)
        while(isValid(strCount, ptrCount)) {
            if(result.equals("-1") || result.length() > (end - start))
                result = str.substring(start, end);
            strCount[str.charAt(start) - 'a']--; 
            start++;
        }

        return result; 
    }

    public static void main(String[] args) throws IOException {
        InputStreamReader read = new InputStreamReader(System.in);
	    BufferedReader buf = new BufferedReader(read); 

        //Taking input from user
        System.out.println("Enter a String text: ");
        String str = buf.readLine().trim();  
        System.out.println("Enter a String pattern: ");
        String pattern = buf.readLine().trim(); 

        //Printing output
        System.out.println("Smallest substring in text, containing all " +
                            "characters in pattern: ");
        System.out.println(findSmallestSubstring(str, pattern)); 
    }

}

/*
    Time complexity: O(N) (considering that isValid() method works in constant 
                        time as it makes a fixed number of comparisons) 
    Space complexity: O(CHAR_COUNT) 

    TEST CASES

    INPUT
    Enter a String text: 
    zaaskzaa
    Enter a String pattern: 
    zsk
    OUTPUT
    Smallest substring in text, containing all characters in pattern: 
    skz

    INPUT
    Enter a String text: 
    pompandpageantrygalore
    Enter a String pattern: 
    gtyn
    OUTPUT
    Smallest substring in text, containing all characters in pattern: 
    ntryg

 */
