import java.util.*;
import java.lang.*;
import java.io.*;

class String_to_int {
    public int myAtoi(String str) {
        if (str.length() == 0) return 0;
        
        String ans = "";
        if (str.length() > 2 ){     // for TESTCASE "+-6"
            if (str.charAt(0) == '-' && str.charAt(1) == '+') return 0;
            if (str.charAt(1) == '-' && str.charAt(0) == '+') return 0;
        }
        
        for (int i = 0 ; i < str.length(); i++){
	    
	    // ith Character of String str 
            char c = str.charAt(i);
            if (ans.length() > 0 && !(c >= '0' && c <= '9')) break;
            else if (str.charAt(i) == ' ') continue;
            else if (str.charAt(i) == '-') ans += str.charAt(i);
            else if (str.charAt(i) == '+') ans += str.charAt(i);
            
            else if (c >= '0' && c <= '9') ans += c;
            else if (ans.length() == 0 && !(c >= '0' && c <= '9')) break;
           
        }
        
        if (ans.length() == 0) return 0;
        if (ans.equals("-") || ans.equals("+")) return 0;
        // if (ans.length() > 9) 
        
        int max = Integer.MAX_VALUE;
        int digits_max = (int)Math.floor(Math.log10(max) + 1);  // hete it is 9 always 
        
        int min = Integer.MIN_VALUE;
        
        long count_0 = 0;
        for (int  i= 0 ; i < ans.length(); i++){
            if (ans.charAt(i) == '-' || ans.charAt(i) == '+') {
                count_0 ++;
                continue;
            }
            if (ans.charAt(i) != '0') break;
            count_0 ++;
            
        }
        
        if (ans.length() - count_0 > digits_max){
            if (ans.charAt(0) == '-') return min;
            return max;
        }
        
        long temp = Long.parseLong(ans) ;
        if (temp > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        else if (temp < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        
         return Integer.valueOf(ans);
    }
}

/*
TEST CASE

TIME COMPLEXITY : 0(N) 
SPACE COMPLEXITY: 0(N)

where N is length of given string

INPUT
"   -42"

OUTPUT
-42

INPUT
 "\n 12 4193 with words"

OUTPUT
0

INPUT
 "words and 987"

OUTPUT
0
*/

