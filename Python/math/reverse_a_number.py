"""
Python program to reverse a number.
The reverse of a number is a number that is obtained when a number is traversed from right to left.
"""

# Function to do reverse 

def reverse(n):
    # Initializing rev as 0

    rev = 0
    while True:
        if n == 0:
            break
        # Adding the last digit

        rev = rev * 10 + n % 10
        # Removing the last digit

        n = n // 10
    return rev

if __name__ == '__main__':
    # Taking input from user

    n = int(input('Enter the number :'))
    # Printing the output

    print ("The reverse of the given number is: {} ".format(reverse(n)))

"""
Time Complexity - O(n), where 'n' is the number of digits in the number.
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT
SAMPLE I

INPUT
Enter the number: 1234

OUTPUT
The reverse of the given number is: 4321

"""

