''' How to determine if a number is a Magic number.
    We calculate the sum of digits of the number till
    we get a single digit, recursively. If the single
    digit comes out to be 1, then we say that the number
    is a magic number. '''

# This function checks if a number is a magic number.
def is_Magic_number(number):
    
    sum_digits = 0
    ''' We loop till the number is greater than 0 or we
    get a single digit sum of the digits of the number.'''
    while(number > 0 or sum_digits > 9):

        # This is the iterating step.
        if(number == 0):
            ''' We replace the number by the sum of its
            digits. And set the sum to zero.'''
            number = sum_digits
            sum_digits = 0

        else:
            # We find the sum of the digits of number
            sum_digits += number % 10
            number = number // 10

    ''' After we get a single digit sum, we check if
    it 1, then it is a magic number and we return True.'''
    if(sum_digits == 1):
        return True

    # Else we return False
    else:
        return False

''' Below two function print the steps if the number
    indeed is a magic number.'''
def sum_return(number):
    sum_number = 0
    # The output is stored in a string
    s = ""
    while(number):
        s += str(number % 10) + " + "
        sum_number += number % 10
        number = number // 10

    ''' After every iteration, we print the number
        and return the sum of the digits.'''
    print((s[:len(s) - 3])[::-1], "=", sum_number)
    return sum_number

def print_steps(number):
    sum_digits = 0
    while(number != 1):
        # Call the above function till number becomes 1
        number = sum_return(number)

# Drivers function
if __name__=='__main__':

    # Take input from the user
    number = int(input("Enter a number to check if it's a magic number: "))

    # Call the magic number function
    if(is_Magic_number(number)):
        print("The number", number, "is a magic number.", end = " ")
        # Print the steps
        print("This is the following steps.")
        print_steps(number)

    else:
        print("The number", number, "is not a magic number.")

'''
Sample I/O:

a)  Enter a number to check if it's a magic number: 112222
    The number 112222 is a magic number. This is the following steps.
    1 + 1 + 2 + 2 + 2 + 2 = 10
    1 + 0 = 1

b)  Enter a number to check if it's a magic number: 123
    The number 123 is not a magic number.
'''

