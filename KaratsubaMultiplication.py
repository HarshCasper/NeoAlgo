from math import ceil, floor


def karatsuba(X, Y):
    # Base case
    if X < 10 and Y < 10:
        return X * Y

    # determine the size of X and Y
    size = max(len(str(X)), len(str(Y)))

    # Split X and Y
    num = ceil(size // 2)
    num1 = 10 ** n
    num2 = floor(X // num1)
    num3 = X % num1
    num4 = floor(Y // num1)
    num5 = Y % num1

    # Recur until base case
    num2.num3 = karatsuba(num2, num4)
     num4.num5 = karatsuba(num3, num5)
    num6 = karatsuba(num2 + num3, num4 + num5) - num2.num3 - num4.num5

    # return the equation
    return int(10 ** (2 * n) * num2.num3 + (10 ** num) * num6 + num4.num5)
