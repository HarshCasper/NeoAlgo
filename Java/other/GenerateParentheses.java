/**
The program will generate all the possible
combinations of n pairs of parentheses.
*/

import java.util.Scanner;

public class GenerateParentheses {

    static void parantheses(int i, int j, int n, String s) {
		if (i==n && j==n) {
			// n opening and n closing brackets
			// have been included
			System.out.println (s);
			
		} else if (i==n) {
			// n opening brackets have been included
			// now just need to add only closing ones
			parantheses (i, j+1, n, s+')');
			
		} else if (j==n || j>i) {
			// condition of failure when closing brackets 
			// are more than the opening ones.
			return;
			
		} else {
			// adding closing bracket to string
			parantheses (i, j+1, n, s+')');
			// adding opening bracket to string
			parantheses (i+1, j, n, s+'(');
		}
	}

	public static void main(String[] args) {

		Scanner sc=new Scanner (System.in);
		
		System.out.print ("Enter value of n- ");
		int n=sc.nextInt();

		System.out.println("Possible pairs - ");
		parantheses (0, 0, n, "");
    }
}

/**
Time Complexity : O(2^2n)
Space Complexity : O(1)

Input :

Enter value of n- 3

Output :

Possible pairs - 
()()()
()(())
(())()
(()())
((()))

*/

