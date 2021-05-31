"""Quadratic Probing is a collision resolution method in hashing.
Quadratic probing says that whenever a collision occurs, search for i^2 position.
It is more efficient algorith than linear probing since it avoids the clustering problem that can occur with linear probing."""
#Function for Quadratic Probing.
def QuadraticProbing(hash, hashSize, arr, N):  
    for i in range(N):
        hashVal = arr[i]%hashSize
        if hash[hashVal] == -1:
            hash[hashVal] = arr[i]
        else:
            k = arr[i]
            for j in range(1,hashSize):
                hashVal = (k + pow(j,2))%hashSize
                if hash[hashVal] == -1:
                    hash[hashVal] = arr[i]
                    break
                else:
                    continue
#  Driver Code Starts
def main():
    T=int(input()) 
    while(T>0):   
        hashSize=int(input())
        sizeOfArray=int(input())
        arr=[int(x) for x in input().strip().split()]        
        hash = [-1]*hashSize
        QuadraticProbing(hash, hashSize, arr, sizeOfArray)       
        for i in hash:
            print(i,end=" ")
        print()
        T-=1
if __name__=="__main__":
    main()
# } Driver Code Ends

"""
Sample Input
hashSize=11
N = 4
Array[] = {21,10,32,43}
Sample Output
10 -1 -1 32 -1 -1 -1 -1 43 -1 2
Time Complexity:- Best case: O(1), Worst case: O(N)
Space Complexity:- O(N)"""
