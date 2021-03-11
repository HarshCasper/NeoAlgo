# Python program to reverse a string using stack.

# Function stack. 
def createStack(): 
	stack=[] 
	return stack 

# Size of the stack 
def size(stack): 
	return len(stack) 

# Empty function
def isEmpty(stack): 
	if size(stack) == 0: 
		return True 

# Push / add an item to stack . 
def push(stack,item): 
	stack.append(item) 

# Pop / remove an item from stack. 
def pop(stack): 
	if isEmpty(stack): return
	return stack.pop() 

# Reverse a string 
def reverse(string): 
	n = len(string) 
	
	# Create a empty stack 
	stack = createStack() 

	# Push all characters of string to stack 
	for i in range(0,n,1): 
		push(stack,string[i]) 

	# Making the string empty since all 
	#characters are saved in stack 
	string="" 

	# Pop all characters of string and 
	# put them back to string 
	for i in range(0,n,1): 
		string+=pop(stack) 
		
	return string 
	
# Driver program to test above functions 
string = input("Enter a string : ")
string = reverse(string) 
print("Reversed string is : " + string) 

"""
Output :
	Enter a string : I Love India
	Reversed string is : aidnI evoL I
"""

