"""
Post Order Binary tree traversal follows the pattern:

Left Child -> Right Child -> Root
"""


class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    # Function to insert nodes into tree
    def insert(self, array_of_nodes):

        # Queue to create the tree
        queue = []
        self.root = Node(int(array_of_nodes.pop(0)))
        queue.append(self.root)
        size_of_queue = len(queue)

        # Logic for nodes insertion
        while array_of_nodes:
            while size_of_queue:
                root = queue.pop(0)
                if root:
                    value = array_of_nodes.pop(0)
                    if value == 'null':
                        root.left = None
                    else:
                        root.left = Node(int(value))
                        queue.append(root.left)
                    value = array_of_nodes.pop(0)
                    if value == 'null':
                        root.right = None
                    else:
                        root.right = Node(int(value))
                        queue.append(root.right)
                size_of_queue -= 1
            size_of_queue = len(queue)

    # Function to perform Post order traversal on our tree
    def postorder_traversal(self, root):

        if not root:
            return []

        # This will be our main list that contains the traversed tree
        self.traversed = []

        # This list will help in the creation of traversed list
        helper_stack = [root]

        # Keeping track of visited nodes
        left_visited_nodes = set()
        right_visited_nodes = set()

        # Main logic for post order traversal
        while helper_stack:

            # Temporary list of nodes to check visited nodes
            temp = helper_stack[-1]

            # Checking left childs
            while temp.left and temp not in left_visited_nodes:
                helper_stack.append(temp.left)
                left_visited_nodes.add(temp)
                temp = temp.left

            # Checking right childs
            if temp.right and temp not in right_visited_nodes:
                right_visited_nodes.add(temp)
                helper_stack.append(temp.right)
                temp = temp.right

            else:
                temp = helper_stack.pop()
                self.traversed.append(temp.value)

        return self.traversed


def main():

    user_defined_tree = list(
        input("Enter the elements of your tree: ").split(','))

    postorder_tree = Tree()
    postorder_tree.insert(user_defined_tree)

    print("Your post order traversed tree:")

    # Final traversed tree
    tree = postorder_tree.postorder_traversal(postorder_tree.root)
    print(tree)


main()


# Sample Input - Output:

# First sample:

# Input: 1,2,3,null,null,4,5
#Output: [2,4,5,3,1]

# Second sample:

# Input: 2,3,4,5,6,1,7
# Output: 5,6,3,1,7,4,2
