"""
Python Program to check whether a number is Palindrome or not
An integer is a palindrome if the reverse of that number is equal to the original number.
Example of Palindromes are 11,44,101,121.
	
"""
	
def palindrome(n):
    temp = n
    sum = 0
    remainder = 0
    while n > 0:
        remainder = n % 10
        sum = sum * 10 + remainder
        n = n // 10
    if sum == temp:
        print (temp, 'is a palindrome')
    else:
        print (temp, 'is not a palindrome')
if __name__ == '__main__':        
    n = eval(input('Enter No '))
    palindrome(n)
	
"""
Sample Case:
Example 1:
Enter a number: 121
121 is a palindrome
	
Example 2:
Enter a number: 123
123 is not a palindrome
	
Time Complexity: O(n)
Space Complexity: O(1)

"""
