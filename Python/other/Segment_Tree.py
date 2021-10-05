"""
Purpose: Let us consider the following problem to understand Segment Trees.
        We have an array arr[0 . . . n-1]. We should be able to 
        1 Find the min of elements from index l to r where 0 <= l <= r <= n-1
        2 Change value of a specified element of the array to a new value x. 
        We need to do arr[i] = x where 0 <= i <= n-1.
         
Article Link:- https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

Method: Segment Tree
Intution: Like Heap, the segment tree is also represented as an array. 
        The difference here is, it is not a complete binary tree. It is
        rather a full binary tree (every node has 0 or 2 children) and all
        levels are filled except possibly the last level. Unlike Heap,
        the last level may have gaps between nodes.

Time Complexity:  
        O(log(n)) -> for finding the min
        O(log(n)) -> for update query
Space Complexity: O(N)

Argument: Array containg the elements
Return  : for each query, return an integer denoting the desired ans

"""

from time import time
class Seg:
    def __init__(self,arr):
        self.size=1
        n = len(arr)

        # intilising the Segment Tree
        while(self.size<n):
            self.size*=2
        self.seg=[10e9]*(2*self.size)

        for i in range(n):
            self.seg[self.size-1+i]=arr[i]
        temp=self.size//2-1

        while(temp>=0):
            for i in range(temp,2*temp+1):
                self.seg[i]=min(self.seg[2*i+1],self.seg[2*i+2])
            temp=(temp+1)//2-1

    # For update query
    def update(self,x,y):
        pos=self.size-1+x
        self.seg[pos]=y
        temp=(pos-1)//2
        while(temp>=0):
            self.seg[temp]=min(self.seg[2*temp+1],self.seg[2*temp+2])
            temp=(temp-1)//2

    # for fing query        
    def find(self,x,lx,rx,l,r):
        if(rx<=l) or (lx>=r):
            return 10e9
        if(l<=lx and rx<=r):
            return self.seg[x]
        ans=0;mid=(lx+rx)//2
        ans+=min(self.find(2*x+1,lx,mid,l,r),self.find(2*x+2,mid,rx,l,r))
        return ans

# ------------------------DRIVER CODE ------------------------

if __name__ == "__main__":

    # Input the initial Position of the Knight
    n = int(input("Enter the length of array "))
    print("Enter the Array ")
    arr = [int(i) for i in input().split()]
    query = int(input("Enter the nuber of queries "))
    start = time()
    seg_tree = Seg(arr)
    
    # for each query will consist of 3 integers
    # <query type> <index> <index/val>
    for _ in range(query):
        query_type, x, y = map(int, input().split())
        
        # for update Query
        if query_type == 1:
            seg_tree.update(x,y)
            arr[x-1] = y
            print("Value at index ", x, " is updated to", y)
            print("Array: ", *arr)
        
        elif query_type == 2:
            print("Minimum from the given range is ", seg_tree.find(0,0,seg_tree.size,x,y))
        

    print("Time taken: ", time()-start)

"""
Sample Input / Output

Enter the length of array 6
Enter the Array
2 4 6 3 3 2
Enter the nuber of queries 4
2 3 6
Minimum from the given range is  2
1 6 5
Value at index  6  is updated to 5
Array:  2 4 6 3 3 5
2 3 6
Minimum from the given range is  3
2 5 5
Minimum from the given range is  3
Time taken:  65.34857654571533
"""
