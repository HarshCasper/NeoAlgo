"""
Author: Akash Kumar Bhagat (akay_99)
Dice Throw Problem : Given n dice each with m faces, numbered
        from 1 to m, find the number of ways to get sum X.
        X is the summation of values on each face when all
        the dice are thrown.

Purpose: Return the number of ways you can get a sum equal to K
        by throwing a M faced dice for N times.

Method: Dynamic Programing
Intution:The Naive approach is to find all possible combinations from N dice
        and keep counting the if the desired sum is achieved
         Sum(m, n, X)=Finding Sum (X - 1) from (n - 1) dice plus 1 from nth dice
               + Finding Sum (X - 2) from (n - 1) dice plus 2 from nth dice
               + Finding Sum (X - 3) from (n - 1) dice plus 3 from nth dice
                  ...................................................
                  ...................................................
                  ...................................................
              + Finding Sum (X - m) from (n - 1) dice plus m from nth dice

        We can use Dynamic Programing to solve this problem efficiently because
        this problem contains many overlaping Sub-problems which need to be
        calculated again and again. We can use Dynamic Programing to store the
        result of the previous sub-problems.

Time Complexity: O(N*K)
Space Complexity: O(N*K)

Argument: 3 Integers (M, N and K)
Return  : Integer    (Number of ways)

Reference: https://www.geeksforgeeks.org/dice-throw-dp-30/

"""


def Dice_Throw(n, m, k):

    # DP table to store the results of all possible sub-problems in a matrix
    # Here DP[i][j] denoted the Number of ways to get the sum j with i throws
    DP = [[0] * (k + 1) for i in range(n + 1)]

    # By convention, the 0th index of the matrix will not be used and
    # the value at DP[0][0] must be 1
    DP[0][0] = 1

    # Iterate through 1 to n dice trows
    for i in range(1, n + 1):

        # For each dice thrown, re-calculate the number of ways to get the
        # target sum j from i throws
        for j in range(1, k + 1):

            DP[i][j] = DP[i][j - 1] + DP[i - 1][j - 1]

            if j - m - 1 >= 0:
                DP[i][j] -= DP[i - 1][j - m - 1]

    # Return the answer i.e. the last cell value of the DP table
    return DP[-1][-1]

# ------------------------------- DRIVER CODE ------------------------------


if __name__ == "__main__":

    # User input for the Number of dice, Number of faces and Target Sum
    n, m = map(
        int, input("Enter the Number of dice and number of faces: ").split())
    k = int(input("Enter the Target Sum: "))

    # we call the Dice_Throw() function with provided arguments to get the
    # answer
    ans = Dice_Throw(n, m, k)
    print("Total Number of Ways to get the target sum= ", ans)

"""

Sample Input / Output

Enter the Number of dice and number of faces: 1 6
Enter the Target Sum: 5
Total Number of Ways to get the target sum=  1

Explanation: (5)


Enter the Number of dice and number of faces: 2 6
Enter the Target Sum: 5
Total Number of Ways to get the target sum=  4

Explanation: (1, 4), (2, 3), (3, 2) and  (4, 1)


Enter the Number of dice and number of faces: 4 6
Enter the Target Sum: 5
Total Number of Ways to get the target sum=  4

Explanation: (1, 1, 1, 2), (1, 1, 2, 1), (1, 2, 1, 1) and (2, 1, 1, 1)
"""
