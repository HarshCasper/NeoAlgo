# Program to verify if a given number is an Armstrong number or not

# taking the input number from the user
number = int(input())

# initializing sum
sum = 0

# find the sum of the cube of each digit
temp = number
while temp > 0:
   dig = temp % 10
   sum += dig ** 3
   temp //= 10

# display the result
if number != sum:
    print(number, "is not an Armstrong Number.")
else:
    print(number, "is an Armstrong Number.")
