"""
Python program to get count of divisors.
Count of divisors refers to the count of numbers in the range [1 to n] which perfectly divides n.
"""

import math
# Function to calculate the count of divisors

def count_of_divisors(num):
    i = 1
    # Initializing cnt by 0

    cnt = 0
    while True:
        if i > math.sqrt(num):
            break
        # Increasing cnt by 1 for i

        if num % i == 0 and i == math.sqrt(num):
            cnt += 1
        # Increasing cnt by 2 for i and n/i

        elif num % i == 0:
            cnt += 2
        i += 1
    return cnt

if __name__ == '__main__':
    # Taking Input 

    n = int(input('Enter the number: '))
    # Printing Output

    print("The count of the divisors is: {} ".format(count_of_divisors(n)))

"""
Time Complexity - O(sqrt(n)), where 'n' is the number
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT
SAMPLE I

INPUT
Enter the number: 36

OUTPUT
The count of the divisors is: 9

"""

