# You are given a positive integer N which represents the number of steps in a staircase. 
# You can either climb 1 or 2 steps at a time. Write a function that returns the number of unique ways to climb the stairs.
'''
Input: n = 4
Output: 5
(1, 1, 1, 1), (1, 1, 2), (2, 1, 1), (1, 2, 1), (2, 2)

Input: n = 5
Output: 8
(1, 1, 1, 1, 1), (2, 1, 1, 1), (1, 2, 1, 1), (1, 1, 2, 1), (1, 1, 1, 2), (2, 2, 1), (2, 1, 2), (1, 2, 2)
'''
# Time Complexity - O(n^2)
# Space Complexion - O(1)
def staircase(n: int) -> int:
  if n <= 3:
    return n
  return staircase(n-1)+staircase(n-2)


# Time Complexity -  O(n) 
# Space Complexion -  O(n)
def staircase(n: int) -> int:
  res = [0]*(n+1)
  res[0] = 1
  res[1] = 1
  for i in range(2,n+1):
    res[i] = res[i-1]+res[i-2]
  return res[n]

print(staircase(4))
# output - 5
print(staircase(5))
# output - 8
