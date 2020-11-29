'''
    is_prime_iterative() function uses an iterative approch to chech the primality
of the pased argument.
    It checks for each number i from 2 to sqrt(num)+1 that wether it divides the
passed number or not. If it does the passed number is not prime, otherwise the 
number is prime.

Time Complexity: O(sqrt(n))
Space Complexity: O(1)
Return Type: Boolean
'''
def is_prime_iterative(num):

    #Base Cases
    if(num<=1):
        return False
    if num==2:
        return True
    
    #Now, we will check from 2 to sqrt(num)+1, if any number within divides the 
    #completely, then the number is not prime hence return False
    for i in range(2,int(num**(1/2))+1):
        if num%i==0:
            return False

    #If the passes this test, then the num is prime, hence return True
    return True


'''
    is_prime_recursive() function checks the primality of number passed through recursive approch
It is similar to the iterative function but here we use recursion to check for the next divisor

Time Complexity: O(sqrt(n))
Space Complexity: O(1)
Return Type: Boolean
'''
def is_prime_recursive(num,i=2):

     #Base Cases
    if(num<=1 or n%i==0):
        return False

    if num==2 or i*i>n:
        return True

    #check the next divisor
    return is_prime_recursive(num,i+1)

#-------------------------------------------------Driver Code---------------------------------------------------

if __name__ == "__main__":
    n = int(input("Enter the number to be checked : "))
    print("Iterative Approch:- ",is_prime_iterative(n))
    print("Recursive Approch:- ",is_prime_recursive(n))
    
"""
Enter the number to be checked : 13
Iterative Approch:-  True
Recursive Approch:-  True

Enter the number to be checked : 35
Iterative Approch:-  False
Recursive Approch:-  False

Enter the number to be checked : 1
Iterative Approch:-  False
Recursive Approch:-  False

"""