"""
A number is said to be a Harshad Number if it is divisible by the sum of its digits.
For example: The number 84 is divisible by the sum (12) of its digits (8, 4).

"""


def isHarshad(number) :
    copy = number

    # Calculating the sum of digits of the number
    sum_of_digits = 0
    while number != 0 :
        digit = number % 10
        sum_of_digits += digit
        number = number // 10

    # Checking if Number is divisible by sum of digits
    if copy % sum_of_digits == 0 :
        return True
    return False


user_input = int(input("Enter a number:"))

if isHarshad(user_input):
    print(user_input, "is a Harshad number")
else:
    print(user_input, "is not a Harshad number")

"""
Space Complexity O(1)
Time Complexity  O(log(n))

Sample input/output:
Enter a number:84
84 is a Harshad number

Enter a number:123
123 is not a Harshad number

"""
