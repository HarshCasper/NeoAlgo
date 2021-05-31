#!/usr/bin/env python3
""" Solution: Sort an array of random integers with merge sort using sequential way."""

import random

""" sequential implementation of merge sort """
def sequential_mergesort(array, *args):
    # first call
    if not args: 
        sequential_mergesort(array, 0, len(array)-1)
        # return the sorted array
        return array 
        # recursive call
    else: 
        left, right = args
        if (left < right):
            # find the middle point
            mid = left + ((right - left) // 2) 
            # sort the left half
            sequential_mergesort(array, left, mid) 
            # sort the right half
            sequential_mergesort(array, mid+1, right) 
            # merge the two sorted halves
            merge(array, left, mid, right) 

""" helper method to merge two sorted subarrays
    array[l..m] and array[m+1..r] into array """
def merge(array, left, mid, right):
    # copy data to temp subarrays to be merged
    left_temp_arr = array[left:mid+1].copy()
    right_temp_arr = array[mid+1:right+1].copy()
    # initial indexes for left, right and merged subarrays
    left_temp_index = 0
    right_temp_index = 0
    merge_index = left
    # merge temp arrays into original
    while (left_temp_index < (mid - left + 1) or right_temp_index < (right - mid)):
        if (left_temp_index < (mid - left + 1) and right_temp_index < (right - mid)):
            if (left_temp_arr[left_temp_index] <= right_temp_arr[right_temp_index]):
                array[merge_index] = left_temp_arr[left_temp_index]
                left_temp_index += 1
            else:
                array[merge_index] = right_temp_arr[right_temp_index]
                right_temp_index += 1
                # copy any remaining on left side
        elif (left_temp_index < (mid - left + 1)): 
            array[merge_index] = left_temp_arr[left_temp_index]
            left_temp_index += 1
            # copy any remaining on right side
        elif (right_temp_index < (right - mid)): 
            array[merge_index] = right_temp_arr[right_temp_index]
            right_temp_index += 1
        merge_index += 1

if __name__ == '__main__':
    NUM_EVAL_RUNS = 1
    userRange = int(input("Enter your range for generating random array: ")) 
    print('Generating Random Array... ')
    array = [random.randint(0,1000) for i in range(userRange)]
    strRandomArray = ','.join([str(i) for i in array])
    print('Random Array to Sort is : ' + strRandomArray)
    print('Evaluating Sequential Implementation...')
    sequential_result = sequential_mergesort(array.copy())
    for i in range(NUM_EVAL_RUNS):
        sequential_mergesort(array.copy())
    strfinalSortResult =','.join([str(i) for i in sequential_result])
    print('final sorted array is : '+ strfinalSortResult)

'''
 input/output sample
 Enter your range for generating random array: 10
 Generating Random Array...
 Random Array to Sort is : 1807,7508,7166,7673,2000,1356,7665,4670,9395,6002
 Evaluating Parallel Implementation...
 final sorted array is : 1356,1807,2000,4670,6002,7166,7508,7665,7673,9395
 Time Complexity: O(nLog(n)) in worst case
Space Complexity: O(n) in worst case
    
'''

