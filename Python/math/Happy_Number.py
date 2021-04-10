''' This code checks if a number is a happy number. A number is
    called happy if it becomes 1 after iterating thorugh a several
    number of steps wherein each step the number is replaced by the
    sum of its digits.'''


''' This function takes a number as input and returns
    sum of its digits.'''
def sum_square_digits(number):

    sum_squares = 0
    
    while(number):
        ''' Taking mod of number with 10 each time
            gives its units place digit. We add its
            square to the sum.'''
        sum_squares += (number % 10) ** 2;
        # Replace the number with number / 10.
        number = number // 10;
    
    return sum_squares

''' This function takes a number as input and checks
    if the number is a happy number. The idea behind
    the code is - we maintain two variables. The second
    variable is one step ahead of the first one. If
    the first variable becomes 1 so the second will be
    1 anyhow, because 1*1 = 1. So, we terminate the loop.'''
def is_happy_number(number):

    first = number
    second = number

    while(True):

        # The first variable calling sum of digits function once 
        first = sum_square_digits(first)

        # The second variable calling sum of digits function twice
        second = sum_square_digits(second)
        second = sum_square_digits(second)

        ''' If the first one equals the second, we break out of the
            loop. Otherwise, it will run into an infinite loop.'''
        if(first == second):
            break
        else:
            continue
    ''' The number is happy if at the end of iterations the number
        becomes 1. If it is one, then we return True.'''
    if(first == 1):
        return True
    else:
        return False

''' This function prints the sequence of steps, if the number
    indeed was a happy number.'''
def print_steps(number):

    display = 0
    # Iterate till we get 1
    while(display != 1):
        display = 0
        s = ""
        while(number):
            display += (number % 10) ** 2
            s += str(number % 10) + "^2 + "
            number = number // 10
        # Print each step till we get 1
        print(s[:len(s)-3], "=", display)
        number = display

# Driver function
if __name__=='__main__':

    # Taking input from the user
    number = int(input("Enter a number to check if it's a happy number or not: "))

    # Callinf the function to check if number is happy number
    check = is_happy_number(number)

    # If the function returns True, it means number is a happy number
    if(check == True):
        print("The number", number, "is a happy number. This is how: ")
        # We call this function to show us the steps that took place.
        print_steps(number)
    else:
        print("The number", number, "is not a happy number.")

'''
Sample I/O:
a)
    Enter a number to check if it's a happy number or not: 1221
    The number 1221 is a happy number. This is how:
    1^2 + 2^2 + 2^2 + 1^2 = 10
    0^2 + 1^2 = 1

b)
    Enter a number to check if it's a happy number or not: 145
    The number 145 is not a happy number.
'''

