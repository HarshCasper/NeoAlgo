''' Definition: 
A binomial coefficient C(n, k) can be defined as the coefficient of x^k 
in the expansion of (1 + x)^n.
Input:
Enter the value of n and k :
4 2
Output:
6
Explanation:
4C2=4!/(2!*(4-2)!)
=>(4*3*2*1)/(2*1*2*1)
=>6
'''
#Time Complexity: O(n*k)
#Space Complexity: O(n*k)
def binomialCoeffMemorization(n,k,dp):
    if n==k or k==0:#if n is equal to k or if k is equal to 0 then it is return 1 as nCn and nC0 is 1
        return 1
    elif dp[n][k]!=-1: #Checks whether dp[n][k] is already present
        return dp[n][k]#Returns dp[n][k] if present
    else:#Storing dp[n-1][k-1]+dp[n-1][k] to dp[n][k]
        dp[n][k]=binomialCoeffMemorization(n-1,k-1,dp)+binomialCoeffMemorization(n-1,k,dp)
    return dp[n][k]
def binomialCoefTabulation(n,k):
    dp2=[[-1 for row in range(k+1)] for col in range(n+1)]
    for row in range(n+1):
        for col in range(k+1):
            if col<=row :
                if col==0 or row==col:
                    dp2[row][col]=1
            else:
                dp2[row][col]=dp2[row-1][col-1]+dp2[row-1][col]
    print("Tabulation: {}C{} = {}".format(n,k,binomialCoeffMemorization(n,k,dp)))
n,k=map(int,input("Enter the value of n and k : ").split())
dp=[[-1 for row in range(k+1)] for col in range(n+1)]
#print(dp)
print("Memorization: {}C{} = {}".format(n,k,binomialCoeffMemorization(n,k,dp)))
binomialCoefTabulation(n,k)
