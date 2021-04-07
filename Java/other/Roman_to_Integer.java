import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner abc = new Scanner(System.in);
        System.out.println("ENTER YOUR ROMAN NUMERAL:"); // INPUT TO BE A ROMAN NUMERAL BETWEEN INTEGERS(1-3999)
        String s = abc.next();
        HashMap < Character, Integer > map = new HashMap < > (); //USING MAP TO STORE PREDEFINED ROMAN CHARACTERS
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i != 0 && (map.get(s.charAt(i)) > map.get(s.charAt(i - 1))))
                result += map.get(s.charAt(i)) - 2 * map.get(s.charAt(i - 1));
            else
                result += map.get(s.charAt(i));
        }
        System.out.println("YOUR ANSWER IS:" + result);
    }
}
/*
Sample Test Case
INPUT:
ENTER YOUR ROMAN NUMERAL:III
OUTPUT:
YOUR ANSWER IS:3
ENTER YOUR ROMAN NUMERAL:MII
OUTPUT:
YOUR ANSWER IS:1002
ENTER YOUR ROMAN NUMERAL:MLIV
OUTPUT:
YOUR ANSWER IS:1054
*/
