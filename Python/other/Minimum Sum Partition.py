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

#Using Dynamic Approach
#Partition the set S into two subsets S1,S2 such that the
#difference between the sum of elements is S1 and the sum of
#elements in S2 is minimized

def minPartition(S,n,S1=0,S2=0,lookup={}):

    #base case : if list becomes empty, return the absolute
    #difference beteen two sets
    if n<0:
        return abs(S1-S2)

    #Construct an unique dict key from dynamic elements of input
    #Note that can uniquely identify the sub problem with n and S1 or
    # as s2 is not hing but S-S1 where S is sum of all elements
    key = (n,S1)

    #if subproblem is seen for first time ,solve it and
    #store its result in dict
    if key not in lookup:

        #Case1 - include current item in the subset S1 and recursively
        #for remaining items(n-1
        inc = minPartition(S,n-1,S1+S[n],S2,lookup)

        #Case2 - exclude current item from subset S1 and recur for remaining
        #items(n-1)
        exc = minPartition(S,n-1,S1,S2+S[n],lookup)

        lookup[key] = min(inc,exc)

    return lookup[key]

if __name__ == '__main__':

    #Input the set of items
    arr = list(map(int,input("Enter values of set separated by space \n").split()))
    print("The Minimum sum difference is ",minPartition(arr,len(arr)-1))
   
"""
  Input : Enter values of set separated by space 
    10 20 15 5 25
  output : The Minimum sum difference is 5
  
  Calculations 
  Subsets formed will be  S1 (10,20,5) S2 (15,25)   or   S1 (10,25) S2 (20,15,5)
"""
