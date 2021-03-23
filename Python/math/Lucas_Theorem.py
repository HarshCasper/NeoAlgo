
# Reference from GeeksForGeeks
'''
Lucas Theorem : 
Lucas' theorem is a result about binomial coefficients modulo a prime p.
We will be given three numbers n, r and p and we need to compute value of nCr mod p.
Excample 1:
Q.) : Find the remainder when 1000C300 is divided by 13.
Sol : First we write 1000 and 300 in terms of the sum of power of 13
             1000 = 5(13^2) + 11(13) + 12 
              300 = 1(13^2) + 10(13) + 1
        Then apply Lucas Theorem:
                                1000C300 = (5C1) * (11C10) * (12C1)
                                         = 5 * 11 * 12
                                         = 5 *(-2) * (-1) 
                                         = 10
Example 2:
Input:  n = 10, r = 2, p = 13
Output: 6
'''
'''defining the modulo function.'''
def Mod(n, r, p): 
    arr = [0] * (n + 1);   
           #The array arr is going to store the
           # last row of the triangle 
           # at the end. And last entry  
           # of last row is nCr 
    arr[0] = 1;    
    for i in range(1, (n + 1)):       
        j = min(i, r);  
        while(j > 0): 
            arr[j] = (arr[j] + arr[j - 1]) % p; 
            j -= 1; 
    return arr[r]; 
###################################################
'''
calculate the last digit of n and r for base p, 
then recur 
the remaining digits 
'''
def Lucas(n, r, p): 
    if (r == 0):
        return 1;  
    nth = int(n % p); 
    rth = int(r % p);            
    return (Lucas(int(n / p), int(r / p), p) * Mod(nth, rth, p)) % p; 
########################################################################
n = int(input("Enter The Value of n : "))
r = int(input("Enter The Value of r : "))
p = int(input("Enter The Value of p : "))
print("Value of nCr % p is",Lucas(n, r, p)); 

'''
  Time Complexity : O(P^2)
  Space Complexity : O(P)
'''
