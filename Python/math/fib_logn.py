

# Matrix multiplication of two 2x2 matrices
def matmult(Mat1, Mat2):
    Mat3 = [[0 for i in range(2)] for j in range(2)]
    Mat3[0][0] = Mat1[0][0] * Mat2[0][0] + Mat1[0][1] * Mat2[1][0]
    Mat3[0][1] = Mat1[0][0] * Mat2[0][1] + Mat1[0][1] * Mat2[1][1]
    Mat3[1][0] = Mat1[1][0] * Mat2[0][0] + Mat1[1][1] * Mat2[1][0]
    Mat3[1][1] = Mat1[1][0] * Mat2[0][1] + Mat1[1][1] * Mat2[1][1]
    return Mat3


# kth Fibonacci number in O(logn)
def fib(k):
    A = [[1, 1],
         [1, 0]]
    if k <= 1:
        return A    
    if k % 2 == 1:
        return matmult(A, fib(k-1))
    fib_half = fib(k//2)
    return matmult(fib_half, fib_half)


for ii in range(10):
    print(fib(ii)[0][0])
