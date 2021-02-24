/* Java implementation to convert infix expression to postfix */
/* Time  Complexity - O(N) 
 * Space Complexity - O(N) */
import java.util.Scanner;
import java.util.Stack; 
public class Infix_to_Postfix {
	    //Given function returns the precedence of an operator,higher value indicates the higher precedence  
	    public static int precedence(char ch) 
	    { 
	        switch (ch) 
	        { 
	             // operator '+' & '-' have same precedence and lower precedence than '+', '-' & '^' operator
	          case '+': 
	          case '-': 
	                return 1; 
	             // operator '*' & '/' have same precedence and greater precedence than '+' & '-' operator
	          case '*': 
	          case '/': 
	                return 2; 
	             // operator '^' have highest precedence
	          case '^': 
	               return 3; 
	        } 
	        return -1; 
	    } 
	    //Given method which converts infix expression to postfix
	    public static String infixToPostfix(String exp) 
	    { 
	        // initializing empty String for result 
	        String result = ""; 
	          
	        // initializing empty stack 
	        Stack<Character> stack = new Stack<>(); 
	          
	        for (int i = 0; i<exp.length(); ++i) { 
	            
	        	char c = exp.charAt(i); 
	              
	            // If the scanned character is an 
	            // operand, add it to output
	            if (Character.isLetterOrDigit(c)) {
	                result += c; 
	               
	            // If the scanned character is an '(' parenthesis, then  
	            // push it to the stack 
	            } else if (c == '(') {
	                stack.push(c); 
	              
	            //  If the scanned character is an ')' parenthesis, then  
	            // pop an output from the stack  
	            // until an '(' parenthesis is encountered 
	            } else if (c == ')') { 
	                
	            	while (!stack.isEmpty() &&  stack.peek() != '(') {
	                    result += stack.pop(); 
	                } 
	            	// finally, pop '(' parenthesis from stack
	                stack.pop(); 
	            
	            } else { // an operator is encountered
	                // Check the precedence of current operator with the top of stack
	            	// If the precedence of curr operator is less than top of stack, then pop() and append it to the final answer 
	            	while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) { 
	                    result += stack.pop(); 
	                } 
	            	// and push high precedence operator into the stack
	                stack.push(c); 
	            } 
	       } 
	       // pop all the operators from the stack 
	        while (!stack.isEmpty()){ 
	            if(stack.peek() == '(') {
	                return "Invalid Expression";
	            }    
	            result += stack.pop(); 
	         } 
	        return result; 
	    } 
	    // Main method  
	    public static void main(String[] args)  { 
	    	Scanner sc = new Scanner(System.in);
	        String exp = sc.next(); 
	        System.out.println(infixToPostfix(exp));
	        sc.close();
	    } 
	} 
/*
 * Sample Input1  : a+b*(c^d-e)^(f+g*h)-i
 * Sample Output1 : abcd^e-fgh*+^*+i-
 * Sample Input2  : a+b*c+d
 * Sample Output2 : abc*+d+
 * Sample Input2  : k+l-m*n+(o^p)*w/u/v*t+q
 * Sample Output2 : kl+mn*-op^w*u/v/t*+q+
 * */
