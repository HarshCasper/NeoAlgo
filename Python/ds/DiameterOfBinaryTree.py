'''
Theory-
The diameter of a tree can be defined as the
maximum distance between two leaf nodes.
Here, the distance is measured in terms of the
total number of nodes present along the path
of the two leaf nodes, including both the leaves.
'''


import queue
from sys import stdin


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def levelOrderInput():
    '''
    Summary Line:
    This function helps us to take level order
    input and build the tree.

    Args:
    No arguments

    Returns:
    Root- root of the tree formed using level
    order input
    '''
    tlist = list(map(int, stdin.readline().strip().split(" ")))
    start = 0
    data = tlist[start]
    start += 1
    if data != -1:
        root = Node(data)
    else:
        return None
    q = queue.Queue()
    q.put(root)
    while not q.empty():
        current = q.get()
        data = tlist[start]
        start += 1
        if data != -1:
            leftChild = Node(data)
            current.left = leftChild
            q.put(leftChild)
        data = tlist[start]
        start += 1
        if data != -1:
            rightChild = Node(data)
            current.right = rightChild
            q.put(rightChild)
    return root


def Diameter(root):
    '''
    Summary Line:
    This function helps us to calculate the diameter
    of our tree. Diameter is the number of nodes
    between the two farthest nodes in our tree.

    Args:
    root- root of our inputted tree

    Returns-
    h- height of the tree
    d- diameter of the tree

    Intuition-
    Height is calculated because the diameter
    is the sum of max left and max right heights.
    '''
    if root is None:
        return 0, 0
    lh, ld = Diameter(root.left)
    rh, rd = Diameter(root.right)
    h = 1 + max(lh, rh)
    d = lh + rh
    b = max(d, max(ld, rd))
    return h, b

if __name__ == "__main__":
    print("Enter level order input for the tree:")
    root = levelOrderInput()
    h, d = Diameter(root)
    print(d + 1)  # added 1 for the root node


'''

Input format-
The first and the only line of input will
contain the node data, all separated by a single space.
Since -1 is used as an indication whether the
left or right node data exist for root,
it will not be a part of the node data.

Sample Input-
Enter level order input for the tree:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Illustration for the tree formed using the input-
     1
   /   \
  2     3
 / \   / \
4   5 6   7

Sample Output-
5

Time complexity- O(N^2)

'''
