'''
Task is to find the largest dimension of a square submatrix 
such that all elements of submatrix are one using Dynamic Programming
'''

def largestSubmatrix(M, row, col):
  S = [[None]*col]*row
  for i in range(row):
    S[i][0] = M[i][0]
  for j in range(col):
    S[0][j] = M[0][j]
  max_val = 0
  for i in range(row):
    for j in range(col):
      if M[i][j] == 1:
        S[i][j] = min([S[i][j-1], S[i-1][j], S[i-1][j-1])
        if s[i][j] > max_val: max_val = s[i][j]
      else:
        S[i][j] = 0
  return max_val
  
row = int(input("Enter number of rows: "))
col = int(input("Enter number of columns: "))

matrix = []
print(f"In next {row} rows, Enter {col} elements separated by spaces for each row")
for i in range(row):
  r = list(map(int, input().split()))
  
  if len(r) < col: r = r + [0]*(col-len(r))
  elif len(r) > col: r = r[:col]
  
  matrix.append(r)
 
print(largestSubmatrix(matrix, row, col)) 
