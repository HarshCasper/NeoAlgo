"""
Given a function ‘int f(unsigned int x)’ which takes a non-negative integer ‘x’
as input and returns an integer as output. The function is monotonically increasing
with respect to value of x, i.e., the value of f(x+1) is greater than f(x) for
every input x. Find the value ‘n’ where f() becomes positive for the first time.
Since f() is monotonically increasing, values of f(n+1), f(n+2),…
must be positive and values of f(n-2), f(n-3), .. must be negative.

Time Complexity : O(log n)
"""

# an example of a function
# fun(x) = x^2 + 5x - 10


def fun(x):
    return x*x + 5*x - 10


def findFirstPositive():
    # if first value itself is positive
    if fun(0) > 0:
        return 0

    # to get 'high index' for binary search
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

        elif fun(midPoint) <= 0:
            return binarySearch((midPoint + 1), high_index)

        else:
            return binarySearch(low_index, (midPoint - 1))

    # Return None if there is no positive value in given range
    return None


"""
Driver Code : Example
print("The value n where fun(x) becomes " +
      "positive first is : ", findFirstPositive())
Input : x^2 + 5x - 10
Output : The value n where function() becomes positive first is 2
"""
