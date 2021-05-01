/*

- Phone Keypad Sequence:
    Given a keypad as shown in the diagram, and an n digit number, list all words which are possible by pressing these numbers.

- Example: 
 
    Input number: 23

    Output: ad ae af
            bd be bf
            cd ce cf

- Approach :

    1. As observed each digit can represent 3 to 4 different alphabets (except 0 and 1)
    2. Map each number with its keypad string equivalent.
    3. Use recrsive function to try all alphabets mapped to the current digit in alphabetic order, and again call the recursive function for the next digit and will pass on the current output string. 

*/

import java.util.Arrays;
import java.util.List;
 
public class KeypadSequence
{
    // Top-down recursive function 
    public static void findCombinations(List<List<Character>> keypad,
                                        int[] input, String result, int index)
    {
        // if we have processed every digit of the key, print the result (base case)
        if (index == -1)
        {
            System.out.print(result + " ");
            return;
        }
 
        // stores the current digit
        int digit = input[index];
 
        // one by one, replace the digit with each character in the corresponding
        // list and recur for the next digit
        for (char c: keypad.get(digit)) {
            findCombinations(keypad, input, c + result, index - 1);
        }
    }
 
    public static void main(String[] args)
    {
        List<List<Character>> keypad = Arrays.asList(
                // 0 and 1 digit doesn't have any characters associated
                Arrays.asList(),
                Arrays.asList(),
                Arrays.asList( 'a', 'b', 'c' ),
                Arrays.asList( 'd', 'e', 'f' ),
                Arrays.asList( 'g', 'h', 'i' ),
                Arrays.asList( 'j', 'k', 'l' ),
                Arrays.asList( 'm', 'n', 'o' ),
                Arrays.asList( 'p', 'q', 'r', 's'),
                Arrays.asList( 't', 'u', 'v' ),
                Arrays.asList( 'w', 'x', 'y', 'z')
        );
 
        // input number in the form of an array (number cannot start from 0 or 1)
        int[] input = { 2, 3 };
 
        findCombinations(keypad, input, "", input.length - 1);
    }
}

/* 
- Output
   ad ae af bd be bf cd ce cf

- Complexity Analysis :
    Time Complexity : O(4^n)
        here as each digit of the number has 3 or 4 alphabets we have taken the upper bound
        so that all cases can be incorporated in it.

    Space Complexity : O(1)
        No extra space is needed
    
        NOTE: Each recursive approach consumes a definite amount of space called call stack for it's execution but for simplicity purpose I've not taken that into account.

*/
