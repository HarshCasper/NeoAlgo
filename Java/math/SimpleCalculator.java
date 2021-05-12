/*
Simple Calculator

You are given a string str representing an expression, 
your task is to perform the basic calculation 
presented in the string and evaluate the answer.
It is also noted that you are not allowed to use any 
in-built function to evaluate strings as mathematical 
expressions.
Constraints of this problem are:-
1. 1 <= str.length <= 3 * 105
2. str consists of digits, '+', '-', '(', ')', and ' '.
3. str represents a valid expression
*/

import java.util.*;
import java.io.*;

public class SimpleCalculator
{
    //we can us e stack to store the elements and evaluate
    //stack can be use to find the value for each 
    //sub-expression within a parenthesis

    //fuction to calculate the string value
    public int calString(String str)
    {
        //stack to store elements and evaluate them
        Stack<Integer> stackEvaluate = new Stack<Integer>();
        int ExpressionOperand = 0;
        //storing current result
        int CurrResult = 0; 
        //the sign configuration goes:- 1 means positive, -1 means negative
        int sign = 1;  

        for (int pass = 0; pass < str.length(); pass++)
        {
            char charStr = str.charAt(pass);

            if (Character.isDigit(charStr))
            {
                //forming operands, because they could be of more than one digit
                ExpressionOperand = 10 * ExpressionOperand + (int) (charStr - '0');
            }

            else if (charStr == '+')
            {
                //for a + we evaluate the expression to the left,
                //along with the result, sign, operand
                CurrResult += sign * ExpressionOperand;
                //saving the recently encountered +
                sign = 1;
                //reseting operand
                ExpressionOperand = 0;
            }

            else if(charStr == '-')
            {
                //for a - we evaluate the expression to the left,
                // along with the result, sign, operand
                CurrResult += sign * ExpressionOperand;
                //saving the recently encountered -
                sign = -1;
                //reseting operand
                ExpressionOperand = 0;
            }

            else if (charStr == '(')
            {
                //for ( we just push the result and sign on to the stack, 
                //for later, we push the result first, then sign
                //and start fresh as if we are calculating a new expression.
                stackEvaluate.push(CurrResult);
                stackEvaluate.push(sign);
                //reseting operand and result, as if new evaluation begins for the new sub-expression
                sign = 1;
                CurrResult = 0;
            }

            else if (charStr == ')')
            {
                //for ) we first evaluate the expression to the left
                // with result, sign and operand
                CurrResult += sign * ExpressionOperand;
                // ')' marks the end of expression within a set of parenthesis
                //Its result is multiplied with sign on top of stack
                //stackEvaluate.pop() is the sign before the parenthesis 
                CurrResult *= stackEvaluate.pop();
                //the result is then just added to the next
                //element on the top of the stack
                //which is stackEvaluate.pop()
                CurrResult += stackEvaluate.pop();
                //Reset the operand
                ExpressionOperand = 0;
            }
        }
        return CurrResult + (sign * ExpressionOperand);
    }

    //driver code
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        //for input
        System.out.println("Enter the expression : ");
        String str = sc.nextLine();

        //for output
        int result = calString(str);
        System.out.println("Value of the expression is : ");
        System.out.print(result);
    }
}

/*
EXAMPLE:-
INPUT--
Enter the expression : (1+(4+5+2)-3)+(6+8)
OUTPUT--
Value of the expression is : 23

TIME COMPLEXITY-->O(N)
SPACE COMPLEXITY-->O(N), where N is the length of the string str. 
*/
