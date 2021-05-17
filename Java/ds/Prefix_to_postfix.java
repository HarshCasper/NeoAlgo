
/*
An expression is called prefix , if the operator appears in the expression before the operands. (operator operand operand)
An expression is called postfix , if the operator appears in the expression after the operands . (operand operand operator)
The program below accepts an expression in prefix and outputs the corresponding postfix expression .
*/
import java.util.Scanner;
import java.util.Stack;

class Code2 {
    // if operand function checks if the element is an operand
    static boolean ifoperand(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        return false;
    }

    // prefixtopostfix function converts a prefix expression to postfix
    static void prefixtopostfix(String expression) {
        Stack<String> s = new Stack<String>();
        int len = expression.length();
        for (int i = len - 1; i >= 0; i--) {
            if (ifoperand(expression.charAt(i))) {
                s.push("" + expression.charAt(i));
            } else {
                String exp = "" + expression.charAt(i);
                String op1 = s.peek();
                s.pop();
                String op2 = s.peek();
                s.pop();
                String temp = op1 + op2 + exp;
                s.push(temp);
            }
        }
        System.out.println("the postfix expresssion is : " + s.peek());
    }

    // Driver code
    public static void main(String[] args) {
        String exp;
        System.out.println("Enter the prefix expression ");
        Scanner sc = new Scanner(System.in);
        exp = sc.nextLine();
        prefixtopostfix(exp);
        sc.close();
    }

}

/*
Sample I/O:

Enter the prefix expression
*+abc
the postfix expresssion is : ab+c*

Time complexity : O(n) 
space complexity : O (n)
 */
