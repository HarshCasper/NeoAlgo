def multiply_fun(li):
    result = 1
    for i in li:
        result *= i
    return result

k = int(input("Enter size of array : "))
print("Enter value of coprime divisors :", end=' ')
n = list(map(int, input() . split()))
print("Enter value of remainders :", end=' ')
a = list(map(int, input().split()))


def chineserem(n, a):
    sum = 0
    pr = multiply_fun(n)
    for n_i, a_i in zip(n, a):
        p = pr/n_i
        sum += a_i * muinv(p, n_i)*p
    return sum % pr


def muinv(a, b):
    b0 = b
    x0, x1 = 0, 1
    if b == 1:
        return 1
    while a > 1:
        q = a//b
        a, b = b, a % b
        x0, x1 = x1 - q * x0, x0
    if x1 < 0:
        x1 += b0
    return x1


print("x = ", chineserem(n, a))
# Sample Input - >
# Enter size of array : 3
# Enter value of coprime divisors : 2 3 5
# Enter value of remainders : 1 2 4
# x =  29.0
