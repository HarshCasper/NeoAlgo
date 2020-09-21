# Program to calculate the depth of a Tree
# Note that the levels start from 0(Zero).


class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Tree:
    def __init__(self, root):
        self.root = TreeNode(root)

    def get_node_depth(self, node, val, depth):
        if node is None:
            return -1

        if node.val is val:
            return depth

        l_depth = self.get_node_depth(node.left, val, depth+1)
        r_depth = self.get_node_depth(node.right, val, depth+1)

        return max(l_depth, r_depth)

    def get_maximum_depth(self, node, depth):
        if node is None:
            return -1

        l_depth = 1 + self.get_maximum_depth(node.left, depth+1)
        r_depth = 1 + self.get_maximum_depth(node.right, depth+1)

        return max(l_depth, r_depth)


# Creating a tree of the following structure:-

#      1
#    /   \
#   2     3
#  / \   / \
# 4   5 6   7

tree = Tree(1)

tree.root.left = TreeNode(2)
tree.root.right = TreeNode(3)

tree.root.left.left = TreeNode(4)
tree.root.left.right = TreeNode(5)
tree.root.right.left = TreeNode(6)
tree.root.right.right = TreeNode(7)

# Printing the depth of each node
for i in range(1, 8):
    print(tree.get_node_depth(tree.root, i, 0))
    # Should print : 0 1 1 2 2 2 2

# Printing the maximum depth of the tree
print("Maximum Depth: ", tree.get_maximum_depth(tree.root, 0))
# Should print: 2

# Print -1 for the depth if the node is not present in the tree
print("If element not present", tree.get_node_depth(tree.root, 10, 0))
# Should print: -1
