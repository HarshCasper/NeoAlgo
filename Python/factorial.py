def fact(x):
    result = 1
    for i in range(1,x):
        result = result * (i+1)
    return result


if __name__ == "__main__":
    n = int(input("Enter the number: "))
    print("The factorial of {} is: {} ".format(n, fact(n)))
