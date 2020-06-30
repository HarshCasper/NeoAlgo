#### Program to traverse a given tree in pre-order, in-order and post-order fashion.

class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None


class Tree:
	def __init__(self, root):
		self.root = TreeNode(root)

	def inorder_traversal(self, node, path):
		if node:
			path = self.inorder_traversal(node.left, path)
			path += str(node.val) + ' '
			path = self.inorder_traversal(node.right, path)

		return path

	def preorder_traversal(self, node, path):
		if node:
			path += str(node.val) + ' '
			path = self.preorder_traversal(node.left, path)
			path = self.preorder_traversal(node.right, path)

		return path

	def postorder_traversal(self, node, path):
		if node:
			path = self.postorder_traversal(node.left, path)
			path = self.postorder_traversal(node.right, path)
			path += str(node.val) + ' '

		return path



#### Creating a tree of the following structure:-

#      1
#    /   \
#   2     3
#  / \   / \
# 4   5 6   7

tree = Tree(1)

tree.root.left  = TreeNode(2)
tree.root.right = TreeNode(3)

tree.root.left.left   = TreeNode(4)
tree.root.left.right  = TreeNode(5)
tree.root.right.left  = TreeNode(6)
tree.root.right.right = TreeNode(7)

#### In-Order Traversal :- left -> root -> right

print(tree.inorder_traversal(tree.root, ''))   # Expected Output:- 4 2 5 1 6 3 7


#### Pre-Order Traversal :- root -> left -> right

print(tree.preorder_traversal(tree.root, ''))  # Expected Output:- 1 2 4 5 3 6 7


#### In-Order Traversal :- left -> right -> root

print(tree.postorder_traversal(tree.root, '')) # Expected Output:- 4 5 2 6 7 3 1


