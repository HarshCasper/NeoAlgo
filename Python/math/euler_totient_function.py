# python program for Euler's Totient Function 
import math
def euler_totient(q):
    ans=q   #defining the answer initially to n
    for i in range (2,int(math.sqrt(q+1))):
      if (q%i == 0):    #checking if i is a factor of q
        while (q%i == 0): 
          q/=i             # if the condition is satisified we are updating the value of n
        ans-= ans/i        # just as we do in sieve of eratosthenes algorithm
                           # we are decreasing values for the multiples of primes
    if (q>1):              #this case ensures that if n have a prime factor greater than sqrt(n) then we are counting thaat case
     ans-=ans/q            
     
    print(int(ans))
    
print("Enter number of elements : ")
n = int(input())           # taking input from the user
if(n<0):                   
    print("inavlid input")
else:
    euler_totient(n)