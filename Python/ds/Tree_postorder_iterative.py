# Python program for iterative postorder traversal
# A binary tree node 
class Node: 
	
	# Constructor to create a new node 
	def __init__(self, data): 
		self.data = data 
		self.left = None
		self.right = None

# An iterative function to do postorder traversal of a given binary tree 
def postorderIterative(root): 

	if root is None: 
		return		
	
	s1 = [] # Create two stacks 
	s2 = [] 
	
	s1.append(root) # Push root to first stack 
	
	while s1: 		# Run while first stack is not empty 
		node = s1.pop() # Pop an item from s1 and 
		s2.append(node) # append it to s2 
	
		# Push left and right children of removed item to s1 
		if node.left: 
			s1.append(node.left) 
		if node.right: 
			s1.append(node.right) 

		# Printing the result
	while s2: 
		node = s2.pop() 
		print node.data, 

# Driver program to test above function 
root = Node(10) 
root.left = Node(20) 
root.right = Node(30) 
root.left.left = Node(40) 
root.left.right = Node(50) 
root.right.left = Node(60) 
root.right.right = Node(70) 
postorderIterative(root) 

'''
     10
   /     \
  20      30
 /  \    /   \
40  50  60    70
 
'''

postorderIterative(root)  # Expected result: [40 50 20 60 70 30 10]
