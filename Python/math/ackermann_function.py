# ACKERMANN FUNCTION
# Definition: A function of two parameters whose value grows very fast.
# Formal Definition:
#   A(0, j)=j+1 for j ≥ 0
#  	A(i, 0)=A(i-1, 1) for i > 0
#  	A(i, j)=A(i-1, A(i, j-1)) for i, j > 0
# In 1928, Wilhelm Ackermann observed that A(x,y,z),
# the z-fold iterated exponentiation of x with y,
# is a recursive function that is not primitive recursive.
# A(x,y,z) was simplified to a function
# of 2 variables by Rózsa Péter in 1935.
# Raphael M. Robinson simplified the initial condition in 1948.


def Ackermann_func(m, n):
    history = [[0 for i in range(n + 1)] for j in range(m + 1)]
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                history[i][j] = j + 1
            elif j == 0:
                history[i][j] = history[i-1][1]
            else:
                a = i - 1
                b = history[i][j-1]
                if a == 0:
                    result = b + 1
                elif b <= n:
                    result = history[i-1][history[i][j-1]]
                else:
                    result = (b-n)*(a) + history[a][n]
                history[i][j] = result
    return history[m][n]
m, n = input("Enter non-negative values of m and n: ").split()
m, n = int(m), int(n)
print("A(%u, %u) = %u" % (m, n, Ackermann_func(m, n)))

# SAMPLE INPUT: Enter non-negative values of m and n: 2 2
# SAMPLE OUTPUT: A(2,2) = 7
# Time complexity: O( M * N )
# Space complexity: O( M * N )
