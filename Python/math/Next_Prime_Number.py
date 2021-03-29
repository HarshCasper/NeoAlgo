'''
INTRODUCTION

The code below calculates and returns the next prime number from the number given by user.
It takes a number n from user and returns a number x such that
1. x is greater than n
2. x is a prime number and 
3. there are no prime numbers between n and x 

'''

def next_prime(n):
	# looping from next number to find if it prime or not
	x = n+1
	while True:
		flag = False
		# checking whether x is divisible by numbers from 2 to it's half
		for y in range(2,x//2+1):
			if x%y==0:
				x+=1
				flag = True
				break
		if flag==False:
			return(x)

n = int(input("Enter a number : "))
print('Next prime number is ', next_prime(n))

'''
OUTPUT

Enter a number : 23
Next prime number is  29


TIME COMPLEXITY : O(n²)
SPACE COMPLEXITY : O(1)
'''
