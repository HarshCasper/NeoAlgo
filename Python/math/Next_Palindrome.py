'''
Python Program to get the next nth palindrome of a given number.
An integer is a palindrome if the reverse of that number is
equal to the original number.
'''


def isPalindrome(num):
    return str(num) == str(num)[::-1]


def getNthPalindrome(n, start):
    if n < 1:
        return start

    while not isPalindrome(start + 1):
        start += 1

    return getNthPalindrome(n - 1, start + 1)


if __name__ == '__main__':
    num = int(input('Enter a Number: '))
    n = int(input('Enter nth position: '))
    print(getNthPalindrome(n, num))


'''
Sample Case:
Example 1:
Enter a number: 12021
Enter nth position: 10
13031

Example 2:
Enter a number: 141
Enter nth position: 5
191

Time Complexity: O(10^k)
Space Complexity: O(1)
where k = no of digits in given number
'''
