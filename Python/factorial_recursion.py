def fact_rec(x):
    if x == 0 or x == 1:
        return 1
    else:
        return x * fact_rec(x-1)


if __name__ == "__main__":
   n = int(input("Enter the number: "))
   print("The factorial of {} is: {} ".format(n, fact_rec(n)))
