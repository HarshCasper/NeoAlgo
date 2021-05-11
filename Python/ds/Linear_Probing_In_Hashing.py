"""
Linear Probing is a technique for resolving hash collisions of calues of hash function.It is a form of open addressing.
In this scheme, each cell of a hash table stores a single key–value pair. 
When the hash function causes a collision by mapping a new key to a cell of the hash table that is already occupied by another key, 
linear probing searches the table for the closest following free location and inserts the new key there.
"""

#Function for Linear Probing
def linearProbing( hash, hashSize, arr, sizeOfArray):
    for i in arr:
        keySpace = i % hashSize 
        if hash[keySpace] == -1:
            hash[keySpace] = i
        else:
            for j in range((keySpace+1), (keySpace+hashSize)):
                j = j%hashSize
                if hash[j] == -1:
                    hash[j] = i
                    break                   
#  Driver Code Starts
def main():
    t=int(input())  
    while(t>0):       
        hashSize=int(input())
        sizeOfArray=int(input())
        arr=[int(x) for x in input().strip().split()]
        hash=[-1]*hashSize      
        linearProbing( hash, hashSize, arr, sizeOfArray)       
        for i in hash:
            print(i,end=" ")
        print()
        t-=1
if __name__=="__main__":
    main()
#Driver Code Ends

"""
Sample Input
hashSize=10
sizeOfArray = 3
Array[] = {3,13,23,33}
Sample Output
-1 -1 -1 3 13 23 33 -1 -1 -1

Time Complexity:- Best case: O(1), Worst case: O(n)
Space Complexity:- O(n)"""

