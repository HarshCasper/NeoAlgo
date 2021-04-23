"""
Problem Statement :
Given a list of elements, return all possible subsets (the power set).

Description:
Power Set P(S) of a set S is the set of all subsets of S.
Power Set P(S) for a set S of <n> elements is 2^n elements.

Approach :
Iterate i from 0 to 2^n (as P(S) will have 2^n elements) and:
    • Find the binary equivalent of i.
    • Add the jth element from the array to the current subset when the jth
      bit of binary(i) is 1.
    • Add the subset to powerset list at end of each iteration.
"""


def binary(num, size):
    """
    num: int
    size: int

    Takes in a number and returns it's binary equivalent.
    Adds trailing zeroes at the beginning to make the
    length of binary equivalent equal to size.
    """
    binary_out = ''
    while num > 0:
        binary_out += str(num % 2)
        num //= 2
    binary_out += (size - len(binary_out)) * '0'
    return binary_out[::-1]


def subsets(nums):
    """
    nums: List[int] of unique elements
    Returns a list of all possible subsets
    """
    n = len(nums)
    powerset = []
    for i in range(2 ** n):
        binary_eq = binary(i, n)
        subset = []
        for j in range(n):
            if binary_eq[j] == '1':
                subset.append(nums[j])
        powerset.append(subset)
    return powerset


if __name__ == "__main__":
    list_of_values = input("Enter values seperated by space: ").split()
    print("Power Set:", subsets(list_of_values))

# Sample Input-Output:

# Sample Input 1:
# Enter values seperated by space: 1 2 3
# Sample Output 1:
# Power Set: [[], [3], [2], [2, 3], [1], [1, 3], [1, 2], [1, 2, 3]]

# Sample Input 2:
# Enter values seperated by space: 1 2 -1 0
# Sample Output 2:
# Power Set: [[], [0], [-1], [-1, 0], [2], [2, 0], [2, -1], [2, -1, 0],
# [1], [1, 0], [1, -1], [1, -1, 0], [1, 2], [1, 2, 0],
# [1, 2, -1], [1, 2, -1, 0]]

# Time Complexity: O(N * 2*N)
# Space Complexity: O(2*N)
