'''
Purpose: 
Given a binary tree, print the bottom view of the tree.

Input formate:
Line1: Number of testcases
Line2: Give the nodes array, space seperated 

Output formate: 
Line1: The testcase number 
Line2: The bottom view array 

Concepts used : 
level order traversing 

Datastructures used : 
1) queue 
2) dictionary 
3) array

Explanation : Here in we use level order traversal by keep track of each level.
In here root is taken as reference and marked as 0 position and all towards left are marked negative and 
towards right are marked as positive positioning just like a number line.
and the result is stored in dictionary as position as keys and value as data 

Arguments: array of int type 
return: array of int type 

'''
class node: # A binary tree node 
    def __init__(self,value):
        self.data=value
        self.left=None
        self.right=None
class binaryTree:
    def __init__(self):
        self.root=None
    def build_tree(self,arr,i,root): # function for building the binary tree from given array using recursion 
        if(i>=len(arr)):
            return root
        if(arr[i]!=None):
            temp=node(arr[i])
            root=temp
            root.left=self.build_tree(arr,2*i+1,root.left) # the left child for the given array is supposed to be at 2*i+1 position 
            root.right=self.build_tree(arr,2*i+2,root.right) # similarly to the left child 
        return root
    def bottom_view(self):
        if not self.root:
            return 
        dic={}# to store the result 
        q=[] # for the level order traversal 
        mi=99999
        res=[] # the final result 
        q.append((self.root,0)) 
        while(q):
            cur=q[0]
            q.pop(0)
            hd=cur[1] # to know the position 
            mi=min(mi,hd)# to know the left most position 
            dic[hd]=cur[0].data
            if cur[0].left: # checking if the node has left child or not 
                q.append((cur[0].left,hd-1))
            if cur[0].right: # checking for right child of the node 
                q.append((cur[0].right,hd+1))
        while mi in dic: #finally iterating throught our answer to make it an array 
            res.append(dic[mi])
            mi+=1
        return res
         
def main ():
    for h in range(int(input())):
        arr=list(map(int,input().split()))
        n=len(arr)
        BT=binaryTree()
        BT.root=BT.build_tree(arr,0,None)
        print("TESTCASE ",h+1)
        print(BT.bottom_view())
if __name__ =="__main__":
    main()
        
'''
Sample Input:
2
1 2 3
1 2 3 None 5 None 7
Sample output:
TESTCASE 1
[2,1,3]
TESTCASE 2
[2,1,3,7]

Time complexity: O(N)
Space complexity: O(N)
'''