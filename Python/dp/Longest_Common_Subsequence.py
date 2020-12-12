# Importing sys module to initalize the maxsize
import sys
''' Longest Common Subsequence '''

'''Problem Statement :Given two sequences, find the length of
                      longest subsequence present in both of them.
                      Both the strings are of uppercase.
'''
# Assigning max value a variable can take
INT_MAX = sys.maxsize - 1
# Taking input of first string
print("Enter the first string:")
string_1 = input()
print("Enter the second string:")
string_2 = input()
# Calculate the sizes of the strings
x = len(string_1)
y = len(string_2)
# Constructing a table of size (x+1)*(y+1)
table = [[0 for i in range ( y + 1 )] for j in range ( x + 1 )]
# Memorization Apporach
# Longest Common Subsequence function
def  longestcommonsubsequence(string_1, string_2, x, y, table):
    for i in range(x + 1):
        for j in range(y + 1):
            if(i == 0 and j == 0):
                table[i][j] = 0
            # Check if the letters at the given positions of the
            # strings are equal add 1 to the previously existing
            # max of lcs
            elif(string_1[i - 1] == string_2[j - 1]):
                table[i][j] = table[i - 1][j - 1] + 1
            # If non of the given conditions are not fullfilled
            # then we will add the max previous of either table[i-1][j] or
            # table[i][j-1]
            else:
                table[i][j] = max(table[i - 1][j], table[i][j - 1])
    return(table[x][y])

max_seq = longestcommonsubsequence(string_1, string_2, x, y, table)

# Printing the max sequence
print("The longest common subsequence is {}".format(max_seq))
''' 
Sample input:
    String 1 : djjradc
    String 2 : jwrwadfc
Sample Output:
    The longest common subsequence is 5
'''