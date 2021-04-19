''' This program calculates nth Catalan number using Dynamic programming.
The solutions to the nth Catalan number is calculated in bottom-up manner.
There by reducing the time complexity.'''

# This function returns nth catalan number
def n_catalan(number):

    # Makes an array to store the catalan numbers
    array = [0] * (number + 1)

    # Base cases
    array[0] = 1
    if(number == 0):
        return array[0]
    array[1] = 1

    # Using DP recursive solution to get nth catalan number
    for i in range(2, number + 1):
        for j in range(0, i):
            array[i] += array[j] * array[i - j - 1]

    # Return the nth catalan number
    return array[number]


## Drivers code
if __name__=="__main__":
    
    ##Take number as input from the user
    number = int(input("Enter a number: "))

    ## Check if the number is non-negative.
    if(number < 0):
        print("\nPlease enter a non-negative number.")
        exit()

    ## Call the function
    catalan = n_catalan(number)
    ## Print the nth catalan number
    print("\nCatalan number at index " + str(number) + " is " + str(catalan))

''' 
Sample I/O:

1)
Enter a number: 10

Catalan number at index 10 is 16796

2)
Enter a number: -2

Please enter a non-negative number.

'''
