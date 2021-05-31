"""
An expression is called prefix , if the operator appears in the expression before the operands. (operator operand operand)
An expression is called postfix , if the operator appears in the expression after the operands . (operand operand operator)
The program below accepts an expression in prefix and outputs the corresponding postfix expression .
"""

# prefixtopostfix function converts a prefix expression to postfix
def prefixtopostfix(exp):
    stack = []
    n = len(exp)
    for i in range(n - 1, -1, -1):
        if exp[i].isalpha():
            stack.append(exp[i])
        else:
            op1 = stack.pop()
            op2 = stack.pop()
            stack.append(op1 + op2 + exp[i])
    print("the postfix expresssion is : " + stack.pop())


# Driver Code
if __name__ == "__main__":
    exp = input("Enter the prefix expression : ")
    prefixtopostfix(exp)


"""
Sample I/O:

Enter the prefix expression : *+abc
the postfix expresssion is : ab+c*

Time complexity : O(n) 
space complexity : O (n)
"""
