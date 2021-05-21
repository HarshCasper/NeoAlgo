"""Python program to implement Minimum XOR value.
Given an array of integers, we have to find the minimum XOR value, a pair in the array makes."""

import sys

def minimumXOR(arr, n):
    # Sort the array, so that elements with minimum bit difference are present consecutive.
    arr.sort()
    minXOR = sys.maxsize
    val = 0

    # Compute the XOR values of the consecutive elements of the array.
    for i in range(0, n-1):
        val = arr[i] ^ arr[i+1]
        minXOR = min(minXOR, val)

    return minXOR


if __name__ == '__main__':
    print("How many numbers are present in the array? ", end="")
    n = int(input())
    if (n <= 0):
        print("No numbers are present in the array!!!")
        exit()
    print("Enter the numbers: ", end="")
    arr = [int(x) for x in input().split(' ')]
    res = minimumXOR(arr, n)
    print("The minimum XOR value present in the given array is {}".format(res))


"""
SAMPLE INPUT AND OUTPUT

SAMPLE I

How many numbers are present in the array? 8
Enter the numbers: 25 45 36 458 651 89 52 95 
The minimum XOR value present in the given array is 9

SAMPLE II

How many numbers are present in the array? 5
Enter the numbers: 5 4 3 2 1
The minimum XOR value present in the given array is 1

"""
