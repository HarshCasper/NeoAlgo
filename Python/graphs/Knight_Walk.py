# Importing sys module to initalize the maxsize
import sys
# Importing collections model to access deque
from collections import deque
''' Knight-Walk '''
'''Problem Statement :Given a chess board of order N x M and
                      source points (s1, s2) and destination
                      points (d1, d2). The task to find minimum
                      number of moves required by the Knight to
                      go to the destination cell.
                      Note: The chess board consists of rows
                      numbered (1 to N) and columns (1 to M).
'''
# Assigning max value a variable can take
INT_MAX = sys.maxsize - 1
# Initialize Infinity
INF = 9999999
# All the posible moves of the knight
row = [2, 2, -2, -2, 1, 1, -1, -1]
col = [-1, 1, 1, -1, 2, -2, 2, -2]


# Create the Node
class Node:
    def __init__(self, x, y, dis=0):  # Distance of self from itself
        self.x = x
        self.y = y
        self.dis = dis

    # Since we are using the nodes as a hash we will need a
    # hashtable
    def __hash__(self):
        return hash((self.x, self.y, self.dis))

    def __eq__(self, other):
        return (self.x, self.y, self.dis) == (other.x, other.y, other.dis)
# Enter the number of rows
print("Enter the number of matrix : ")
n = int(input("Row:"))
# Taking input of the address of the source and destination
# as a tuple
print("Enter the source:")
x = int(input("src1:"))
y = int(input("src2:"))
src = Node(x, y)
print("Enter the source:")
x = int(input("des1:"))
y = int(input("des2:"))
des = Node(x, y)
# Knight Walk


def kinghtwalk(n, src, des):
    # Set to check if the cell is visited or not
    visited = set()
    # Create the queue to check the next reachable cell
    queue = []
    queue.append(src)
    # Loop while the queue is empty
    while queue:
        node = queue.pop(0)
        x = node.x
        y = node.y
        dis = node.dis
        if x == des.x and y == des.y:
            return dis
        if node not in visited:
            visited.add(node)
            for i in range(8):
                a = x + row[i]
                b = y + row[i]
                if present(a, b, n):
                    queue.append(Node(a, b, dis + 1))
# Check if the given node is valid or not


def present(a, b, n):
    # If either one of then is not true it mean the cell is
    # outside the board
    return not(a < 0 or y < 0 or x >= n or y >= n)
KW = kinghtwalk(n, src, des)
print("Minumun nunbers of paths are {}".format(KW))
'''
Sample input:
    Enter the number of matrix :
    Row:8
    Enter the source:
    src1:0
    src2:7
    Enter the source:
    des1:7
    des2:0
Sample Output:
    Minumun nunbers of paths are 6
'''
# Time complexity: O(N^2)
