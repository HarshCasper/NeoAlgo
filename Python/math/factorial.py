# Calculate factorial using iterative approach
def fact(x):
    result = 1
    for i in range(1,x):
        result = result * (i+1)
    return result

# Calculate factorial using recursion
def fact_rec(x):
    if x == 0 or x == 1:
        return 1
    else:
        return x * fact_rec(x-1)


if __name__ == "__main__":
    n = int(input("Enter the number: "))
    print("The factorial of {} is: {} ".format(n, fact(n)))
