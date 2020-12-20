"""
Purpose: To determine whether a given array of numbers can be divided
        into to sets of equal sum or not.
        Example: 6 3 11 2
        Output:  Yes ((6,3,2) and (11))

Method: Dynamic Programing
Intution: The problem can be solved using dynamic programming when the
        sum of the elements is not too big. We can create a 2D array part[][]
        of size (sum/2 + 1)*(n+1).And we can construct the solution in a
        bottom-up manner such that every filled entry has the following property.

        DP[i][j] = True if a subset of {arr[0], arr[1], ..arr[j-1]} has sum
             equal to i, otherwise false
Reference: https://www.geeksforgeeks.org/partition-problem-dp-18/

Time Complecity:  O(sum * N)
Space Complexity: O(sum * N)

Argument: List
Return  : Boolean

"""


def Partition_Problem(n, arr):

    # Calculate the sum of the each element in the array
    s = sum(arr)

    # Base Case: if the sum is odd, return false
    if s % 2:
        return False

    DP = [[True] * (n + 1) for j in range(s // 2 + 1)]

    # Initilize the leftmost col to False
    for i in range(1, s // 2 + 1):
        DP[i][0] = True

    # Construct the DP table
    for row in range(1, s // 2 + 1):

        for col in range(1, n + 1):
            DP[row][col] = DP[row][col - 1]

            if row >= arr[col - 1]:
                DP[row][col] = DP[row][col] or DP[row - 1][col - 1]

    # Return the last element of the table
    return DP[-1][-1]


# ------------------------DRIVER CODE ------------------------

if __name__ == "__main__":

    # Input the array form the user
    a = list(map(int, input("Enter the array elements: ").split()))
    n = len(a)

    ans = Partition_Problem(n, a)

    if ans:
        print("Yes")
    else:
        print("No")

"""

Sample Input / Output

Enter the array elements: 6 3 11 2
Yes


Enter the array elements: 1 3 4 14 6
Yes


Enter the array elements: 1 2 3 4 5 6
No

Enter the array elements: 10 6 7 4 2 9 5
No

"""
