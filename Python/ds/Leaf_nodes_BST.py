'''
    COUNT OF LEAF NODES IN A BINARY SEARCH TREE
    Binary Search Tree is a special type of binary tree where
    1. The value of all the nodes in the left sub-tree is less than or equal to the value of the root.
    2. The value of all the nodes in the right sub-tree is greater than value of the root.
    3. This rule will be recursively applied to all the left and right sub-trees of the root.

    Leaf node is a node which does not have left or right child
    No. of leaf nodes varies with the order in which the nodes are inserted
'''

# Declare treeNode with data , rc (right child) and lc (left child )
class treeNode:
    def __init__(self, item):
        self.data = item
        self.lc = None
        self.rc = None

# to insert a node into BST
def insertIntoTree(root, data):
    # If tree is empty insert as root node
    if root is None:
        root = treeNode(data)
    else:
        # insert recursively in accordance with BST properties
        if root.data >= data:
            root.lc = insertIntoTree(root.lc, data)
        elif root.data < data:
            root.rc = insertIntoTree(root.rc, data)
    return root

# to count the leaf nodes
def leaf_nodes(root):
    # If tree is not empty
    if root is not None:
        # If the node doesn't have any child increment count
        if root.lc is None and root.rc is None:
            leaf_nodes.count += 1
        else:
            # recursively check left and right sub-trees
            if root.lc is not None:
                leaf_nodes(root.lc)
            if root.rc is not None:
                leaf_nodes(root.rc)
    return leaf_nodes.count

# driver code
def main():
    # Initialize tree as empty
    root = None
    # Accept the no. of elements and elements as user input
    n = int(input("Enter the number of elements: "))
    print("Enter the numbers: ")
    for _ in range(0, n):
        data = int(input())
        root = insertIntoTree(root, data)
    # Initially count of leaf nodes is set as 0
    leaf_nodes.count = 0
    print("\nNo. of leaf nodes in the binary search tree = " +str(leaf_nodes(root)))

if __name__ == "__main__":
    main()
    
'''
    Sample input:
    Enter the number of elements: 7 
    Enter the numbers: 
    6
    2
    10
    1
    4
    8
    11
    
    Sample output:
    No. of leaf nodes in the binary search tree = 4

    Time complexity : O(n)
    Space complexity : O(n)
'''
