''' program to check if the number is an Armstrong number or not
A positive number is called Armstrong Number if it is equal to the sum of cubes of its digits
'''

num = int(input("Enter a number: "))
sum = 0

# finding  the sum of the cube of each digit
temp = num
while temp > 0:
   digit = temp % 10
   sum += digit ** 3
   temp //= 10

if num == sum:
   print(num,"is an Armstrong number")
else:
   print(num,"is not an Armstrong number")

'''Sample Input Output
case 1
Enter a number: 407
407 is an Armstrong number
case 2
Enter a number: 22
22 is not an Armstrong number

Time complexity: O(log(n))
Space complexity: O(1)
'''