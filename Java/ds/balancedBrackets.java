/*Given a string s containing round, curly, and square open and closing brackets,
 return whether the brackets are balanced. The aim of the program is to make use of stacks.*/

import java.util.*;

public class balancedBrackets {
    /* This method checks if the input string is balanced or not */
    public static boolean isBalanced(String s) {
        java.util.Stack<Character> stack = new java.util.Stack<>();
        if (s.length() == 1)
            return false;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            /* If the present character is an opening bracket, we push it into the stack */
            if (c == '(' || c == '[' || c == '{')
                stack.add(c);

            /*
             * If it is a closing bracket, we check if the last character pushed into the
             * stack is the corresponding opening bracket or not and we pop it
             */
            else {
                if (c == ')') {
                    if (stack.isEmpty())
                        return false;
                    char c2 = stack.pop();
                    if (c2 != '(')
                        return false;
                } else if (c == ']') {
                    if (stack.isEmpty())
                        return false;
                    char c2 = stack.pop();
                    if (c2 != '[')
                        return false;
                } else if (c == '}') {
                    if (stack.isEmpty())
                        return false;
                    char c2 = stack.pop();
                    if (c2 != '{')
                        return false;
                }
            }
        }

        /*
         * At the end of all operations, if it turns out that the stack is not empty
         * i.e, the brackets are not balanced, we return false.
         */
        if (!stack.isEmpty())
            return false;
        return true;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        /* Taking the input string */
        System.out.println("Enter the string consisting of brackets");
        String s = sc.nextLine();

        /*
         * Passing the string to check if it is balanced or not and displaying output
         * accordingly
         */
        if (isBalanced(s))
            System.out.println("The given string " + s + " has balanced brackets in it.");
        else
            System.out.println("The given string " + s + " does not have balanced brackets in it.");
    }
}

/*
 * Sample Input: "([])[]({})" Output: The given string ([])[]({}) has balanced
 * brackets in it.
 */
/*
 * Time Complexity: O(n)
 */
