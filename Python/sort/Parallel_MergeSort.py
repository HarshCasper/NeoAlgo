#!/usr/bin/env python3
""" Solution: Sort an array of random integers with merge sort using parallel approach."""

import random
import math
import multiprocessing as mp

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
        elif (left_temp_index < (mid - left + 1)): # copy any remaining on left side
            array[merge_index] = left_temp_arr[left_temp_index]
            left_temp_index += 1
        elif (right_temp_index < (right - mid)): # copy any remaining on right side
            array[merge_index] = right_temp_arr[right_temp_index]
            right_temp_index += 1
        merge_index += 1

""" parallel implementation of merge sort """
def par_mergesort(array, *args):
    if not args: # first call
        shared_array = mp.RawArray('i', array)
        par_mergesort(shared_array, 0, len(array)-1, 0)
        array[:] = shared_array # insert result into original array
        return array
    else:
        left, right, depth = args
        if (left < right):
            mid = (left + right) // 2
            left_proc = mp.Process(target=par_mergesort, args=(array, left, mid, depth+1))
            left_proc.start()
            par_mergesort(array, mid+1, right, depth+1)
            left_proc.join()
            merge(array, left, mid, right)

if __name__ == '__main__':
    NUM_EVAL_RUNS = 1

    userRange = int(input("Enter your range for generating random array: "))

    print('Generating Random Array...')
    array = [random.randint(0,10_000) for i in range(userRange)]

    strRandomArray = ','.join([str(i) for i in array])

    print('Random Array to Sort is : ' + strRandomArray)

    print('Evaluating Parallel Implementation...')
    parallel_result = par_mergesort(array.copy())
    parallel_time = 0
    for i in range(NUM_EVAL_RUNS):
        par_mergesort(array.copy())

    strfinalSortResult =','.join([str(i) for i in parallel_result])

    print('final sorted array is : '+ strfinalSortResult)