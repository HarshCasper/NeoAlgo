class node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class Tree:
    def __init__(self, root):
        self.root = node(root)
    
    def recursive_preorder_traversal(self, root, path):
        if root:
            path.append(root.val)
            self.recursive_preorder_traversal(root.left, path)
            self.recursive_preorder_traversal(root.right, path)
        return path
	
    def iterative_preorder_traversal(self, root):
        self.path = []  #to save the path of the tree
        stack = []      #stack to save the cuurent node.
        while stack or root:
            while root:
                self.path.append(root.val)   #preorder traversal. Therefore, keeping current node's value
                stack.append(root)           #pushing the current node into stack so that 
                                             #it can be used in the future to move to the right child
                root = root.left             #traversing to the left child of the current node
            root = stack.pop()               #will end the inner loop once we reach the left most leaf. 
            root = root.right                #most recent node is popped out of the stack. 
                                             #Now we move to its right node and repeat the above steps until we reach rightmost leaf
        return self.path
 	
preOrdertree = Tree(2)

preOrdertree.root.left  = node(4)
preOrdertree.root.right = node(8)

preOrdertree.root.left.left   = node(16)
preOrdertree.root.left.right  = node(32)
preOrdertree.root.right.left  = node(64)
preOrdertree.root.right.right = node(128)

'''
      2
   /     \
  4       8
 / \     / \
16  32  64  128
 
'''

#### Pre-Order Traversal :- root.val -> root.left -> root.right

print(preOrdertree.recursive_preorder_traversal(preOrdertree.root, []))  # Expected result: [2,4,16,32,8,64,128]
print(preOrdertree.iterative_preorder_traversal(preOrdertree.root))  # Expected result: [2,4,16,32,8,64,128]

