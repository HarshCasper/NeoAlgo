"""
Python program to check if the number is Neon number or not.
We can Say that the number is Neon number if its sum of digits
of square is equal to the number.

"""
def Neon_number(number) :
    # Calculating the square of the number
    square_number = pow(number,2)
    # Calculating the sum of digits of the square of the number
    sum_of_digits = 0
    while square_number != 0 :
        digit = square_number % 10
        sum_of_digits += digit
        square_number = square_number // 10
    if sum_of_digits == number :
        print(number,"is a Neon number")
    else :
        print(number,"is not a Neon number")

number = int(input("Enter a number:"))
Neon_number(number)

"""
Sample of input/output:

Example 1:
Input:
Enter a Number: 9
Output:
9 is a Neon number

Example 2:
Input:
Enter Number: 5
Output:
5 is not a Neon number

Example 3:
Input:
Enter a Number: 0
Output:
0 is a Neon number

Space Complexity O(1)
Time Complexity  O(log(n))
"""

