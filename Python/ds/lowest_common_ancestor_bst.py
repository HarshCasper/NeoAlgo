'''
Lowest Common Ancestor is defined as the lowest node 
that is farthest from the root and has p and q it's descendants.
And we allow the node to be descendant of itself.

Purpose: Find the lowest common ancestor of two nodes in a binary search tree.

Intuition: LCA is the split point where the two nodes won't be part of same subtree 
or one being the parent of the other.

Time Complexity: O(N), in worst case we may have to visit all the nodes.
SPace Complexity: O(1)
'''


# class that represents a node of the binary search tree
class Node:
    
    def __init__(self, val):
        self.left=None
        self.right=None
        self.val=val
    
    # insert a new node in the BST
    def insert(self, root, val):
        
        node=Node(val)
        
        # if tree is empty return this new node
        if root is None:
            return node
        
        # otherwise traverse the tree to insert the node
        current=root
        while True:
            # case for node to be inserted in right subtree
            if current.val<val:
                if current.right is None:
                    current.right = node
                    return root
                current=current.right
                
            # case for node to be inserted in left subtree
            elif current.val>val:
                if current.left is None:
                    current.left= node
                    return root
                current=current.left
                
    # function for finding the lowest common ancestor of two nodes
    # iterative version
    def lowestCommonAncestor(self, root, p, q):
        pVal=p
        qVal=q
        node=root
        # traverse the tree
        while node:
            # if p>current node and q> current node, 
            # then traverse the right subtree
            if pVal>node.val and qVal>node.val:
                node=node.right
            # when p< current.node and q< current.node,
            # then traverse the left subtree
            elif pVal<node.val and qVal<node.val:
                node=node.left
            # returns the current node 
            # when p lies in left subtree and q in right subtree or vice versa
            #     node              node
            #     /  \       or     /  \
            #    p    q            q    p   
            #
            else:
                return node

# driver code    
if __name__=='__main__':
    
    # input the binary search tree elements from the user
    s=int(input("Enter the value of the root\n"))
    root=Node(s)
    
    while True:
        s=input("Add the node value to be inserted(Enter N if you dont wish to insert more nodes)\n")
        if s=='N':
            break
        root=root.insert(root,int(s))
    
    print("Enter the two nodes value for finding Lowest Common Ancestor")
    a,b=list(map(int, input().split()))
    
    # getting the lowest common ancestor of a and b
    ans=root.lowestCommonAncestor(root,a,b)
    
    # print the value of the lowest common ancestor
    print("Lowest Common Ancestor is: ", ans.val )
'''
Sample Test Cases:

            50
           /  \
          30   70
         / \   / \
        20 40 60 80
        
Input/Output #1:
Enter the value of the root
50
Add the node value to be inserted(Enter N if you dont wish to insert more nodes)
20
Add the node value to be inserted(Enter N if you dont wish to insert more nodes)
30
Add the node value to be inserted(Enter N if you dont wish to insert more nodes)
40
Add the node value to be inserted(Enter N if you dont wish to insert more nodes)
70
Add the node value to be inserted(Enter N if you dont wish to insert more nodes)
60
Add the node value to be inserted(Enter N if you dont wish to insert more nodes)
80
Add the node value to be inserted(Enter N if you dont wish to insert more nodes)
N
Enter the two nodes value for finding Lowest Common Ancestor
30 40
Lowest Common Ancestor is:  30

'''
