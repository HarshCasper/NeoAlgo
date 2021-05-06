'''
Descrption ->
            Given an array of distinct number enteries which are 
            arranged in ascending order.If the array is rotated 
            clockwise number of times. Then, calculate the total 
            number of rotations in the respective array.
'''

# program to find number of rotations in a sorted rotated array.

# PYTHON CODE:

def Total(listt, low, high):


    # When array in not rotated at all
    if high < low:
        return 0

    # When array has single element left
    if high == low: 
        return low 

    # calculating middle value 
    mid = low + (high - low)/2
    mid = int(mid)

    # checking minimum element
    if (mid < high and listt[mid+1] < listt[mid]):
        return mid+1

    # check if mid is middle element
    if (mid > low and list[mid] < listt[mid - 1]):
        return mid

    # Move either left or right
    if listt[high] > listt[mid]:
        return Total(listt, low, mid-1)

    return Total(listt, mid+1, high)


# main code

lst = list(map(int, input().strip().split()))
n = len(lst)


print(Total(lst, 0, n-1)) 
 


'''
Test Case 1:

            Input : lst = [4, 9, 11, 12, 5]
            Output : 4

Test Case 2:

            Input : lst = [7, 9, 11, 12, 15]
            Output : 0

Test Case 3:

            Input : lst = [15, 18, 2, 3, 6, 12]
            Output : 2

Time Complexity: O(log n)

Space Complexity: O(1)
'''
