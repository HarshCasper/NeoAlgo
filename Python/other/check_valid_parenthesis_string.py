#!/usr/bin/python
# -*- coding: utf-8 -*-

'''
PROBLEM STATEMENT

Given a string of '(' , ')' and lowercase english characters.

The task is to remove the minimum number of parentheses so
that the resulting parentheses string is valid.
A parentheses string is valid if and only if:
1.It is the empty string, contains only lowercase characters, or
2.It can be written as AB (A concatenated with B), where A and B are valid strings, or
3.It can be written as (A), where A is a valid string.

Implementation By: Nandini Bansal (GitHub: nandinib1999)

Method:
We can process a string which may possbily have unbalanced parentheses.
It makes use of a stack to store in the indices of the opening parenthesis
when encountered one and pops the index from the top of the stack when a
closing parenthesis is encountered. If a closing parentheses is encountered
while the stack is empty, its index is saved in an array "indx".
At the end of string traversal, we combine the "stack" and "indx" as
they contain the indices of unpaired opening and closing brackets.
An output string is generated after skipping the characters at indices
left in "stack" and "indx".

Argument: string (Input string with parenthesis)
Return: string (Output string with balanced parenthesis)
'''


def remove_parenthesis(string):
    '''
    Returns a string after removing minimum number of parentheses to make it balanced.

    Parameters:
            string (str): A string input

    Returns:
            op_str (str): A valid parentheses string
    '''
    stack = []
    indx = []
    for (i, s) in enumerate(string):
        if s == '(':
            # save the index of ( in stack
            stack.append(i)
        elif s == ')':
            if len(stack) > 0:
                # pop the index of ( on the top of stack if stack is not empty
                _ = stack.pop()
            else:
                # if stack is empty, save the index of ) in indx array
                indx.append(i)
        else:
            # no action taken for other character of the string
            continue

    # Generating the output string by skipping the unpaired parenthesis
    # whose indices are saved in "stack" and "indx"
    op_str = ''
    # combine the list of indices and sort the indices
    final_indx = indx + stack
    final_indx.sort()
    for (i, s) in enumerate(string):
        # if index is in final_indx i.e. has unpaired parenthesis, skip it
        if i in final_indx:
            pass
        else:
            op_str = op_str + s
    return op_str


if __name__ == '__main__':
    inp_str = input().strip()
    output_str = remove_parenthesis(inp_str)
    print(output_str)
    # Time Complexity: O(n)
    # Testcases
    # (1) Input: (()))() Output: (())()
    # (2) Input: neoalgo Output: neoalgo
    # (3) Input: ())(() Output: ()()
    # (4) Input: )))((( Output: ''
    # (5) Input: (())() Output: (())()
