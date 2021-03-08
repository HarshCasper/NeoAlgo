"""
Problem Statement : Given an array arr of N integers.
                    Find the contiguous sub-array with maximum sum
                    
Method            : Kadane's Algorithm, Dynamic Programming.

Time Complexity: O(N)
Auxiliary Space: O(1)

"""

def maximumSum(arr,size):
    max=int(arr[0])

    # intialize highest with first array element
    sum=int(arr[0])

    for i in range(1,size):
        max = max if max>arr[i]+max else arr[i]+max
        sum = sum if sum>max else max

    #returning the highest sum among all
    return sum

# user defined array size: N
N = int(input("Enter size of array: "))

# array elements
arr = list(map(int,input().split()))

# call to the function and printing the maximum sum
print("Maximum contiguous subarray sum: ",maximumSum(arr,size))


"""
Sample Input:   N = 5
                arr[] = {1,2,3,-2,5}

Sample Output:
                9
Explanation:
                Max subarray sum is 9
                of elements (1, 2, 3, -2, 5) which 
                is a contiguous subarray.        
"""