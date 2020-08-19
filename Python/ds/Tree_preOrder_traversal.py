class node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None
    
    def createTree(self, treeNodesArray):
        queue = []
        self.root = node(int(treeNodesArray.pop(0)))
        queue.append(self.root)
        size = len(queue)
        while treeNodesArray:
            while size:
                root = queue.pop(0)
                if root:
                    val = treeNodesArray.pop(0)
                    if val == 'null':
                        root.left = None
                    else:
                        root.left = node(int(val))
                        queue.append(root.left)
                    val = treeNodesArray.pop(0)
                    if val == 'null':
                        root.right = None
                    else:
                        root.right = node(int(val))
                        queue.append(root.right)
                size -= 1
            size = len(queue)
    
    def recursive_preorder_traversal(self, root, path):
        if root:
            path.append(root.val)
            self.recursive_preorder_traversal(root.left, path)
            self.recursive_preorder_traversal(root.right, path)
        return path

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
 	
treeNodesArray = list(input().split(','))
preOrdertree = Tree()
preOrdertree.createTree(treeNodesArray)

#### Pre-Order Traversal :- root.val -> root.left -> root.right

print(preOrdertree.recursive_preorder_traversal(preOrdertree.root, []))  
print(preOrdertree.iterative_preorder_traversal(preOrdertree.root))  

'''
    Input should be of this type->    1,2,3,null,null,4,5,null,null,6,7      
    Children of leaf node are null
        
        1
       / \
      2   3
         / \
        4   5
           / \
          6   7
     Expected Output: 1,2,3,4,5,6,7
     
Stack is used to implement the iterative approach. Push nodes into the stack. We leave the inner loop when left leaf is reached. 
Latest node is popped out of the stack and we move to its right child and repeat the above steps until we reach the right-most child. 
'''
