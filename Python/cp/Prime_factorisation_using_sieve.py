'''
Python Program to calculate prime factorization of a number n in O(Log n) time complexity using sieve. 
'''
import math
  
Max_Num = 10001
  
small_prime_factor = [0 for num in range(Max_Num)] # smallest prime factor for every number 

def sieve(): 

    ''' Function that calculates Smallest Prime Factor for every number till Max_Num. '''

    
    for num in range(1, Max_Num):# smallest prime factor for every number is the number itself
        small_prime_factor[num] = num
  
  
        if(num % 2 == 0):# smallest prime factor of every even number is 2
           
          small_prime_factor[num] = 2 
  
    for num in range(3, math.ceil(math.sqrt(Max_Num))): 
                
        if (small_prime_factor[num] == num): # checks if num is a prime number
                         
            for num1 in range(num^2, Max_Num, num): # small prime factors for all numbers divisible by num.                  
               
                if (small_prime_factor[num1] == num1): 
                    small_prime_factor[num1] = num # marking small_prime_factor[num1]
  

def get_factorization(element): # function definition

    '''
    Function that calculates prime factors by dividing by smallest  
    prime factor at every step.
    Params: element (input)
    returns: factors
    
    '''
    factors1 = set() # adding factors to set: factors1 to avoid duplicates

    while (element != 1): 

        factors1.add(small_prime_factor[element]) 

        element = element // small_prime_factor[element] # floor divison

    factors= list(factors1) # converting set to list to access the elements of the set
    return factors
  
if __name__ == "__main__": 

  ''' Main function that runs functions: sieve and get_factorization '''
  
  sieve() # Calculates Smallest Prime Factor 

  element = int(input("Enter the number to find prime factors for:"))

  print("Prime factors of",element, ":",end = "") 

  y = get_factorization(element) # function calling
  
  for num in range(len(y)): 
    print(y[num], end = " ") 

''' 
Sample Output 

Enter the number to find prime factors for:288
Prime factors of 288 :2 3

'''
