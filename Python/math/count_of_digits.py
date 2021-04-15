"""
Python program to get count of digits.
Count of digits refers to the sum of the frequency of all distinct digits in a number.
"""

# Function to count digits in the number

def count_of_digits(n):
    if(n==0):
      return 1
    # Initializing cnt variable to zero

    cnt = 0
    while True: 
        if(n==0):
          break
        # Increasing the cnt

        cnt+=1 
        # Removing the least significant digit

        n = n//10
    return cnt

if __name__ == '__main__':
    # Taking Input

    n = int(input("Enter the number :"))
    # Printing Output

    print("The count of digits in the given number is: {} ".format(count_of_digits(n)))

"""
Time Complexity - O(n), n is the count of digits in the number
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT
SAMPLE I

INPUT
Enter the number: 8965

OUTPUT
The count of digits in the given number is: 4

"""

