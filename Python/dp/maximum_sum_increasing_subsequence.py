"""
Python program to implement Maximum Sum Increasing Subsequence
In this problem, given an array we have to find the maximum sum an increasing subsequence of that array can make.
This problem is a slight modification to the Longest Increasing subsequence problem.
The problem can be solved using Dynamic Programming
"""


def maximum_sum_increasing_subsequence(arr, n):
    max_sum = 0
    dp = [0 for i in range(n)]

   # Initialize the dp array with the array values, as the maximum sum
   # at each point is atleast as the value at that point
    for i in range(n):
        dp[i] = arr[i]

    for i in range(1, n):
        for j in range(i):
            if(arr[i] > arr[j] and dp[i] < dp[j] + arr[i]):
                dp[i] = dp[j] + arr[i]

    # Now Find the maximum element in the dp array
    max_sum = max(dp)
    return max_sum


if __name__ == '__main__':
    print("What is the length of the array? ", end="")
    n = int(input())
    if (n <= 0):
        print("No numbers present in the array!!!")
        exit()
    print("Enter the numbers: ", end="")
    arr = [int(x) for x in input().split(' ')]
    res = maximum_sum_increasing_subsequence(arr, n)
    print("The maximum sum of an  increasing subsequence of the given array is {}".format(res))


"""
Time Complexity: O(num ^ 2), where 'num' is the size of the given array
Space Complexity: O(num)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

What is the length of the array? 10
Enter the numbers: 23 14 5 84 24 222 321 43 123 432 
The maximum sum of an increasing subsequence of the given array is 1082

SAMPLE 2

What is the length of the array? 5
Enter the numbers: 5 4 3 2 1
The maximum sum of an increasing subsequence of the given array is 5
"""
