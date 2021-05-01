'''
Backtracking: Backtracking is a general algorithm for finding all (or some) solutions to some computational problems, notably constraint satisfaction problems.

Problem statement: Given a set of n integers, divide the set into 2 halves such a way that the difference of sum of 2 sets is minimum.

Input formate:
Line1: Number of test casses 
Line2: The length of the array 
Line3: space seperated array elements 

Output formate: 
The 2 array subsets

Method:
Backtracking 

Intuition: As there can be any possibility we try to check all the possible chances of forming subarrays according to the given possibility.
We intent to form one subset and push the rest of the elements to the other subset.
For every element that we iterate through there are 2 possibilities
1) Belongs to first subset 
2) Dosent belong to first subset 
While iterating we also check for the best solution so far and update it.

Argument: int,Array
return: Array 

'''

def utilfun(arr,n,curr,num,sol,min_diff,sumn,curr_sum,pos):
    '''
    Here the arr is the input and n is its size
    curr is an arr containing curr elements in first subset and num is the length
    sol is the final boolean arr; true means the element is in the first subset
    sumn is tracking the sum of the first subset 
    '''
    #Base Case1 :check if the array is out of bound 
    if(pos==n):
        return
    #Base Case2 :check if the number of elements is not less than the number of elements int he solution 
    if ((int(n/2)-num)>(n-pos)):
        return 
    #case1: when current element is not in the solution 
    utilfun(arr,n,curr,num,sol,min_diff,sumn,curr_sum,pos+1)
    #case2: when the current element belongs to first subset
    num+=1
    curr_sum+=arr[pos]
    curr[pos]=True
    #checking if we got the desired subset array length
    if(num==int(n/2)):
        #checking if the solution is better or not so far 
        if(abs(int(sumn/2)-curr_sum)<min_diff[0]):
            min_diff[0]=abs(int(sumn/2)-curr_sum)
            for i in range(n):
                sol[i]=curr[i]
        else:
            utilfun(arr,n,curr,num,sol,min_diff,sumn,curr_sum,pos+1)
        curr[pos]=False
def tugofwar(arr,n):
    curr=[False]*n
    sol=[False]*n
    min_diff=[999999999]
    sumn=0
    for i in range(n):
        sumn+=arr[i]
    utilfun(arr, n, curr, 0, sol, min_diff, sumn, 0, 0)
    return sol

# driver code 
def main():
    for _ in range(int(input())):
        n=int(input())
        arr=list(map(int,input().split()))
        sol=tugofwar(arr, n)
        print("First subset is: ",end="")
        for i in range(n):
            if(sol[i]==True):
                print(arr[i],end=" ")
        print("\n")
        print("Second subset is: ",end="")
        for i in range(n):
            if(sol[i]==False):
                print(arr[i],end=" ")
        print("\n")

if __name__ == '__main__':
    main()

'''
Sample Input:
1
11
23 45 -34 12 0 98 -99 4 189 -1 4

Sample output:
First Subset is: 45 -34 12 98 -1
Second subset is: 23 0 -99 4 189 4

Time Complexity: O(n^2)
Space Complexity: O(n)
'''
