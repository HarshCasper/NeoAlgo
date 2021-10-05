'''
    Author: Dasu Srinivas
    Description: Calculates the height of the given  Binary Tree

    Time Complexity: O(log N),  Worst-Case: O(N)
    Space Complexity: O(1)
            Where N is the total number of nodes
'''
# Strucure of a Binary Node
class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

def height_of_tree(node):
    if node is None:
        return 0
    else:
        left_height = height_of_tree(node.left)
        right_height = height_of_tree(node.right)

        # will give the maximum height
        if left_height > right_height:
            return left_height+1
        else:
            return right_height+1


#----------------------------------------- Driver Code -------------------------
if __name__ == "__main__":
    root_node = Node(1) 
    root_node.left = Node(21) 
    root_node.right = Node(23) 
    root_node.left.left = Node(34) 
    root_node.right.left = Node(37)
    root_node.right.rights = Node(46)
    root_node.right.left.left = Node(55)

    print("Height of the given tree is:", height_of_tree(root_node))

"""
Sample Input / Output:

                     1
                    / \
                   /   \
                  /     \
                21       23
               /         / \
              /         /   \
             /         /     \
           34         37     46
                     /
                    /
                   /
                 55  
    Output = 4
"""