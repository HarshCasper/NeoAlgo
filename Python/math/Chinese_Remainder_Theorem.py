"""
Chinese Remainder Theorem: In number theory, the Chinese remainder theorem
        states that if one knows the remainders of the Euclidean division
        of an integer n by several integers, then one can determine uniquely
        the remainder of the division of n by the product of these integers,
        under the condition that the divisors are pairwise coprime.

Method : Chinese Remainder Theorem / Inverse Modulo Implementation

"""

def multiply_fun(li):
    result = 1
    for i in li:
        result *= i

    return result


def Chinese_Remainder(n, a):
    sum = 0
    pr = multiply_fun(n)

    for n_i, a_i in zip(n, a):
        p = pr / n_i

        sum += a_i * muinv(p, n_i) * p

    return int(sum % pr)


def muinv(a, b):
    b0 = b
    x0, x1 = 0, 1

    if b == 1:
        return 1

    while a > 1:
        q = a // b
        a, b = b, a % b
        x0, x1 = x1 - q * x0, x0

    if x1 < 0:
        x1 += b0

    return x1

# ----------------------------- DRIVER CODE ---------------------------


if __name__ == "__main__":

    k = int(input("Enter size of array : "))
    n = list(map(int, input("Enter value of coprime divisors :") . split()))
    a = list(map(int, input("Enter value of remainders :").split()))

    ans = Chinese_Remainder(n, a)

    print("x = ", ans)

'''
Time Complexity : O(N^2)
Space Complexity: O(N)
'''

"""
Sample Input / Output

Enter size of array : 3
Enter value of coprime divisors : 2 3 5
Enter value of remainders : 1 2 4
x =  29.0


Enter size of array : 5
Enter value of coprime divisors : 5 4 3 7 11
Enter value of remainders : 1 2 3 4 5
x =  1446.0
"""

