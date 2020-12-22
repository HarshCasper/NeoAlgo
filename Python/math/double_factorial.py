# Double Factorial.


def double_fact_i(n):   # iterative implementation
    ans = 1
    for i in range(n, 1, -2):
        ans *= i
    return ans


def double_fact_r(n):          # recursive implementation
    if n == 0 or n == 1:       # checking for 1 or 0
        return 1
    return n * double_fact_r(n - 2)


if __name__ == "__main__":
    n = int(input("Enter number: "))
    print(f"Answer using Iterative method: {double_fact_i(n)}")
    print(f"Answer using recursive method: {double_fact_r(n)}")

'''
output:
enter number4
Answer using Iterative method: 8
Answer using recursive method: 8
enter number5
Answer using Iterative method: 15
Answer using recursive method: 15
Time complexity : O(n) '''
