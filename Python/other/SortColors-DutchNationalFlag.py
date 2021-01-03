             
# PROBLEM STATEMENT- https://leetcode.com/problems/sort-colors/

# Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
# Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
# In simpler words sort an array containing 0,1,2.

# Solve the problem with a one-pass algorithm using only O(1) constant space?

# The bruteforce approach - Sort the vector in nlogn time

#                                 ************************DUTCH_NATIONAL_FLAG ALGORITHM***********************************



# Python program to sort an array with 0, 1 and 2 in a single pass using DUTCH NATIONAL FLAG ALGORITHM


# Function to sort array 
def dnf_algo( a, arr_size): 

    low = 0 
    high = arr_size - 1
    mid = 0
    while mid <= high: 
        if a[mid] == 0: 
            a[low], a[mid] = a[mid], a[low] 
            low = low + 1
            mid = mid + 1
        elif a[mid] == 1: 
            mid = mid + 1
        else: 
            a[mid], a[high] = a[high], a[mid]  
            high = high - 1
    return a 
      
    
array = list(map(int,input().split()))  # taking all the values in one line and mapping into list

arr_size = len(array)  # finding length of list

array = dnf_algo(array, arr_size) 

print("Array after applying Dutch National Flag Algo :")

# printing the final resultant array
for i in array: 
    print(i,end=" ")    # end= " " is used to print all elements in one line

