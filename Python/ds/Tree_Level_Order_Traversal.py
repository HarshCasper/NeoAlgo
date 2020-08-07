#### Level Order Traversal of a Tree

class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None


class Tree:
	def __init__(self, root):
		self.root = TreeNode(root)


	def level_order_traversal(self, root):
		nodes_visited = [root]
		path = ''
		while len(nodes_visited) > 0:
			node = nodes_visited.pop(0)
			if node.left:
				nodes_visited.append(node.left)
			if node.right:
				nodes_visited.append(node.right)

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

#### Level Order Traversal
#### In level order traversal, every node at the 
#### same level is visited before moving on to the next.

print(tree.level_order_traversal(tree.root)) # Expected Output:- 1 2 3 4 5 6 7


