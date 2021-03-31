# code to check if  number is prime. This program demonstrates concept behind AKS algorithm and doesn't implement the actual
# algorithm (This works only  till n = 64)
def expandX1(m):
    c = [1]
    for i in range(m):
        c.append(c[-1] * -(m-i) / (i+1))
    return c[::-1]

def isPrime(m):
    if m < 2: return False
    c = expandX1(m)
    c[0] += 1
    return not any(mul % m for mul in c[0:-1])



print('for small primes]AKS TEST GAVE THE FOLLOWING AS PRIMES')
print([m for m in range(1000) if isPrime(m)])

'''
Time Complexity: O(log(n))
Space Complexity: O(1)

OUTPUT :
  # [for small primes]AKS TEST GAVE THE FOLLOWING AS PRIMES
  [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]

'''