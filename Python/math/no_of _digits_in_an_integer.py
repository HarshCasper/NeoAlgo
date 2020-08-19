# Program to count digits in an integer 

#Iterative approach
def iterative_countDigits(n):
    count = 0
    while n != 0: 
        n //= 10                
        count+= 1
    return count 

#Recursive approach
def recursive_countDigits(n): 
    if n == 0: 
        return 0
    return 1 + recursive_countDigits(n // 10) 

if __name__ == "__main__":
    n = int(input("Enter the number: "))
    print("Iterative approach")
    print("The no. of digits in {} is: {} ".format(n, iterative_countDigits(n)))
    print("Recursive approach")
    print("The no. of digits in {} is: {} ".format(n, recursive_countDigits(n)))

"""
Output:-
Enter the number: 4567
Iterative approach
The no: of digits in 4567 is:4
Recursive approach
The no: of digits in 4567 is:4
"""     