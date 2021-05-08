/*
Minimum Window Substring

You are given two strings str1 and str2, your task 
is to return the minimum number of windows in str1 which 
will contain all the characters present in str2.
If there is no such window present in str1 that covers 
all the characters of str2 then return an empty string " ".
It is also mentioned that if there is such a window 
then it is guaranteed that there will always be only 
a unique minimum window in str1.
*/

import java.io.*;
import java.util.*;
import java.util.HashMap;

public class MinimumWindowSubstring
{
    //function to find the minimum window
    public String minWindow(String str1, String str2)
    {
        //we basically use two pointer approach 
        //right pointer expands the current window and 
        //the left pointer contracts the given window.
        //we keep expanding the window, when the window has all
        //the desired charcters we contract it ans save it
        
        //for an empty string there is no minimum window 
        //so empty string is returned
        if (str1.length() == 0 || str2.length() == 0) 
        {
            return "";
        }

        //dictionary keeps a count of all unique characters in str2
        Map<Character, Integer> dictionaryStr2 = new HashMap<Character, Integer>();
        for (int pass = 0; pass < str2.length(); pass++)
        {
            int count = dictionaryStr2.getOrDefault(str2.charAt(pass), 0);
            dictionaryStr2.put(str2.charAt(pass), count + 1);
        }
        //requiredChar indicates the number of unique characters in str2
        //which ought to be present in window we desire for.
        int requiredChar = dictionaryStr2.size();
        //The approach that we use over here is that we create a 
        //filterStr1 list which contains all the charcters from 
        //str1 along with there indecies in str1
        //but these characters must be present in str2.
        List<Pair<Integer, Character>> filterStr1 = new ArrayList<Pair<Integer, Character>>();
        for (int pass = 0; pass < str1.length(); pass++)
        {
            char chr = str1.charAt(pass);
            if (dictionaryStr2.containsKey(chr)) 
            {
                filterStr1.add(new Pair<Integer, Character>(pass, chr));
            }
        }

        //left and right pointers
        int lftptr = 0, rghptr = 0;
        //formed keeps track of how many unique characters in str2
        //are present in the current window in its desired frequency.
        int formed = 0;
        //windowCounts stores the count of all unique characters in current window 
        Map<Character, Integer> windowCounts = new HashMap<Character, Integer>(); 
        //res list is of the form (windowlength, left pointer, right pointer)
        int[] res = {-1, 0, 0};

        //here the approach that we adopt is that we try
        //to look for the characters only in the filtered list, reducing our search
        while (rghptr < filterStr1.size()) 
        {
            //adding one character from the right 
            char c = filterStr1.get(rghptr).getValue();
            int count = windowCounts.getOrDefault(c, 0);
            windowCounts.put(c, count + 1);
            //if the frequency of the current character added equals to the
            //desired count in str2 then increment the formed count by 1.
            if (dictionaryStr2.containsKey(c) && windowCounts.get(c).intValue() == dictionaryStr2.get(c).intValue())
            {
                formed++;
            }
            // we try to contract the window till the point where it ceases to be 'desirable'.
            while (lftptr <= rghptr && formed == requiredChar) 
            {
                c = filterStr1.get(lftptr).getValue();
                // we save the smallest window obtained till now.
                int end = filterStr1.get(rghptr).getKey();
                int start = filterStr1.get(lftptr).getKey();
                if (res[0] == -1 || end - start + 1 < res[0]) 
                {
                    res[0] = end - start + 1;
                    res[1] = start;
                    res[2] = end;
                }
                //the character present at the position pointed by left pointer 
                //is no more a part of the window so just not including it.
                windowCounts.put(c, windowCounts.get(c) - 1);
                if (dictionaryStr2.containsKey(c) && windowCounts.get(c).intValue() < dictionaryStr2.get(c).intValue()) 
                {
                    formed--;
                }
                //Next, we shift the lftptr ahead for looking into new window
                lftptr++;
            }

            //we keep expanding the window once we are done with the
            //contracting part
            rghptr++;   
        }

        return res[0] == -1 ? "" : str1.substring(res[1], res[2] + 1);
    }

    //driver code
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        //for input
        System.out.println("Enter the first string: ");
        String str1 = scanner.nextLine();
        System.out.println("Enter the second string: ");
        String str2 = scanner.nextLine();
        //for output
        System.out.println("The Minimum window substring thus obtained is: ");
        System.out.print(minWindow(str1, str2));
    }
} 

/*
EXAMPLE:
Input--
Enter the first string: ADOBECODEBANC
Enter the second string: ABC
Output--
The Minimum window substring thus obtained is: BANC

TIME COMPLEXITY --> O(∣str1∣ + ∣str2∣) 
SPACE COMPLEXITY --> O(∣str1∣ + ∣str2∣) 
*/
