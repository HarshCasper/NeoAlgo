"""A valid Binary Search Tree is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

"""

import math


class TreeNode:
    """
    Definition of binary tree node
    """

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def createTree(i: int, arr: list) -> TreeNode:
    node = TreeNode(arr[i])
    left_child = 2 * i + 1
    right_child = 2 * i + 2
    if left_child < len(arr) and arr[left_child] is not None:
        node.left = createTree(left_child, arr)
    if right_child < len(arr) and arr[right_child] is not None:
        node.right = createTree(right_child, arr)
    return node


def isValidBST(root: TreeNode) -> bool:
    return explore(root, -math.inf, math.inf)


def explore(node: TreeNode, mini: int, maxi: int) -> bool:
    """
    Explores the tree (Depth First Search)
    - Returns False when the node that doesn't satisfy any of the BST properties
    is encountered.
    - Returns True when all the nodes in tree are satisfying BST properties
    and the entire tree has been explored.

    # Time complexity : O(N) since we visit each node exactly once.
    # Space complexity : O(N) since we keep up to the entire tree.
    """
    if node:
        if node.val <= mini or node.val >= maxi:
            return False
        if not explore(node.left, mini, node.val):
            return False
        if not explore(node.right, node.val, maxi):
            return False
    return True


if __name__ == "__main__":
    data = []
    for element in input().split():
        if element == 'None':
            data.append(None)
        else:
            data.append(int(element))
    tree = createTree(0, data)
    print(isValidBST(tree))

# Sample 1 Input - Output
# Input: 2 1 3
#       2
#     /   \
#    1     3
# Output: True
# This tree is a valid bst

# Sample 2 Input - Output
# Input: 5 1 4 None None 3 6
#       5
#     /   \
#    1     4
#        /   \
#       3     6
# Output: False
# This tree is invalid bst
# as node 3 in the right subtree of root is less than the root

# Sample 3 Input - Output
# Input: 1 None 2 None None None 3 None None None None None None None 4
#    1
#     \
#      2
#       \
#        3
#         \
#          4
# Output: True
# This tree is a valid bst

# Sample 4 Input - Output
# Input: 4 2 6 1 3 5 7
#             4
#         /       \
#        2          6
#     /    \     /     \
#    1     3    5       7
# Output: True
# This tree is a valid bst

# Sample 5 Input - Output
# Input: 4 2 None 1 5
#           4
#         /
#        2
#     /    \
#    1      5
# Output: False
# This tree is invalid bst
# as node 5 in left sub tree of the root is greater than the root
