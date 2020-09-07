#Extended Euclidean Algorithm

def Extended_gcd(a, b, x, y):
    #Base Case
    if a == 0:
        x = 0
        y = 1
        return b

    x1, y1 = 0, 0
    gcd = Extended_gcd(b % a, a, x1, y1)

    x = y1 - int(b / a) * x1
    y = x1

    return gcd

#Main code
a = int(input())
b = int(input())
x, y = 0, 0
print("GCD of numbers " + str(a) + " and " + str(b) + " is " + str(Extended_gcd(a, b, x, y)))
