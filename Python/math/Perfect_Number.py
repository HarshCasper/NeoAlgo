''' This program written in Python checks if a number is a perfect
number. A perfect number is a number which is equal to the sum of
its divisors (excluding the number itself).'''

# This function checks if a number is a perfect number
def is_perfect(n):

    # This variable stores the sum of divisors of number
    sum_of_divisors = 0
    # Iterate from 1 till the number
    for i in range(1, n):
        if(n % i == 0):
            # Add divisors
            sum_of_divisors += i

    # If the sum of divisors is equal to the number
    if(sum_of_divisors == n):
        return 1

    # Else return -1
    return -1

if __name__ == '__main__':

    # Take number as input from the user
    number = int(input("Enter a number to check if it's a perfect number: "))

    # If the number is non-positive, exit
    if(number <= 0):
        print("\nPlease enter a positive number.")
    else:
        # Call the function
        result = is_perfect(number)

        # If the result is 1, the number is a perfect number
        if(result != -1):
            print("\nThe number " + str(number) + " is a perfect number.")
        else:
            # Else it is not
            print("\nThe number " + str(number) + " is not a perfect number.")

'''
Sample I/O:

1)
Enter a number to check if it's a perfect number: 28

The number 28 is a perfect number.

2)
Enter a number to check if it's a perfect number: -16

Please enter a positive number.

Time Complexity - O(n)
Space Complexity - O(1)

'''

