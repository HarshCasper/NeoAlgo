# Python program to find the subsequences Recursion


def Subsequence_recursion(string, index, current):
    if index == len(string):  # count the size
        print(current)  # print values one by one
        return
# calling function to update the values
    Subsequence_recursion(string, index + 1, current + string[index])
    Subsequence_recursion(string, index + 1, current)

string = input()
Subsequence_recursion(string, 0,  '')

'''
Sample I/O:
Input:
abc

Output:
abc
ab
ac
a
bc
b
c

Time Complexity:O(N) (where N =index)
Space Complexity:O(1)
'''
