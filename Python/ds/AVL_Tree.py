"""
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for 
all nodes and if at any time they differ by more than one, rebalancing is done to restore this property. Each node maintains extra information 
called a balance factor whose value is either -1, 0 or +1 where balance factor of a node in an AVL tree is the difference between the height of 
the left subtree and that of the right subtree of that node.
"""
class avlnode:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

class avltree():
    def __init__(self):
        self.node = None
        self.height = -1
        self.balancefactor = 0

    """
    Insert new value into AVL Tree
    """
    def insert(self, value):
        tree = self.node
        new_node = avlnode(value)

        if tree is None:
            self.node = new_node
            self.node.left = avltree()
            self.node.right = avltree()

        elif value < tree.value:
            self.node.left.insert(value)

        elif value > tree.value:
            self.node.right.insert(value)

        self.rebalance()

    def get_height(self):
        if self.node:
            return self.node.height
        else:
            return 0

    # Rotate left (RL)
    def rotate_left(self):
        old_root = self.node
        new_root = self.node.right.node
        new_right = new_root.left.node

        self.node = new_root
        old_root.right.node = new_right
        new_root.left.node = old_root

    #Rotate right (RR)
    def rotate_right(self):
        old_root = self.node
        new_root = self.node.left.node
        new_left = new_root.right.node

        self.node = new_root
        old_root.left.node = new_left
        new_root.right.node = old_root

    """
    Rebalance a tree after insertion or deletion of a node
    """

    def rebalance(self):

        self.compute_height(recursive=False)
        self.balance(recursive=False)

        # For each node if balance is -1, 0 or 1 no rotation is required
        while self.balancefactor < -1 or self.balancefactor > 1:

            # Left subtree is bigger than right subtree
            if self.balancefactor > 1:

                if self.node.left.balancefactor < 0:

                    self.node.left.rotate_left()
                    self.compute_height()
                    self.balance()

                self.rotate_right()
                self.compute_height()
                self.balance()

            # Right subtree is bigger than left subtree
            if self.balancefactor < -1:

                if self.node.right.balancefactor > 0:

                    self.node.right.rotate_right()
                    self.compute_height()
                    self.balance()

                self.rotate_left()
                self.compute_height()
                self.balance()

    def compute_height(self, recursive=True):
        # Height is max height of either left or right subtree =1 for root

        if self.node:
            if recursive:
                if self.node.left:
                    self.node.left.compute_height()
                if self.node.right:
                    self.node.right.compute_height()

            self.height = 1 + max(self.node.left.height,
                                  self.node.right.height)
        else:
            self.height = -1


    """
    balance - Balance = height (left subtee ) - height (right subtree)
    """
    def balance(self, recursive=True):

        if self.node:
            if recursive:
                if self.node.left:
                    self.node.left.balance()
                if self.node.right:
                    self.node.right.balance()

            self.balancefactor = self.node.left.height - self.node.right.height
        else:
            self.balancefactor = 0

    def inorder_traversal(self):
        """
        Left tree nodes , root , right tree nodes 
        """
        if not self.node:
            return []

        result = []
        left_nodes = self.node.left.inorder_traversal()
        for lnode in left_nodes:
            result.append(lnode)

        result.append(self.node.value)

        right_nodes = self.node.right.inorder_traversal()
        for rnode in right_nodes:
            result.append(rnode)

        return result
        
    def preorder_traversal(self):
        """
        root, Left tree nodes , right tree nodes 
        """
        if not self.node:
            return []
            
        result = []
        result.append(self.node.value)

        left_nodes = self.node.left.preorder_traversal()
        for lnode in left_nodes:
            result.append(lnode)

        right_nodes = self.node.right.preorder_traversal()
        for rnode in right_nodes:
            result.append(rnode)

        return result

    def postorder_traversal(self):
        """
        Left tree nodes , root , right tree nodes 
        """
        if not self.node:
            return []
            
        result = []

        left_nodes = self.node.left.postorder_traversal()
        for lnode in left_nodes:
            result.append(lnode)

        right_nodes = self.node.right.postorder_traversal()
        for rnode in right_nodes:
            result.append(rnode)
        
        result.append(self.node.value)

        return result

if __name__ == "__main__":
    tree = avltree()
    data = []
    i=0
    print("Enter the number of nodes in a tree -")
    num = int(input())
    print("Enter the values of the nodes - ")
    for i in range(0,num):
        val = int(input())
        data.append(val)

    for value in data:
        tree.insert(value)

    print('In order traversal ', tree.inorder_traversal())
    print('Preorder traversal ', tree.preorder_traversal())
    print('Postorder traversal ', tree.postorder_traversal())
    
'''

Enter the number of nodes in a tree -
10
Enter the values of the nodes - 
10
20
40
30
80
60
50
44
22 
18
('In order traversal ', [10, 18, 20, 22, 30, 40, 44, 50, 60, 80])
('Preorder traversal ', [40, 20, 10, 18, 30, 22, 60, 50, 44, 80])
('Postorder traversal ', [18, 10, 22, 30, 20, 44, 50, 80, 60, 40])

--------------------------------
Space Complexity :
 O(n) in all the cases
 
Time Complexity :
 O(log n) in all the cases
'''
