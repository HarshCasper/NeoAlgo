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
    
    '''
    Stack is used to implement the iterative approach. Push nodes into the stack. We leave the inner loop when left leaf is reached. 
    Latest node is popped out of the stack and we move to its right child and repeat the above steps until we reach the right-most child.
    '''

    def iterative_preorder_traversal(self, root):
        self.path = []
        stack = [] 
        while stack or root:
            while root:
                self.path.append(root.val)   
                stack.append(root) 
                root = root.left            
            root = stack.pop()                
            root = root.right                
                                             
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

