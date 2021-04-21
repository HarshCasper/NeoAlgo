/**
 * Infix to Prefix Expression
 * 
 * Algorithm Used:
 * First the given infix expression is reversed.
 * By reversing, every '(' becomes ')' and vice versa.
 * Then, we obtain the postfix of the reversed expression.
 * Now, we reverse this postfix expression to obtain the Prefix expression.
 * 
 * Author: iamvs-2002
 */

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

public class InfixtoPrefix 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Kindly enter the infix expression: ");
        String infix = sc.nextLine();

        InfixtoPrefix x = new InfixtoPrefix();
        String prefix = x.infixtoprefix(infix);
        
        System.out.println("Prefix Expression: "+prefix);
    }

    static int priority(char c)
    {
        /**
         * '+' and '-' have priority=1
         * '*' and '/' have priority=2
         * '^' has priority=3
         */
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

    private String infixtoprefix(String expression)
    {
        //initially an empty string
        String result = "";

        //reversing the given infix expression
        char[] array = new char[expression.length()];
        for (int j = expression.length()-1; j >=0 ; j--) { 
            array[expression.length()-j-1] = expression.charAt(j);
        }

        Stack<Character> stack = new Stack<>();

        int i=0;
        for (i = 0; i < array.length; i++) 
        {
            if (array[i] == '(')
            {
                array[i] = ')';
                i++;
            }
            else if (array[i] == ')')
            {
                array[i] = '(';
                i++;
            }
        }

        String infix = '(' + String.valueOf(array) + ')';

        for (i = 0; i < infix.length() ; i++) 
        {
            char c = infix.charAt(i);
            //check if char is operator or operand
            if(priority(c)>0)
            {
                //if the topmost operator in the stack has a priority greater than c
                //pop it and add to result string
                //else push it into the stack
                while(stack.isEmpty()==false && (priority(stack.peek())>priority(c) || (priority(stack.peek())>=priority(c) && c=='^')))
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
                //removing '(' from stack
                char x = stack.pop();
            }
            else if(c=='(')
            {
                //character is starting bracket '('
                stack.push(c);
            }
            else
            {
                //if the character is an operand, add it to the result string
                result = result + c;
            }
        }
        //the result string is now a postfix expression
        //reversing the string to obtain the prefix expression.
        //converting the final result string to a char array
        char[] arr = new char[result.length()];
        for (i = result.length()-1; i >=0 ; i--) { 
            arr[result.length()-i-1] = result.charAt(i);
        }
        return String.valueOf(arr);
    }
}
/**
 * Sample Outputs:
 * 
 * Kindly enter the infix expression:
 * A+B*C
 * Prefix Expression: +A*BC
 * 
 * Kindly enter the infix expression: 
 * x+y*z/w+u
 * Prefix Expression: ++x/*yzwu
 * 
 * Kindly enter the infix expression: 
 * A * B + C / D
 * Prefix Expression: +*A  B / C  D
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */
