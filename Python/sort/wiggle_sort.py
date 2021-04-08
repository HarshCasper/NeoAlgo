"""  
    WIGGLE SORT
    This program accepts an array of unsorted numbers and
    sorts the array such that arr[0]<arr[1]>arr[2]<arr[3]...
    
"""

# to wiggle sort the array
def wiggle_sort(n, arr):

    # arr is sorted and stored in second array res

    res = sorted(arr)
    left = (n - 1) // 2
    right = n - 1

    # Elements in the left sub-array  are added to the even indices of arr
    # Elements in the right sub-array are added to the odd indices of arr

    for k in range(0, n, 2):
        arr[k] = res[left]
        left -= 1
    for i in range(1, n, 2):
        arr[i] = res[right]
        right -= 1
    print ('Wiggle sorted array:')
    print (arr)


# driver code

if __name__ == '__main__':
    arr = list(map(int, input('Enter the array: ').split()))
    no_of_elements = len(arr)
    wiggle_sort(no_of_elements, arr)

'''   
Sample output           
Enter the array: 1 3 2 2 3 1
Wiggle sorted array:
[2,3,1,3,1,2]

Complexities
Time Complexity : O(nlogn)   (Sorting takes O(n logn) and traversal takes O(n))
Space Complexity : O(n)   (New array to store the wiggle sorted elements)
'''

