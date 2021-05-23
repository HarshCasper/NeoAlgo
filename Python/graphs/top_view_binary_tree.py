'''
Top view of binary tree

Given a binary tree, print the nodes in left to right manner as visible from
above the tree.Input is given in order of root node, left child then
right child(preorder).
For e.g. 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
Tree looks like
              1
          /      \
      2           3
    /     \       /
  4       5     6

nodes '5' and '6' will be overlapped by '1' as seen from above,
so when viewed from the top , we would see the nodes 4, 2, 1 and 3.
'''


# A class to create a node
class Node:
    # Constructor to initialize node
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


# A function to build the tree in preorder manner
def MakeTree():
    val = int(input())
    if val == -1:
        return None
    root = Node(val)
    root.left = MakeTree()
    root.right = MakeTree()
    return root


# A function to print the left side of the binary tree
def LeftView(root):
    # base case
    if root is None:
        return
    # Recursive case
    LeftView(root.left)
    print(root.key, end=" ")


# A function to print the right side of the binary tree
def RightView(root):
    # base case
    if root is None:
        return
    # Recursive case
    print(root.key, end=" ")
    RightView(root.right)


print("Enter values in a binary tree: ")
# A function call to build the tree and return root node
root = MakeTree()
# Calling the below two functions for printing the top view
print("Top view of the binary tree is: ")
LeftView(root)
RightView(root.right)

'''
Sample Input:
Enter values in a binary tree:
1
2
4
-1
-1
5
-1
-1
3
6
-1
-1
-1
Sample Output:
Top view of the binary tree is: 4 2 1 3

Time Complexity:  O(n), for traversing the 'n' nodes

Space Complexity: O(1), since no extra space is used
'''
