"""
Julia program to check if a number is a pronic number
Pronic Numbers are those numbers that can be arranged to form a rectangle.
It is a number which is the product of two consecutive integer
"""

import math

def check_pronic(x):
    i = 0
    while(i <= math.sqrt(x)):
        if(x == i * (i + 1)):
            return True
        i = i + 1   
    return False 


if __name__ == '__main__':
    print("Enter the number: ", end="")
    n = int(input())
    res = check_pronic(abs(n))
    if(res):
        print("The given number {} is a pronic number.".format(n))
    else:
        print("The given number {} is not a pronic number.".format(n))



"""
Time Complexity: O(log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number: 154
The given number 154 is not a pronic number.

SAMPLE 2
Enter the number: 72
The given number 72 is a pronic number.
"""
