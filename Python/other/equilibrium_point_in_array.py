#!/usr/bin/env python
# coding: utf-8

# In[7]:


'''
Given an array of n positive integers, find the first equilibrium point in the array.
Equilibrium Point in an array is a position at which sum of elements before it is equal 
to the sum of elements after it.

'''

def findEquilibriumPoint(arr, n):
    
    '''
    Returns equilibrium point if exists,
    -1 otherwise.
    
    '''
    #initialize sum of elements to the left to zero
    lsum = 0
    #initialize sum of elements to the right to sum of all the elements in the array
    rsum = sum(arr)
    #loop through elements in the array
    for i in range(n):
        #subtract element at ith position from rsum
        rsum -= arr[i]
        #check if left sum equals right sum, if true return the position,
        #otherwise add element at ith position to lsum
        if lsum == rsum:
            return i+1
        else:
            lsum += arr[i]
    return -1


if __name__ == "__main__":
    arr = [int(x) for x in input("Enter elements of the array: ").split()]
    n = len(arr)
    equi_point = findEquilibriumPoint(arr,n) 
    if equi_point == -1:
        print("Equilibrium point does not exist.")
    else:
        print(f"Position {equi_point} is the equilibrium point. ")
        
        
"""

Time complexity: O(n)
Space complexity: O(n)

Test case 1
Input:
Enter elements of the array: 1 2 3 4 5
Output:
Equilibrium point does not exist.

Test case 2
Input:
Enter elements of the array: 3 2 4 1 4
Output:
Position 3 is the equilibrium point.

"""

