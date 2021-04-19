"""
Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it can trap after raining.
"""

# function to find the water trapped
def trap(arr, n):
    if n < 3:
        return 0

    # initialize the values
    water, i, j = 0, 1, n-2
    left = arr[0]
    right = arr[n-1]

    while i <= j:

        # fill left
        if left <= right:
            left = max(left, arr[i])
            water += left - arr[i]
            i += 1

        # fill right
        else:
            right = max(right, arr[j])
            water += right - arr[j]
            j -= 1

    # return result
    return water
    
# Driver's code
if __name__ == "__main__":
    # creating an empty lists
    arr = []
    n = int(input('Enter length of array: '))
    arr = list(map(int,input("\nEnter elements of array: ").strip().split()))[:n]

    print('Water trapped is is: ' +
        str(trap(arr, n)))

"""
Time Complexity: O(n)
Space Complexity: O(n)

Example 1:

Input:
Enter number of elements: 
12
Enter the elements: 
0 1 0 2 1 0 1 3 2 1 2 1

Output:
Water it can trap is: 6

"""
