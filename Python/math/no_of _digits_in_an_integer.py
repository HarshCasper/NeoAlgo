# Program to count digits in an integer 

def iterative_countDigits(number):
    '''Function to count the number of digits in an integer using the iterative approach.'''
    count = 0
    while number != 0: 
        number //= 10                
        count+= 1
    return count 

#Recursive approach
def recursive_countDigits(number): 
    '''Function to count the number of digits in an integer using the recursive approach.'''
    if number == 0: 
        return 0
    return 1 + recursive_countDigits(number // 10) 

if __name__ == "__main__":
    number = int(input("Enter the number: "))
    print(iterative_countDigits.__doc__)
    print("The no. of digits in {} is: {} ".format(number, iterative_countDigits(number)))
    print(recursive_countDigits.__doc__)
    print("The no. of digits in {} is: {} ".format(number, recursive_countDigits(number)))

"""
Output:-
Enter the number: 4567
Function to count the number of digits in an integer using the iterative approach.
The no. of digits in 4567 is:4
Function to count the number of digits in an integer using the recursive approach.
The no. of digits in 4567 is:4
"""     
