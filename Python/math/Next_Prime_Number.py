'''
Introduction 

The code below calculates and returns the next prime number from the number given by user.

Time Complexity : O(n²)
Space Complexity : O(1)

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
Sample output

Enter a number : 23
Next prime number is  29
'''