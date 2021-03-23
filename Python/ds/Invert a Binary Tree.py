"""
 The inversion of a Binary Tree (T) is also a Binary tree (M) with left and right children of T swapped.
"""

from queue import Queue


class TreeNode:
    """
    Definition of binary tree node
    """

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Tree:
    def __init__(self, values):
        def createTree(i: int, arr: list) -> TreeNode:
            node = TreeNode(arr[i])
            left_child = 2 * i + 1
            right_child = 2 * i + 2
            if left_child < len(arr) and arr[left_child] is not None:
                node.left = createTree(left_child, arr)
            if right_child < len(arr) and arr[right_child] is not None:
                node.right = createTree(right_child, arr)
            return node

        self.root = createTree(0, values)

    def preOrder(self, node):
        if node:
            print(node.val)
            self.preOrder(node.left)
            self.preOrder(node.right)

    def invert(self):
        """
        Inverts the binary tree recursively
        """
        def invertHelper(node):
            """
            -> Swap left and right child nodes of the current node.
            -> Call invert for the left child.
            -> Call invert for the right child.
            """
            if node:
                node.left, node.right = node.right, node.left
                invertHelper(node.left)
                invertHelper(node.right)

        invertHelper(self.root)

    def invert_iter(self):
        """
        Inverts the binary tree iteratively using a queue
        """
        def iterativeHelper(root) -> TreeNode:
            if root:
                q = Queue()
                q.put(root)
                while q.qsize() > 0:
                    node = q.get()
                    node.left, node.right = node.right, node.left
                    if node.left:
                        q.put(node.left)
                    if node.right:
                        q.put(node.right)
            return root

        self.root = iterativeHelper(self.root)

    def print(self):
        self.preOrder(self.root)


if __name__ == "__main__":
    data = []
    for element in input().split():
        if element == 'None':
            data.append(None)
        else:
            data.append(int(element))
    tree = Tree(data)
    print("Recursive Method:")
    tree.invert()
    tree.print()
    print("\nIterative Method:")
    tree.invert_iter()
    tree.print()

# Sample 1:
# Input: 2 1 3
#       2
#     /   \
#    1     3
# After Inversion :
#       2
#     /   \
#    3     1

# Sample 2:
# Input: 2 1 4 None None 3 5
#       2
#     /   \
#    1     4
#        /   \
#       3     5
# After Inversion :
#       2
#     /   \
#    4     1
#  /   \
# 5      3

# Sample 3:
# Input: 4 2 6 1 3 5 7
#             4
#         /       \
#        2          6
#     /    \     /     \
#    1     3    5       7
# After Inversion :
#             4
#         /       \
#        6          2
#     /    \     /     \
#    7      5   3       1
