"""
Given a natural number n, print all distinct divisors of it.
Input : n = 10
Output: 1 2 5 10
"""

import math


def Divisors(sqrnum):
    divisors = []

    for i in range(1, num):
        if(num % i == 0):
            divisors.append(i)
    divisors.append(num)
    return(divisors)

if __name__ == '__main__':
    num = int(input("Enter the number "))
    if num < 1:
        print("Not a natural number")
    else:
        divisors = Divisors(num)
        print(divisors)

"""
Sample Input- Output:

Enter the number 50
[1, 2, 5, 10, 25, 50]
"""
