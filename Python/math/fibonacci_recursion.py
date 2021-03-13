# Fibonacci Sequence Using Recursion

def fibo_rec(x):
    """
    >>fibo_rec(6)
    0 1 1 2 3 5

    >>fibo_rec(10)
    0 1 1 2 3 5 8 13 21 34

    """
    if x == 0:
        return 0
    elif x == 1:
        return 1
    else:
        return fibo_rec(x-1) + fibo_rec(x-2)

if __name__ == "__main__":
    n = int(input("Enter the number of terms: "))
    for i in range(n):
        print(fibo_rec(i), end=" ")
