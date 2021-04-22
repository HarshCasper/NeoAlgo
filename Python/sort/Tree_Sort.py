''' SORTING USING BINARY SEARCH TREE
    Binary Search Tree is a special type of binary tree where
    1. The value of all the nodes in the left sub-tree is less 
       than or equal to the value of the root.
    2. The value of all the nodes in the right sub-tree is 
       greater than value of the root.
    3. This rule will be recursively applied to all the left 
       and right sub-trees of the root.

    Inorder traversal
    1. Traverse the left subtree
    2. Visit the root.
    3. Traverse the right subtree

    Inorder traversal in BST gives sorted list
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


# to sort-inorder traversal gives sorted list
def inorder(root):
    # If tree is not empty
    if root is not None:
        # recursively visit left sub-tree,root and right sub-tree
        inorder(root.lc)
        print(root.data, end=" ")
        inorder(root.rc)


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

    print("\nSorted list : ")
    inorder(root)


if __name__ == "__main__":
    main()

'''
    Sample input:
    Enter the number of elements: 7
    Enter the numbers:
    1
    2
    5
    3
    7
    4
    6

    Sample output:
    Sorted list:
    1 2 3 4 5 6 7

    Time complexity : O(n)
    Space complexity : O(n)
'''
