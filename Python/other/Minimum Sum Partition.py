"""
In this problem given set is partitioned into two subsets
 such that the difference between the sum of elements
  of 1st set and the sum of elements of 2nd set is minimized.
"""

"""
    This problem has an optimal structure i.e. the problem can be broken into number 
    of smaller,simpler subproblems,which can be further divided into yet smaller and simpler,
    smaller subproblems until the solution becomes trivial. 
"""
import sys

#Using Dynamic Programming Approach
#Partition the set S into two subsets S1,S2 such that the
#difference between the sum of elements is S1 and the sum of
#elements in S2 is minimized

def MinimumSumPartition(arr):
    
    #Taking Sum of all elements
    summ = sum(arr)
    
    #Creating a matrix to store values(True,False) 
    # for results of subproblems
    
    mat = []
    for i in range(len(arr)+1):
        row=[]
        for j in range(summ+1):
            row.append(0)
        mat.append(row)
    
    #Now sum 0 can be possible with any number of elements of array so taking all elements to be True in first column
    for j in range(summ+1):
        mat[0][j] = True
    
    
    #Now with zero elements only sum 0 is possible so initialising all other elements in first row to be False 
    for i in range(len(arr)+1):
        mat[i][0] = False
        
        
    #Filling the Partition Matrix 
    for i in range(1,len(arr)+1):
        for j in range(1,summ+1):
            
            #If ith element is excluded
            mat[i][j] = mat[i-1][j]
            
            #If ith element is included
            if arr[i-1] <=j:
                mat[i][j] |= mat[i-1][j-arr[i-1]]
                

    #Intialising the Variable for difference
    minn = sys.maxsize

    #Find largest j in which mat[n][j] is true       
    #Taking the last row with True values till half of range            

    for j in range(summ//2,-1,-1):
        if mat[len(arr)-1][j]==True:
            minn=summ-(2*j)             #We break the loop after getting first value of j because differene would be minimum at max value of j
            break
    return minn
        

#Implementing the Function
if __name__ == '__main__':
    #Take input the size of array
    n = int(input("Enter size of array\n"))
    
    #Taking input the values of array
    arr=[]
    print("Enter elements of array ")
    for i in range(n):
        i=int(input())
        arr.append(i)
    
    print("The minimum difference between two subsets of array is {}".format(MinimumSumPartition(arr)))
    
    
"""

Sample Input/Output

Enter size of array
4
Enter elements of array
1
6
11
5

The minimum diiference between two subsets of array is 1

Time Complexity : O(2*n)
Space Complexity : O(n)


"""

    
