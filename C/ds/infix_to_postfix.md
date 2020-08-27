# Conversion of an infix expression to postfix expression.

An Infix expression is an expression where operators are written in-between the operands. Example:- A+B.
Infix expressions are readable and solvable by humans. 
But the computer cannot differentiate the operators and parenthesis easily, that’s why conversion to postfix expression is needed.
i.e, Operators are written after their operands. Example:- AB+

### To convert infix expression to postfix expression, we will use the *Stack Data Structure*. 

### The following is the process how the conversion of an infix expression to postfix expression takes place using stack data structure.

1. Print operands as they arrive.
2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
3. If the incoming symbol is a left parenthesis, push it on the stack.
4. If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.
5. If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
6. If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator.
7. If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.
8. At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)
