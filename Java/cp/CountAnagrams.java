/**
 * Count Occurrences of Anagrams
 * Java program to find the count of occurrences of anagrams
 * of an entered word, in an entered text (given that
 * length of word <= length of text). Both Strings contain
 * only lower case alphabets. 
 */

import java.io.*;
public class CountAnagrams {
    
    private static int countAnagrams(String text, String word) {

        //Integer arrays to store count of characters in word and text
        int wordCharCount[] = new int[26];
        int textCharCount[] = new int[26];
 
        int len = word.length(); 
        for(int i=0; i<len; i++) {
            wordCharCount[word.charAt(i) - 'a']++;
            
            //To obtain count of each character in first window of text
            //The size of window is the length of word
            textCharCount[text.charAt(i) - 'a']++; 
        }

        //If current window of text and given word are anagrams, difference
        //will be 0. Non-zero difference indicates that the count of atleast
        //one of the 26 characters in not equal in text and word.
        int difference = 0;
        for(int i=0; i<26; i++) {
            difference += Math.abs(wordCharCount[i] - textCharCount[i]); 
        }

        //For first window
        int anagramCount = 0; 
        if(difference == 0)
            anagramCount++;

        //To obtain value of difference for each subsequent window of size len
        for(int i=len; i<text.length(); i++) {

            //Previous value associated with character that has exited window 
            //is subtracted. This character's count is updated and the new value 
            //of difference in added to overall difference.  
            difference -= Math.abs(wordCharCount[text.charAt(i-len)-'a'] - 
                                textCharCount[text.charAt(i-len)-'a']);
            textCharCount[text.charAt(i-len) - 'a']--; 
            difference += Math.abs(wordCharCount[text.charAt(i-len)-'a'] - 
                                textCharCount[text.charAt(i-len)-'a']);

            //Previous value associated with character that has entered the window 
            //is subtracted. This character's count is updated and the new value 
            //of difference in added to overall difference.
            difference -= Math.abs(wordCharCount[text.charAt(i)-'a'] - 
                                textCharCount[text.charAt(i)-'a']);
            textCharCount[text.charAt(i) - 'a']++; 
            difference += Math.abs(wordCharCount[text.charAt(i)-'a'] - 
                                textCharCount[text.charAt(i)-'a']);

            if(difference == 0)
                anagramCount++; 
        }

        return anagramCount; 
    }
    public static void main(String[] args) throws IOException {
        InputStreamReader read = new InputStreamReader(System.in);
	    BufferedReader buf = new BufferedReader(read); 

        //Taking input from user
        System.out.println("Enter the text String: ");
	    String text = buf.readLine().trim(); 
        System.out.println("Enter the word whose anagrams need to be counted: ");
	    String word = buf.readLine().trim(); 

        System.out.println("Number of anagrams: " + countAnagrams(text, word)); 
    }

}

/*
    Time complexity: O(N)
    Space complexity: O(1) (as two arrays of fixed size 26 are being used)

    TEST CASES

    INPUT
    Enter the text String: 
    trfororfideriorofrufrx
    Enter the word whose anagrams need to be counted: 
    for
    OUTPUT
    Number of anagrams: 5

    INPUT
    Enter the text String: 
    timetimetime
    Enter the word whose anagrams need to be counted: 
    time
    OUTPUT
    Number of anagrams: 9

 */
