<<<<<<< HEAD
=======
''' Minimum no of coins required'''
>>>>>>> 00d5b8a740755e635cb63b775555f018e63ac7dd

'''Problem Statement : Given coins of different denominations with infinite supply and a total amount of money amount. 
                      Compute the fewest number of coins required to make up that amount.
'''

#importing sys module to initalize the maxsize 
import sys

# assigning max value a variable can take
INT_MAX = sys.maxsize - 1

# taking input of list of coins
<<<<<<< HEAD
print("Enter coins denominations :")
coins = list(map(int,input().split()))
print("Given coins denominations are: ",coins)

# taking input of value of coin to be changed
print("Enter the total amount:")
value = int(input())
print("Given total amount is: ", value)
=======
print("Enter the coins denominations")
coins = list(map(int,input().split()))
print("Given Coins Denominations are: ",coins)

# taking input of value of coin to be changed
print("Enter the total amount")
value = int(input())
print("Given the total amount is: ",value)
>>>>>>> 00d5b8a740755e635cb63b775555f018e63ac7dd

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

<<<<<<< HEAD

''' Sample input
  coins = [1,2,5,8,10]
  value = 24
=======
#Sample input
'''   coins = [1,2,5,8,10]
      value = 24
>>>>>>> 00d5b8a740755e635cb63b775555f018e63ac7dd
'''

min_coins = coinChange(coins,value,n)

# printing the min required coins
print("Minimum coins required are {}".format(min_coins))

    
