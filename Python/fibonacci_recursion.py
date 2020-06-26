# Fibonacci Sequence Using Recursion

def fibo_rec(x):
    if x == 0:
        return 0
    elif x == 1:
        return 1
    else:
        return fibo_rec(x-1) + fibo_rec(x-2)

if __name__ == "__main__":
    n = int(input("Enter the number of terms:"))
    for i in range(n):
        print(fibo_rec(i), end=" ")
