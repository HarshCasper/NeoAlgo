import java.util.*;

public class FirstNonRepeatingChar {

    private static int firstNonRepeating(String str) {
        int len = str.length();
        int result = Integer.MAX_VALUE;
        HashMap<Character, CountIndex> countEachChar
            = new HashMap<Character, CountIndex>(len);
        
        for (int i = 0; i < len; i++) {
            if (countEachChar.containsKey(str.charAt(i))) {
                // if the character already exists in the hashmap,
                // we increment the counter for it by one
                countEachChar.get(str.charAt(i)).incrementCount();
            } else {
                // if first occurrence, then create an entry for it
                countEachChar.put(str.charAt(i), new CountIndex(i));
            }
        }

        for (Map.Entry<Character, CountIndex> entry : countEachChar.entrySet()) 
        {
            // checking all entries for repetition. If all repeating,
            // then Integer.MAX_VALUE is returned
            int c = entry.getValue().count; 
            int ind = entry.getValue().index; 
            if(c == 1 && ind < result) 
            { 
                result = ind; 
            } 
        } 
        return result;
    }
    
    public static void main(String[] args) {
        // taking String input
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        String str = sc.nextLine();
        sc.close();

        int result = firstNonRepeating(str);

        System.out.println(result == Integer.MAX_VALUE
            ? "Either all characters repeat atleast once or String is empty"
            : "First non-repeating char:" + str.charAt(result) + " at index " + result);
    }
}

class CountIndex { 
    int count, index; 
  
    // constructor for first occurrence 
    public CountIndex(int index) 
    { 
        this.count = 1; 
        this.index = index; 
    } 
  
    // method for updating count 
    public void incrementCount() 
    { 
        this.count++; 
    } 
}
/**
 * Sample input/output:
 * Enter a string:
 * aabcdb
 * First non-repeating char:c at index 3
 * 
 * Enter a string:
 * lovetocode
 * First non-repeating char:l at index 0
 * 
 * Time complexity: O(n)
 * Since we need to go through the whole string at least once
 * Space complexity: O(n)
 * Space used for storing the String hashmap for keeping a track of frequency
 */
