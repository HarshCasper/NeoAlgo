/*

Check for balanced parenthesis
==============================
Given an expression containing parenthesis, check if it is well-formed or balanced.
Example of balanced parenthesis are: (), ((())), (a+b), (a/b)*(b/a)

*/

import java.util.*; 
import java.io.*;

public class BalancedParenthesis {
	private static boolean isBalanced(String str) {
		// Size of the string
		int n = str.length();

		// Stack to store open parenthesis
		Stack<Integer> s = new Stack<Integer>();
		// Open parenthesis -> 1

		// Loop through characters in the string
		for (int i = 0; i < n; i++) {
			// Open parenthesis is always pushed into the stack
			if (str.charAt(i) == '(') {
				s.push(1);
			} else if (str.charAt(i) == ')') {
				// Closed parenthesis encountered must be balanced by an open parenthesis already
				// present in the stack
				if (!s.empty())
					// Stack contains open parenthesis, one of which has been balanced
					// Pop one parenthesis out
					s.pop();
				else
					// Stack contains no open parenthesis. So closed parenthesis cannot be balanced
					return false;
			}
		}

		// Check if we have open parenthesis remaining
		return (s.size() == 0);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		System.out.println((isBalanced(str) ? "YES" : "NO"));
	} 
}

/*

Input:
((a+b)+(c-d+f))
Output:
YES

Application: Stack data structure
Time Complexity: O(n)
Space Complexity: O(n)

*/

