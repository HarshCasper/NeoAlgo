'''
Problem statement:
https://www.hackerrank.com/challenges/matrix-script/problem

Topic: Regex and Parsing

Purpose:
The command re.compile will compile a regular expression pattern into a regular
expression object, which can be used for matching using its match(), search()
and other methods. This is a regular expression that has been compiled for
faster reuse. Regarding the specific regex expression, this searches for groups
that have alphanumerics (that's the \w part) or apostrophes (which is also in
those square brackets) that are 1 or longer. Note that whitespace is not a
match, so this, generally speaking, breaks a line into words.

Time Complexity: O(n^2)
Space Complexity: O(n)
'''

import math
import os
import random
import re
import sys
# taking multiple integer inputs on a single line
first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)
string = ""
for y in range(m):
    for x in range(n):
        string += matrix[x][y]
# for pattern matching & helps to search a pattern again without rewriting it
# \w for word character and \W for non-word character
pattern = re.compile('(\w)(\W)+(\w)')
# prefix r for raw string which ignores escape and \1 is a backreference
# \3 is for backreference to 3rd parenthesized subexpression
subs = pattern.sub(r"\1 \3", string)
print(subs)

'''
Sample Input:
7 3
Tsi
h%x
i #
sM
$a
#t%
ir!

Sample Output:
This is Matrix#  %!

Explanation:

The decoded script is:
This$#is% Matrix#  %!
It replaces the symbols or spaces between two alphanumeric characters with a
single space ' ' for better readability.
So, the final decoded script is:
This is Matrix#  %!
'''
