'''
Python program to calculate prime factorization  
of a number n in O(Log n) time complexity using sieve. 
'''
import math as mf
  
Max_Num = 100001
  
# stores smallest prime factor for every number 
spf = [0 for i in range(Max_Num)]   

def sieve(): 
    ''' Function that calculates SPF (Smallest Prime Factor) for every number till Max_Num. '''
    spf[1] = 1
    for i in range(2, Max_Num):# marking smallest prime factor for every number to be itself.
        spf[i] = i 
  
    # separately marking spf for  
    # every even number as 2 
    for i in range(4, Max_Num, 2): 
        spf[i] = 2 
  
    for i in range(3, mf.ceil(mf.sqrt(Max_Num))): 
          
        # checking if i is prime 
        if (spf[i] == i): 
              
            # marking SPF for all numbers 
            # divisible by i 
            for j in range(i * i, Max_Num, i):  
                  
                # marking spf[j] if it is not previously marked 
                if (spf[j] == j): 
                    spf[j] = i 
  

def getFactorization(x): 
    '''
    Function that calculates prime factors by dividing by smallest  
    prime factor at every step.
    Params: x (input)
    returns: ret
    '''
    factors1 = set() #adding factors to set:factors1 to avoid duplicates
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
  
# calling getFactorization function 
y = getFactorization(x) 
  
for i in range(len(y)): 
    print(y[i], end = " ") 