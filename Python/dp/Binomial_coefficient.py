'''
Purpose:
A binomial coefficient C(n, k) can be defined as the coefficient of x^k in the expansion of (1 + x)^n.
A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects more formally, the number of k-element subsets (or k-combinations) of a n-element set.

Read on: https://en.wikipedia.org/wiki/Binomial_coefficient

Basic formula: c(n,k) = c(n-1, k-1) + c(n-1, k)
Base condition: c(n,0)= c(n,n) = 1

For recursive method:
Time Complexity : O(2^n)
Space complexity : O(n)
'''
'''
n ---> total number of objects
k ---> Number of objects to be chosen from n
'''

def binomial_coeff_recursive(n, k):
    # if total number of objects to be chosen from is greater than total number of objects present
    if k > n:
        return 0
    
    # Base condition
    if k == 0 or k == n:
        return 1
 
    # Recursive Call
    return binomial_coeff_recursive(n-1, k-1) + binomial_coeff_recursive(n-1, k)

# Driver Program to test ht above function
n = int(input('Total number of objects: '))
k = int(input('Number of objects to be chosen: '))
print ("Value of C(%d,%d) is (%d)" % (n, k,binomial_coeff_recursive(n, k)))

'''
output:

Total number of objects: 5
Number of objects to be chosen: 2
Value of C(5,2) is (10)
'''


