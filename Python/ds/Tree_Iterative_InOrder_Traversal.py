# InOrder tree traversal using python3 (Iterative)

class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    # creation of tree.
    def createTree(self, NodesArray):
        queue = []
        self.root = node(int(NodesArray.pop(0)))
        queue.append(self.root)
        size = len(queue)
        while NodesArray:
            while size:
                root = queue.pop(0)
                if root:
                    data = NodesArray.pop(0)
                    if data == 'null':
                        root.left = None
                    else:
                        root.left = node(int(data))
                        queue.append(root.left)
                    data = NodesArray.pop(0)
                    if data == 'null':
                        root.right = None
                    else:
                        root.right = node(int(data))
                        queue.append(root.right)
                size -= 1
            size = len(queue)

    # Iterative function to perform in-order traversal of the tree
    def inorderIterative(self,root):
	    stack = []
	    curr = root
	    while stack or curr:
        # if current node is not null, push it to the stack
		    if curr:
		    	stack.append(curr)
		    	curr = curr.left
		    else:
			# else if current node is null, we pop an element from the stack,print it and finally set current node to its right child
			    curr = stack.pop()
			    print(curr.data, end=' ')
			    curr = curr.right


NodesArray = list(input().split(' '))
InOrdertree = Tree()
InOrdertree.createTree(NodesArray)
InOrdertree.inorderIterative(InOrdertree.root)


'''
     10
   /     \
  20      30
 /  \    /  \   
40  50  -    -
 
input :: 10 20 30 40 50 null null
output :: 40 20 50 10 30
'''
