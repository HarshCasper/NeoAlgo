import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 1) return 1;
        
        ArrayList<Character> arrLL = new ArrayList<>();
        int si = 0;
        int ei = 0 ;
        int currlen = 0;
        int maxlen = 0;
        
        while (ei < s.length() && si < s.length()){

            if (!arrLL.contains(s.charAt(ei))){
                arrLL.add(s.charAt(ei));
                 ei++;
                currlen = ei - si;
                if (maxlen < currlen) maxlen = currlen;
            }

            else{
                arrLL.remove(Character.valueOf(s.charAt(si)));
                si++;
            }
        }
        return maxlen;
    }
}

/*
TIME COMPLEXITY O(N) where n is length of the the given string
SPACE COMPLEXITY O(1)

TEST CASE

INPUT
s = "bbbbb"
OUTPUT
1

INPUT 
s = "abcabcbb"
OUTPUT
3

*/

