# Python program to find LCM of two numbers

# using euclid method to find gcd of two numbers


def euclidGCD(number1, number2):
    if number2 == 0:
        return number1
    return euclidGCD(number2, number1 % number2)

# Calculating lcm of two numbers using GCD


def lcm(number1, number2):
    return (number1 * number2) // euclidGCD(number1, number2)

number1, number2 = [int(x) for x in input().split()]
print(lcm(number1, number2))

'''
Sample I/O:

Sample 1:
Input:761457 614573
Output:467970912861

Sample 2:
Input:6 8
Output:24

Time Complexity :O(logn)
Space Complexity:O(1)
'''
