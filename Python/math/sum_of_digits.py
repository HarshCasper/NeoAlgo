# Python program to Find the Sum of Digits of a Number


def sum_of_digits(num):
    # Extracting Each digits
    # and compute thier sum in 's'
    s = 0
    while num != 0:
        s = s + (num % 10)
        num = num // 10
    return s


if __name__ == '__main__':
    # Input the number And
    # Call the function
    print("Enter the number: ", end="")
    n = int(input())
    S = sum_of_digits(abs(n))
    print("The sum of digits of the given number is {}.".format(S))
    
'''    
Time Complexity: O(log(num)), where "num" is the length of the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number: -12
The sum of digits of the given number is 3.

SAMPLE 2

Enter the number: 43258
The sum of digits of the given number is 22.
'''
