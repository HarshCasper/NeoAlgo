'''
PROBLEM STATEMENT:
Given a binary tree, the task is to print its right view. Right view of
a binary tree is defined as the nodes which will be visible if the tree
is viewed from the right side. The input for the binary tree is in the
form of preorder and entering '-1' denotes a null node.
For example:
Input: 3 4 -1 6 -1 -1 5 1 -1 -1 -1
The above input will have the following structure:
    3
   / \
  4   5
  \   /
   6  1
Output: 3 5 1, as as these are the nodes that will be visible from right.
'''


# A class to create a node
class Node:
    # Constructor to initialize node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# A function to build the tree in preorder form
def BuildTree():
    d = int(input())
    if d == -1:
        return None
    root = Node(d)
    root.left = BuildTree()
    root.right = BuildTree()
    return root


# A function to print the right view of the binary tree
def RightView(root, level, maxlevel):
    # base case
    if root is None:
        return
    if level > maxlevel[0]:
        print(root.data, end=" ")
        maxlevel[0] = level
    # Recursive case
    RightView(root.right, level + 1, maxlevel)
    RightView(root.left, level + 1, maxlevel)


print("Enter values in a binary tree:")
# A function call to build the tree and return root node
root = BuildTree()
# maxlevel is defined as a list because it is mutable and we want the changes
# made to it gets reflected outside the function
maxlevel = [-1]
print("Right view of the binary tree is:")
RightView(root, 0, maxlevel)


'''
TEST CASE:
1.
Input:
Enter values in a binary tree:
2
4
7
8
-1
-1
-1
5
-1
-1
3
9
-1
6
-1
1
-1
-1
-1
Output:
Right view of the binary tree is:
2 3 9 6 1
Explanation:
The structure of the tree is:
            2
          /   \
         4     3
        / \   /
       7   5 9
      /       \
     8         6
                \
                 1
Therefore, the nodes visible from the right are: 2 3 9 6 1

TIME COMPLEXITY: O(n), due to the traversal of the whole tree,
where 'n' denotes the number of nodes in the tree.
SPACE COMPLEXITY: O(1), no extra space used.
'''
