#Linear Probing is a collision resolution method in hashing.

#Sample Input
#hashSize=10
#sizeOfArray = 3
#Array[] = {3,13,23,33}
#Sample Output
#-1 -1 -1 3 13 23 33 -1 -1 -1

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