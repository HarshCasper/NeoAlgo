# This program checks whether a number is an armstrong number or not

import math

def no_of_digits(n : int) -> int:
    count = 0
    while n > 0:
        count += 1
        n = n // 10
    return count

def add(n : int) -> int:
    temp = n
    tot = 0
    nod = no_of_digits(temp)
    while n > 0:
        r = n % 10
        tot += r ** nod
        n = n // 10
    return tot

def checkArmstrong(num : int) -> bool:
    return add(num) == num
    
num = int(input("Enter the number"))
print(add(num))
if checkArmstrong(num):
    print("It is an armstrong number")
else:
    print("It is not an armstrong number")
    
# Example: 
# 1. Input : 153
#   Output : It is an armstrong number
# 2. Input : 12
#   Output : It is not an armstrong number
