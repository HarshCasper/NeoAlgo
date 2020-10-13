/**
 * This program implements the Knuth–Morris–Pratt string-searching algorithm which searches
 * for occurrences of a "word" W within a main "text string" S by employing the observation
 * that when a mismatch occurs, the word itself embodies sufficient information to determine 
 * where the next match could begin, thus bypassing re-examination of previously matched 
 * characters.
 *
 * For more information visit: https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
 *
 *
 * Time Complexity: O(n+m)                n -> Length of Text String
 * Space Complexity: O(m)                 m -> Length of Pattern String
 * 
 * 
 * Sample Input :- 
 *    	Text String - "aabaacaadaabaaba"
 *    	Pattern String - "aaba"
 *   
 * Expected Output :-
 *		Pattern found at index: 0
 *		Pattern found at index: 9
 *		Pattern found at index: 12
 */

import java.util.Scanner;

public class KMP_Algorithm {
	
	// To compute the longest prefix suffix array 
	static int[] computeLPS(String patt)
	{
		// length of pattern String
		int len = patt.length();
		
		int i, j;
		int[] lps = new int[len];
		
		// LPS of length 1 String is always 0
		lps[0] = 0;
		
		i = 1;
		j = 0;
		while(i < len)
		{
			if(patt.charAt(i) == patt.charAt(j))
			{
				lps[i] = j + 1;
				i++;
				j++;
			}
			else
			{
				if(j == 0)
				{
					lps[i] = 0;
					i++;
				}
				else
				{
					j = lps[j - 1];					
				}
			}
		}
		
		return lps;
	}
	
	// Prints all starting index of pattern in text string 
	static void KMPSearch(String txt, String patt)
	{
		int[] lps = computeLPS(patt);
		int i, j;
		int txt_len, patt_len;
		
		// Length of text string
		txt_len = txt.length();
		
		// Length of pattern string
		patt_len = patt.length();
		
		i = j = 0;
		while(i < txt_len)
		{
			if(patt.charAt(j) == txt.charAt(i))
			{
				i++;
				j++;
			}
			else
			{
				if(j == 0)
					i++;
				else
					j = lps[j-1]; 
			}
			
			if(j == patt_len)
			{
				// Printing the staring index of pattern in text string
				System.out.println("Pattern found at index: " + (i - j));
				j = lps[j-1];
			}
		}
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		String patt = "", txt = "";
		
		// Dynamic Input
		System.out.print("Enter Text String: ");
		txt = sc.nextLine();
		System.out.print("Enter Pattern String: ");
		patt = sc.nextLine();
		sc.close();
		
		KMPSearch(txt, patt);
	}
}
