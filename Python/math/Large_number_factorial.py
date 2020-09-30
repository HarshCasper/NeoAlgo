# Python Program to compute Large factorial numbers


def factorial_range(start, end):
    if start+1 < end:
        middle = start + ((end - start)//2)  # computing the mid element
        # recursive function to half the digits
        return factorial_range(start, middle) * factorial_range(middle+1, end)
    if start == end:
        return start
    return start*end


def factorialtree(n):  # function to divide the factorial in trees
    if n < 2:
        return 1
    return factorial_range(1, n)


# Driver Code
n = int(input())
print(factorialtree(n))

'''
Sample I/O:
input:
12
Output:
479001600
Time Complexity: O(logN)
Space Complexity: O(1)
'''
