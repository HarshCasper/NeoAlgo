'''
Introduction 

The code below calculates and returns the next prime number when user inputs any number.
'''

# taking input from user
n = int(input("Enter a number between 0 and 1000000 : "))

# looping from next number to find if it prime or not
for x in range(n+1,9999999):
	# checking whether x is divisible by numbers from 2 to it's half
    for y in range(2,x//2+1):
        if x%y==0:
            break  # break if x is divisble cause it will not be a prime number then
    else:
        print("Next prime number is ",x) # if x is not divisible then printing x
        break  # break cause we found the result in form of x

'''
Sample output

>>>Enter a number between 0 and 1000000 : 17
Next prime number is 19
'''