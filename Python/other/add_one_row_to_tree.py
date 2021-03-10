class TreeNode:
    def __init__(self, value = 0, left = None, right = None):
        self.data = value
        self.left = left
        self.right = right
    
    def printTree(self):
        print(self.data, end = " ")
         
        if self.left:
            self.left.printTree()
        
        if self.right:
            self.right.printTree()

    def addOneRow(self, node, value, depth):
        if not node:
            return 
                
        if depth - 2 > 0:  #too early to update, let's go deeper
            self.addOneRow(node.left, value, depth-1)
            self.addOneRow(node.right, value, depth-1)
            
        elif depth - 2 == 0: # here is the place, let's update
            node.left = TreeNode(value,node.left, None)
            node.right = TreeNode(value, None, node.right)
            
        else: #the depth is too short, let's update the root
            root = TreeNode(value, node, None)
            return root
                
        return node



# A binary tree as following:
#        4
#      /   \
#     2     6
#    / \   / 
#   3   1 5   

root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(6)
root.left.left = TreeNode(3)
root.left.right = TreeNode(1)
root.right.left = TreeNode(5)

# Given value and depth
value = 1
depth = 2

# Adding a row of given value at the given depth
root = root.addOneRow(root, value, depth)
print("The preordal traversal of the tree after addition of row-")
root.printTree()
print()

# The resultant tree would be:
#        4
#       / \
#      1   1
#     /     \
#    2       6
#   / \     / 
#  3   1   5   