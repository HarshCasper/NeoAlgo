#!/bin/python3

import math
import os
import random
import re
import sys

first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])
m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)

# start   
matrix = list(zip(*matrix))

sample = str()

for words in matrix:
    for char in words:
        sample += char
       
print(re.sub(r'(?<=\w)([^\w\d]+)(?=\w)', ' ', sample)) 
