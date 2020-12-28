#to check whether a word is a palindrome

s1=input("enter the word ").lower()
r1=s1[::-1]

if s1 == r1:
	print("The word is a palindrome")
else:
	print("The word is not a palindrome")