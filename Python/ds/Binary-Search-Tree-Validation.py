"""A valid Binary Search Tree is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

"""
import typing
# Python's typing module provides a way of hinting what type of objects are being used. This makes the code more readable and robust.
import math


class TreeNode:
    """
    Defination of binary tree node
    """

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def createTree(i: int, arr: list) -> TreeNode:
    node = TreeNode(arr[i])
    leftChild = 2 * i + 1
    rightChild = 2 * i + 2
    if leftChild < len(arr) and arr[leftChild] is not None:
        node.left = createTree(leftChild, arr)
    if rightChild < len(arr) and arr[rightChild] is not None:
        node.right = createTree(rightChild, arr)
    return node


def isValidBST(root: TreeNode) -> bool:
    return explore(root, -math.inf, math.inf)


def explore(node: TreeNode, mini: int, maxi: int) -> bool:
    """
    Explores the tree (Depth First Search)
    - Returns False when the node that doesn't satisfy any of the BST properties is encountered.
    - Returns True when all the nodes in tree are satisfying BST properties and the entire tree has been explored.

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
    root1 = createTree(0, [2, 1, 3])
    print(isValidBST(root1))
    #       2
    #     /   \
    #    1     3
    # This tree is a valid bst
    root2 = createTree(0, [5, 1, 4, None, None, 3, 6])
    print(isValidBST(root2))
    #       5
    #     /   \
    #    1     4
    #        /   \
    #       3     6
    # This tree is invalid bst as node 3 in the right subtree of root is less than the root
    root3 = createTree(0, [1, None, 2, None, None, None,
                           3, None, None, None, None, None, None, None, 4])
    print(isValidBST(root3))
    #    1
    #     \
    #      2
    #       \
    #        3
    #         \
    #          4
    # This tree is a valid bst
    root4 = createTree(0, [4, 2, 6, 1, 3, 5, 7])
    print(isValidBST(root4))
    #             4
    #         /       \
    #        2          6
    #     /    \     /     \
    #    1     3    5       7
    # This tree is a valid bst
    root5 = createTree(0, [4, 2, None, 1, 5])
    print(isValidBST(root5))
    #           4
    #         /
    #        2
    #     /    \
    #    1      5
    # This tree is invalid bst as node 5 in left sub tree of the root is greater than the root
