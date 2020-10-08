'''
Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
shows the first 11 ugly numbers.
'''


def Divide(a, b):
    while a % b == 0:
        a = a / b
    return a


def isUgly(num):
    num = Divide(num, 2)
    num = Divide(num, 3)
    num = Divide(num, 5)
    return 1 if num == 1 else 0


def getUglyNo(num):
    i = 1
    count = 1
    while num > count:
        i += 1
        if isUgly(i):
            count += 1
    return i

num = int(input("Enter Number: "))
ugly = getUglyNo(num)
print("Ugly number is ", ugly)

'''
Time Complexity:O(n)
Space Complexity: O(1)

Example 1:
Input:
Enter Number: 10
Output:
Ugly number is 12

Example 2:
Input:
Enter Number: 4
Output:
Ugly number is 4
'''
