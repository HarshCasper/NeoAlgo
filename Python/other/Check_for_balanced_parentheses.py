'''
Check-for-balanced-parentheses
Problem Statement : Given an expression string x. Examine whether
                    the pairs and the orders of
                    “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
                    For example, the function should return
                    'true' for exp = “[()]{}{[()()]()}” 
                    and 'false' for exp = “[(])”.
                    
Input : Enter list of parentheses.


Output : Print True if it is balanced or else False.


Time Complexity : O(n)
Space Complexity : O(n)

'''

def Check(brackets): 
    stack = [] 
  
    # Traversing the Expression
    
    for i in brackets: 
        if i in ["(", "{", "["]: 
  
            # Push the element in the stack
            
            stack.append(i) 
        else: 
  
            # IF current character is not opening 
            # bracket, then it must be closing. 
            
            if not stack: 
                return False
            char = stack.pop() 
            if char == '(': 
                if i != ")": 
                    return False
            if char == '{': 
                if i != "}": 
                    return False
            if char == '[': 
                if i != "]": 
                    return False
  
    # Check Empty Stack
    
    if stack:
        return False
    return True

# -----------------------Driver Code-----------------------

# INPUT

# Enter the list of the brackets
brackets = input("Enter the brackets: ")

# OUTPUT

if(Check(brackets)):
    print("The parentheses are balnced")
else:
    print("The parentheses are not balnced")

'''
SAMPLE INPUT/OUTPUT:

INPUT

    Enter the brackets: {{[[[()]]]}}{(())}

OUTPUT

    The parentheses are balnced    
'''
