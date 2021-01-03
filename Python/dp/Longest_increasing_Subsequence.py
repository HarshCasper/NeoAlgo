# Importing sys module to initalize the maxsize
import sys
''' Longest Increasing Subsequence '''

'''Problem Statement :Given an array of integers,
                      find the length of the
                      longest (strictly) increasing subsequence
                      from the given array.
'''
# Assigning max value a variable can take
INT_MAX = sys.maxsize - 1
# Taking input of first string
print("Enter the list of integers:")
int_list = list(map(int, input().rstrip().rsplit()))
# Calculate the sizes of the list
n = len(int_list)
# Constructing a table of size (x+1)*(y+1). Initialize all the
# value with 1 since the min length has to be 1.
table = [1]*n
# Memorization Apporach
# Longest Increasing Subsequence function


def longestincreasingsubsequence(int_list, n, table):
    for i in range(1, n):
        for j in range(0, i):
            # Check if the element in the give position
            # is larger then the one in the previous position or not
            if int_list[i] > int_list[j] and table[i] < table[j] + 1:
                table[i] = table[j] + 1
    return(max(table))
max_len = longestincreasingsubsequence(int_list, n, table)
print("The longest increasing subsequence is {}".format(max_len))
''' 
Sample input:
    Int List = 10, 22, 9, 33, 21, 50, 41, 60
Sample Output:
    The longest increasing subsequence is 5
'''

