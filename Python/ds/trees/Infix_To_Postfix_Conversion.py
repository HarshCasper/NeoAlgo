# function to convert infix to postfix using array as stack
def infix_to_postfix(infix_expression):
    # initially empty stack
    stack = []
    # initially empty postfix_expression
    postfix_expression = ''
    for char in infix_expression:
        # if an operand then put it directly in postfix expression
        if char not in operators:
            postfix_expression += char
        # else if operators should be put in stack
        elif char == '(':
            '''append function to push
            elements in the stack '''
            stack.append('(')
        elif char == ')':
            while stack and stack[-1] != '(':
                postfix_expression += stack.pop()
            ''' pop function to pop
                elements from stack in LIFO order '''
            stack.pop()
        else:
            '''if priority of char in infix_expression is less than or equal to
                char at stack[-1] pop out and put in postfix_expression'''
            while stack and stack[-1] !=
            '(' and priorities[char] <= priorities[stack[-1]]:
                postfix_expression += stack.pop()
            stack.append(char)
    while stack:
        postfix_expression += stack.pop()
    return postfix_expression

# set of operators
operators = set(['+', '-', '*', '/', '(', ')', '^'])
# dictionary having priorities
priorities = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
print('Input:')
infix_expression = input('Enter infix expression\n')
print('Output:')
# displaying the Output
print('Postfix expression: ', infix_to_postfix(infix_expression))

'''
Input:
Enter infix expression: A+C*(B^D-E)^(G+H*K)-J
Output:
Postfix expression:     ACBD^E-GHK*+^*+J-

Time Complexity : O(n)
Space Complexity: Θ(n)
'''
