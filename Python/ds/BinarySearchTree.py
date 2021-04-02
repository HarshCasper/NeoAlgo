# Implementation of Binary Search Tree


class BSTNode(object):
    # A Node of the Binary Search Tree 
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def insertNode(root, val):
    # Function to insert a node to a BST

    # if the given BST is empty
    if root == None:
        return BSTNode(val)

    else:
        # if the value to insert already exists in the tree
        if root.val == val:
            return root

        # if the value to insert should be inserted to the left subtree
        if val < root.val:
            root.left = insertNode(root.left, val)
        
        # if the value to insert should be inserted to the right subtree
        else:
            root.right = insertNode(root.right, val)

    return root

    
def searchNode(root, val):
    # Function to search a node in a BST

    # if the BST is empty or if the node doesn't exist
    if root == None:
        return False

    # if the value exists in the BST
    if root.val == val:
        return True

    # if the value might exist in the right subtree    
    elif val > root.val:
        return searchNode(root.right, val)

    # if the value might exist in the left subtree
    else:
        return searchNode(root.left, val)


def inorderSuccessor(node):
    # Function to find the inorder successor of a given node

    curr = node
    # Loop through the BST until a left most node is reached
    while (curr.left != None):
        curr = curr.left
    return curr


def deleteNode(root, val):
    # Function to delete a node in a BST

    # if the BST is empty
    if root == None:
        return root
    
    # if the node to delete might exist in the left subtree
    elif root.val > val:
        root.left = deleteNode(root.left, val)

    # if the node to delete might exist in the right subtree
    elif root.val < val:
        root.right = deleteNode(root.right, val)

    # if the node is found
    else:

        # if the node has one child or no children
        if root.right == None:
            tempNode = root.left
            root = None
            return tempNode

        elif root.left == None:
            tempNode = root.right
            root = None
            return tempNode 

        # if the node has two children
        tempNode = inorderSuccessor(root.right)
        root.val = tempNode.val
        root.right = deleteNode(root.right, tempNode.val)

    return root


def inorder(root):
    # Function to print the nodes in the BST inorder
    
    # if the BST is not empty
    if root:
        # visit the left subtree (or leaf)
        inorder(root.left)
        # visit the parent
        print(root.val, end = ' ')
        # visit the right subtree (or leaf)
        inorder(root.right)
    
    
# A menu based implementation
if __name__ == '__main__':
    bst = None
    op = 1

    while (op != 5):
        print()
        print("1: Insert")
        print("2: Search")
        print("3: Delete")
        print("4: Print (Inorder)")
        print("5: Exit")
        print("Enter option: ", end = "")
        
        op = int(input())
        
        if op == 1:
            print("Enter value to insert: ", end = "")
            val = int(input())
            bst = insertNode(bst, val)
            print()
        
        elif op == 2:
            print("Enter element to search for: ", end = "")
            val = int(input())
            if searchNode(bst, val):
                print("The element is present!")
            else:
                print("The element is not present")
            print()
        
        elif op == 3:
            print("Enter the value to delete: ", end = "")
            val = int(input())
            bst = deleteNode(bst, val)
            print()
        
        elif op == 4:
            if bst:
                inorder(bst)
            else:
                print("Empty BST!")
            print()