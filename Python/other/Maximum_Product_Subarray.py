'''
Given an array Arr that contains N integers (may be positive, negative or zero).
Find the product of the maximum product subarray.

Example 1:

Input:{6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is  6, -3, -10 which gives product as 180.
Example 2:

Input:{2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is 2, 3, 4, 5 which gives product as 120.

'''
def maximum_product_subarray(arr):
    arr2 = arr[::-1]
    for i in range(1, len(arr)):
        arr[i] *= arr[i - 1] or 1
        arr2[i] *= arr2[i - 1] or 1
    return max(arr + arr2)

if __name__ == "__main__":
    arr = list(map(int,input("Enter the number: ").split()))
    print("Maximum Subarray product is ",maximum_product_subarray(arr))

'''
Time complexcity  = O(n)
space complexcity = O(1)

INPUT 
Enter the Number: 6 -3 -10 0 2

OUTPUT
Maximum Subarray product is 180
'''
