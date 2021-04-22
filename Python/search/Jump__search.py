"""
Python code to implement Jump Search.
Jump Search is a searching algorithm for sorted arrays.
The basic idea is to check fewer elements by jumping ahead by fixed
steps instead of checking the whole array.
"""
import math
def jump_search(arr, key):
    """
    :param arr: Our array
    :param key: Element we are searching on
    :return: The index of the key if it there, if it
    return -1 then the key is not in the array
    """
    n = len(arr)
    # Step length
    jump = math.sqrt(n)
    key_index = 0
    # Find the block where the key belong
    while arr[int(min(jump,n))-1] < key:
        key_index = jump
        jump = jump + math.sqrt(n)
        if key_index >= n:
            return -1
    # Searching linearly in the block that begin with key_index
    while arr[int(key_index)] < key:
        key_index = key_index + 1
        # Making sure that we didn't reach the end of the block
        # or the end of array
        if key_index >= n:
            return -1
    # Finding the element
    if arr[int(key_index)] == key:
        return int(key_index)
    return -1
# Take array from user
arr = list(map(int,input("\nEnter the array : ").split()))
# Take the key element from the user
key = int(input("\nEnter a number to search : "))
# Start searching on the Key
index = jump_search(arr,key)
# Print the index of the Key if it there
if index == -1 :
    print("\nThis number is not in the array")
else:
    print("\nThe number {} is in the index {} of the array".format(key,index))

"""
Sample of input/output:
Example 1:
""""""""
Input: Enter the array : 1 2 3 4 5 6
Enter a number to search : 5
Output: The number 5 is in the index 4 of the array
""""""
Space Complexity O(1)
Time Complexity  O(√n)
"""
