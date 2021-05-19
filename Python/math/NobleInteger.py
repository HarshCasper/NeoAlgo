''' 
Problem Statement ->>

An integer x is said to be Noble given an array if the number of integers greater 
than x are equal to x.
If noble integer is not found output will be -1. 
'''

# Python Code :
# Function to check the array

def Check(Arr , num):
    x = 0
    Arr.sort()
    # list traversing
    for i in range(0, num - 1):
        if Arr[i] == Arr[i + 1]:
            continue

        if Arr[i] == num - i - 1:
            x = 1
            return num - i - 1

    if x == 0:
        # Noble Integer not found
        return -1

# main code ->>

num = int(input())
Arr = list(map(int, input().split()))
Integer = Check(lst, number)

if Integer==-1:
    print("Noble Integer not present")
else:
    print("Noble Integer =",Integer)

'''
Test Case 1:
Input: n= 4
       Arr= { 7 3 9 81 }

Output: Noble Integer = 3

Test Case 2:
Input: n= 3
       Arr= { 2 2 2 }

Output: Noble Integer = -1
'''
        
