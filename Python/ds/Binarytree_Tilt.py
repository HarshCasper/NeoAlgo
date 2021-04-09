'''
Given the root of a binary tree, return the sum of every tree node's tilt.
Using Post-order DFS,firstly traverse each node, and calculate the tilt value for each node. At the end, we sum up all the tilt values.
Ex:
  1               1
 / \     ===>    / \
2   3           0   0
The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. 
'''
from queue import Queue
class TreeNode: 
    #binary tree Node definition
    def __init__(self,val): 
        self.left = None
        self.right = None
        self.val = val 

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

    def findTilt(self, root): 
        tilt_sum = 0
        def helper(node:TreeNode):  
            if not node:
				# base case: empty node or empty tree
                return 0
        
            else: 
                left_sum = helper(node.left)
                right_sum = helper(node.right)
				# update tilt sum for whole binary tree
                nonlocal tilt_sum
                tilt_sum += abs(left_sum - right_sum)
                return left_sum + node.val + right_sum
        
        helper( root )
        return tilt_sum

#main function
if __name__ == "__main__":
    data = []
    #append data into tree, input list is single line seperated with commas  
    for element in input().split(','):
        if element == 'None':
            data.append(None)
        else:
            data.append(int(element))
    tree = Tree(data)
    print(tree.findTilt(tree.root))

'''
Test Case 1:

Input: [1,2,3]
Output: 1

Test Case 2:

Input: [4,2,9,3,5,None,7]
Output: 15

Test Case 3:
Input: [21,7,14,1,1,2,2,3,3]
Output: 9

Time Complexity: O(n)
Space Complexity: O(n)
'''
