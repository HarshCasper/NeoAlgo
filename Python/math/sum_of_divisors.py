"""
Python program to get sum of divisors.
The Sum of divisors refers to the sum of numbers in the range [1 to n] which perfectly divides n.
"""

import math
# Function to get the sum of divisors

def sum_of_divisors(num):
    # Initializing i as 1 and sum as 0

    i = 1
    sum = 0
    while True:
        if i > math.sqrt(num):
            break
        # Adding i to sum if it is a factor

        if num % i == 0 and i == math.sqrt(num):
            sum += i
        # Adding i and n/i to sum if i is a factor
        
        elif num % i == 0:
            sum += i
            sum += num // i
        i += 1
    return sum

if __name__ == '__main__':
    # Taking Input

    n = int(input("Enter the number :"))
    # Printing Output

    print("The sum of the divisors is: {} ".format(sum_of_divisors(n)))

"""
Time Complexity - O(sqrt(n)), where 'n' is the number
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT
SAMPLE I

INPUT
Enter the number: 36

OUTPUT
The sum of the divisors is: 91

"""

