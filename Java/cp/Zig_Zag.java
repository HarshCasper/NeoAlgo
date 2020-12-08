import java.util.*;
import java.lang.*;
import java.io.*;

class ZigZag {
    public String convert(String s, int numRows) {
        
        if (numRows == 1 || numRows >= s.length()) return s; 
        
        ArrayList<String> arrLL = new ArrayList<>();
        
        for (int i = 0; i < Math.min(numRows, s.length()); i++)
            arrLL.add("");
        
        int counter = 0;
        boolean b = false;
        int size = Math.min(numRows, s.length());
        for (char c : s.toCharArray()){
            String str = Character.toString(c);
            String initial = "";
           
            if (counter < arrLL.size() || arrLL.get(counter) != "") {
                initial = arrLL.get(counter);
                arrLL.add(counter, initial + str);
                arrLL.remove(counter+1);
                
            }
            if (counter == 0 || counter + 1 == numRows) b = !b;   
            counter += b ? 1 : -1;     // adding -1 in b if b is false 
                                      // adding 1 in b if b is true
        }
        
        String ans = "";
        for (int i =0; i< arrLL.size(); i++){
            ans += arrLL.get(i);
        }
        
        
        return ans;
    }
}

/*
TIME COMPLEXITY: 0(N) where n is size of string
SPACE COMPLEXITY:0(N) where n is size of string
TEST CASE

INPUT
"PAYPALISHIRING"

OUTPUT
"PAHNAPLSIIGYIR"

INPUT
"PAYPALISHIRING"
4

OUTPUT
"PINALSIGYAHRPI"

*/

