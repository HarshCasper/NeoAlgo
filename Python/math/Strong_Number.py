"""
Basically a strong number is number in which sum of factorial of each digit
of the number is equal to that number
EX : Consider 145=1! + 4! + 5! = 1 + 24 + 120 = 145
Here input a number
We initialize sum to 0 and assign the input number to a temporary variable
In side while loop --> (we find sum of factorial of each digit of the number)
In side factorial function --> (we calculate the factorial of each digit and return it)
In the end if number and the sum obtained is equal then it is a Strong number
otherwise not
"""


def factorial(n) :
    p = 1
    for i in range(1 , n + 1) :
        p = p * i
    return p


number = int(input("Enter a number greater than zero : "))
temp = number
sums = 0
if number > 0 :
    while temp > 0 :
        remainder = temp % 10
        sums = sums + factorial(remainder)
        temp = temp // 10
    if sums == number :
        print('Number' , number , 'is a Strong Number')
    else :
        print('Number' , number , 'is not a Strong Number')
else :
    print('0 is not a Strong Number')

# Time Complexity : O(log n)
# Space Complexity : O(1)

# TestCase 1:
# Enter a number greater than zero : 65
# Number 65 is not a Strong Number
# TestCase 2:
# Enter a number greater than zero : 145
# Number 145 is a Strong Number
