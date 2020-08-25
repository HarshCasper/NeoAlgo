''' Minimum no of coins required'''
import sys

INT_MAX = sys.maxsize - 1

coins = list(map(int,input().split()))

value = int(input())

# size of coins list
n = len(coins)

# constructing a matrix of size n * value
k = [[0 for i in range(value + 1)] for j in range(n + 1)] 

# Bottom Up Dp Apporach

# coinchange function
def coinChange(coins,value,n):

  # Initialize first row with sys.maxsize
  for i in range(1,value+1):
    k[0][i] =INT_MAX

  # Initialize first column with 0
  for j in range(n+1):
    k[j][0] = 0


  for i in range(1,n+1):
    for j in range(1,value+1):

      # checking if coins[i-1] is less than index j
      if coins[i-1] <= j:

        # assigning the min value 
        k[i][j] = min(k[i][j-coins[i-1]] + 1, k[i-1][j])
      else:
        # assigning the previous value from matrix
        k[i][j] = k[i-1][j]

  # returns value in n * value block
  return k[n][value]

min_coins = coinChange(coins,value,n)

# printing the min required coins
print(min_coins)

    