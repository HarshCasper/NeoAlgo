'''
Author : @anushkrishnav
Problem : https://www.hackerrank.com/challenges/circular-array-rotation/problem
'''
import sys


N, K, Q = list(map(int, sys.stdin.readline().split()))
A = list(map(int, sys.stdin.readline().split()))
   
for _ in range(Q):
  x = int(sys.stdin.readline())
  print(A[(x - K) % N])
