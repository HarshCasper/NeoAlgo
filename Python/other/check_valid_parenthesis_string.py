'''
PROBLEM STATEMENT

Given a string of '(' , ')' and lowercase english characters.

The task is to remove the minimum number of parentheses so that the resulting parentheses string is valid.
A parentheses string is valid if and only if:
1.It is the empty string, contains only lowercase characters, or
2.It can be written as AB (A concatenated with B), where A and B are valid strings, or
3.It can be written as (A), where A is a valid string.

Implementation By: Nandini Bansal (GitHub: nandinib1999)

Method:
We can process a string which may possbily have unbalanced parentheses. It makes use of a stack to store in the indices of the opening parenthesis when encountered one and pops the index from the top of the stack when a closing parenthesis is encountered. If a closing parentheses is encountered while the stack is empty, its index is saved in an array "indx".
At the end of string traversal, we combine the "stack" and "indx" as they contain the indices of unpaired opening and closing brackets. An output string is generated after skipping the characters at indices left in "stack" and "indx".

Argument: string (Input string with parenthesis) 
Return: string (Output string with balanced parenthesis)

Time Complexity: O(n)
'''


def remove_parenthesis(string: str) -> str:
  stack = []
  indx = []
  for i, s in enumerate(string):
    if s == '(':
      stack.append(i) # save the index of ( in stack
    elif s == ')':
      if len(stack) > 0:
        _ = stack.pop() # pop the index of ( on the top of stack if stack is not empty
      else:
        indx.append(i) # if stack is empty, save the index of ) in indx array
    else:
      continue # no action taken for other character of the string
  
  # Generating the output string by skipping the unpaired parenthesis whose indices are saved in "stack" and "indx"
  op_str = ""
  final_indx = indx + stack # combine the list of indices and sort the indices
  final_indx.sort()
  for i, s in enumerate(string):
    if i in final_indx: # if index is in final_indx i.e. has unpaired parenthesis, skip it
      continue
    else:
      op_str = op_str + s 
  return op_str

if __name__ == '__main__':
  remove_parenthesis("he((l)l)o)")
  # Output: he((l)l)o
  '''
  Testcases

  (1) Input: (()))() Output: (())()
  (2) Input: neoalgo Output: neoalgo
  (3) Input: ())(() Output: ()()
  (4) Input: )))((( Output: ''
  (5) Input: (())() Output: (())()
  '''