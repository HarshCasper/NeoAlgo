'''
Python Program to calculate prime factorization  
of a number n in O(Log n) time complexity using sieve. 
'''
import math
  
Max_Num = 10001
  
spf = [0 for i in range(Max_Num)] #smallest prime factor for every number 

def sieve(): 
    ''' Function that calculates SPF (Smallest Prime Factor) for every number till Max_Num. '''
    spf[1] = 1
    for i in range(2, Max_Num):#smallest prime factor for every number is the number itself.
        spf[i] = i 
  
  
    for i in range(4, Max_Num, 2): #smallest prime factor of every even number is 2
        spf[i] = 2 
  
    for i in range(3, math.ceil(math.sqrt(Max_Num))): 
                
        if (spf[i] == i): # checks if i is a prime number
                         
            for j in range(i * i, Max_Num, i): #small prime factors for all numbers divisible by i.                  
               
                if (spf[j] == j): 
                    spf[j] = i 
  

def getFactorization(x): 
    '''
    Function that calculates prime factors by dividing by smallest  
    prime factor at every step.
    Params: x (input)
    returns: ret
    '''
    factors1 = set() #adding factors to set: factors1 to avoid duplicates
    while (x != 1): 
        factors1.add(spf[x]) 
        x = x // spf[x] 
    factors= list(factors1) #converting set to list to access the elements of the set
    return factors
  
# precalculating Smallest Prime Factor 
sieve() 
x = int(input("Enter the number to find prime factors for:"))
print("Prime factors of",x, ":", 
                                end = "") 
  

y = getFactorization(x) #function calling
  
for i in range(len(y)): 
    print(y[i], end = " ") 

''' 
Sample Output 

Enter the number to find prime factors for:288
Prime factors of 288 :2 3

'''
