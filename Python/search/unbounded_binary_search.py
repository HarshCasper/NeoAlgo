"""
code for unbounded_binary_search Algorithm:
    Given a function ‘int f(unsigned int x)’ which takes a non-negative integer ‘x’
    as input and returns an integer as output. The function is monotonically increasing
    with respect to value of x, i.e., the value of f(x+1) is greater than f(x) for
    every input x. Find the value ‘n’ where f() becomes positive for the first time.
    Since f() is monotonically increasing, values of f(n+1), f(n+2),…
    must be positive and values of f(n-2), f(n-3), .. must be negative.
"""


def fun(x):
    if sign_b == '+':
        if sign_c == '+':
            return a * x * x + b * x + c
        else:
            return a * x * x + b * x - c

    else:
        if sign_c == '+':
            return a * x * x - b * x + c
        else:
            return a * x * x - b * x - c


def findFirstPositive():
    # if first value itself is positive
    if fun(0) > 0:
        return 0

    # to get 'high_index' for binary search
    i = 1
    while fun(i) <= 0:
        i = i * 2

    # Call binary search
    return binarySearch(i // 2, i)


def binarySearch(low_index, high_index):

    if high_index >= low_index:
        midPoint = low_index + (high_index - low_index) // 2

        if fun(midPoint) > 0 and (midPoint == low_index or fun(midPoint - 1) <= 0):
            return midPoint

        if fun(midPoint) <= 0:
            return binarySearch((midPoint + 1), high_index)

        else:
            return binarySearch(low_index, (midPoint - 1))

    # Return None if there is no positive value in given range
    return None


# the main code
# take the input from user : a, b, c of the equation and signs of b & c
a, b, c = map(int, input("please enter three parameters of the equation in order a, b, c : ").split())
sign_b, sign_c = input("please enter the signs of the equation + or - in order sign_b, sign_c : ").split()

# calculate the output
out = findFirstPositive()

# print output
print("The value n where fun(x) becomes " +
      "positive first is : ", out)


"""
Example 1: x*x + 5 - 10

please enter three parameters of the equation in order a, b, c : 1 5 10
please enter the signs of the equation + or - in order sign_b, sign_c : + -
The value n where fun(x) becomes positive first is :  2

Example 2: 2*x*x - 10 - 20

please enter three parameters of the equation in order a, b, c : 2 10 20 
please enter the signs of the equation + or - in order sign_b, sign_c : - - 
The value n where fun(x) becomes positive first is :  7

Time Complexity : O(log n)
Space Complexity : O(1)
"""

