# Python Program to find Binary Exponent Iteratively and Recursively.

# Iterative function to calculate exponent.
def binExpo_iterate(a,b):
    res=1
    while b>0:
        if b%2==1:
            res=(res*a)
        a=a*a
        b//=2
    return res

# Recursive function to calculate exponent.
def binExpo_recurse(a,b):
    if b==0:
        return 1
    res=int(binExpo_recurse(a,b//2))
    res=res*res
    if b%2==1:
        return (res*a)
    else:
        return res

# Main function
a=int(input())
b=int(input())

if a==0 and b==0:
    print("Math error")
elif b<0:
    print("Exponent must be positive")
elif a==0:
    print(0)
else:
    resIterate=binExpo_iterate(a,b);
    resRecurse=binExpo_recurse(a,b);
    print(resIterate)
    print(resRecurse)
