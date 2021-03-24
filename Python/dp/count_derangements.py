'''
A Derangement is a permutation of n elements, such that no element appears in its original position.

Problem statement: Given a number n, find total number of Derangements of a set of n elements.

Input format
Line1: Number of test cases
Line2: Give the value of n

Output format
The total number of derangement

Basic idea is to use dynamic programming and identify a pattern: 
base case : n=1 answer 0
            n=2 answer 1
for other values of n: 
    eg: 0 can be placed in a position with given conditions in (n-1) ways
    now has 2 possiblities:
        either 0 can be placed in ith position implies (n-2) elements should be placed  
        else 0 neednt be placed in ith position  implies (n-1) elements should be placed in some position 
hence we come to a relation as follows: 
count_derangement(n) = (n - 1) * [count_derangement(n - 1) + count_derangement(n - 2)]

argument: integer (value of n)
return: integer (total number of derangements)

'''
def derangements(n):
    #dynamic programming table 
    d=[0 for i in range(n+1)]
    #base casses 
    d[1]=0
    d[2]=1
    for i in range(3,n+1):
        d[i]=(i-1)*(d[i-1]+d[i-2])
    return d[n]
#Driver code 
def main():
    for _ in range(int(input())):
        n=int(input())
        print(derangements(n))
if __name__=='__main__':
    main()
'''
Sample Input
1
4

Sample Output
9

Sample Explanation
As n=4 we have original array, a=[0,1,2,3] Now we can have different derangements as:
[1, 0, 3, 2], [1, 2, 3, 0], [1, 3, 0, 2],[2, 3, 0, 1], [2, 0, 3, 1], [2, 3,1, 0], [3, 0, 1, 2], [3, 2, 0, 1] and [3, 2, 1, 0]

Time complexity : O(n)
Space Complexity : O(n)

'''
