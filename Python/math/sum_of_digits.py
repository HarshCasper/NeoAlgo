# Python program to Find the Sum of Digits of a Number

# Extracting Each digits
def sum_of_digits(num):
    sum = 0
    while(num != 0):
        sum = sum + (num % 10)
        num = num // 10
    return sum


print("Enter the number: ", end="")
num = int(input())
sum = sum_of_digits(abs(num))
print("The sum of digits of the given number is {}.".format(sum))

"""
Time Complexity: O(log(num)), where 'num' is the length of the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number: -12
The sum of digits of the given number is 3.

SAMPLE 2

Enter the number: 43258
The sum of digits of the given number is 22.
"""
