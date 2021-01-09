# Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
# Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
# In simpler words sort an array containing 0,1,2.
# Solve the problem with a one-pass algorithm using only O(1) constant space?
# The bruteforce approach - Sort the vector in nlogn time

# PROBLEM STATEMENT- https://leetcode.com/problems/sort-colors/

#                                 ************************DUTCH_NATIONAL_FLAG ALGORITHM***********************************

# Python program to sort an array with 0, 1 and 2 in a single pass using DUTCH NATIONAL FLAG ALGORITHM

# Function to sort array 
def dnf_algo( array, len): 
    low = 0 
    high = len - 1
    mid = 0
    while mid <= high:        
        if array[mid] == 0: 
            array[low], array[mid] = array[mid], array[low] 
            low = low + 1
            mid = mid + 1
        elif array[mid] == 1: 
            mid = mid + 1
        else: 
            array[mid], array[high] = array[high], array[mid]  
            high = high - 1
    return array 

if __name__ == "__main__":
    
    # Now by taking all the values in one line and mapping into list    
    array = list(map(int,input().split()))  

    # finding length of list
    arr_size = len(array) 
    array = dnf_algo(array, arr_size) 
    print("Array after applying Dutch National Flag Algo :")

    # printing the final resultant array
    print(*array)   

# ------------------------------------------ TEST CASES -------------------------------------
# Sample I/P 1:
# 2 0 1

# Sample O/P 1:
# Array after applying Dutch National Flag Algo : 0 1 2

#--------------------------------------------------------------------------------------------

# Sample I/P 2:
# 2 0 2 1 1 0

# Sample O/P 2:
# Array after applying Dutch National Flag Algo : 0 0 1 1 2 2

#--------------------------------------------------------------------------------------------

# COMPLEXITY ANALYSIS-
#       Time = O(N)
#       Space = O(1)
