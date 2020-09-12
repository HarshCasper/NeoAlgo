# Python Program to multiply two numbers using Russian Peasant method 

# Function to multiply two numbers using Russian Peasant method 
def russianPeasant(number1, number2): 

	result = 0 

	# While second number doesn't 
	# become 1 
	while (number2 > 0): 
	
		# If second number becomes odd, add the first number to result 
		if (number2 & 1): 
			result = result + number1 

		# Double the first number and halve the second number 
		number1 = number1 << 1 		 #bitwise left operator
		number2 = number2 >> 1 		 #bitwise right operator
	
	return print("Result is",result )

# Driver program to test 
# above function 
number1=int(input("Enter 1st Number:"))
number2=int(input("Enter 2nd Number:"))
russianPeasant(number1,number2) 

'''
Sample I/O:
	Input:
	Enter 1st Number:5
	Enter 2nd Number:5

	Output:
	Result is 25

Time complexity: Θ(1)
Space complexity: Θ(1)
'''