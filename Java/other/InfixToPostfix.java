/**
 * Infix to Postfix Expression
 *
 * This program converts an infix expression entered by the user
 * into the Postfix expression.
 * The program uses a stack to keep the track of the operators and
 * paranthesis of the input expression.
 *
 * Author: iamvs-2002
 */

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

public class InfixToPostfix 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Kindly enter the infix expression: ");
        String infix = sc.nextLine();

        InfixToPostfix x = new InfixToPostfix();
        String postfix = x.infixtopostfix(infix);

        System.out.println("Postfix Expression: "+postfix);
    }

    static int priority(char c)
    {
        switch (c)
        {
            case '+':
                return 1;
            case '-':
                return 1;
            case '*':
                return 2;
            case '/':
                return 2;
            case '^':
                return 3;
            default:
                return -1;
        }
    }

    private String infixtopostfix(String expression)
    {
        String result = "";

        Stack<Character> stack = new Stack<>();

        int i=0;
        for (i = 0; i < expression.length() ; i++) 
        {
            char c = expression.charAt(i);
            if(priority(c)>0)
            {
                //if the topmost operator in the stack has a priority greater than or equal to c
                //pop it and add to result string
                //else push it into the stack
                while(stack.isEmpty()==false && (priority(stack.peek())>=priority(c)))
                {
                    result = result + stack.pop();
                }
                stack.push(c);
            }
            else if(c==')')
            {
                //if character is ending bracket ')'
                //pop from stack, until '(' is found
                while(stack.peek()!='(')
                {
                    result = result + stack.peek();
                    stack.pop();
                }
                char x = stack.pop();
            }
            else if(c=='(')
            {
                stack.push(c);
            }
            else
            {
                result = result + c;
            }
        }

        while (!stack.isEmpty())  
			result = result + stack.pop();

        return result;
    }
}
/**
 * Sample Outputs:
 * 
 * Kindly enter the infix expression:
 * (X - Y / (Z + U) * V)
 * Postfix Expression: X  Y  Z  U+ / V*-
 *
 * Kindly enter the infix expression:
 * ab+
 * Postfix Expression: ab  +
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */
