"""
matrix multiplication is a binary operation that produces a product matrix 
from two matrices . To multiply two matrices, the number of columns of first 
matrix should be equal to the number of rows to second matrix.
This program finds the product of two given matrices
"""

Row_1 = int(input("Enter the number of rows for first matrix : "))
Col_1 = int(input("Enter the number of columns for first matrix : "))

matrix_1 = []
print("Enter the entries rowwise:")
for i in range(Row_1):
    matrix_1.append([int(x) for x in input().split(" ")])

Row_2 = int(input("Enter the number of rows for second matrix : "))
Col_2 = int(input("Enter the number of columns for second matrix : "))

matrix_2 = []
print("Enter the entries rowwise:")
for i in range(Row_2):
    matrix_2.append([int(x) for x in input().split(" ")])

result = [[0 for i in range(Col_2)] for j in range(Row_1)]
# Multiplying both matrices and storing in result
for i in range(Row_1):
    for j in range(Col_2):
        for k in range(Col_1):
            result[i][j] += matrix_1[i][k] * matrix_2[k][j]

print("The result of the matrix multiplication is")
for i in range(Row_1):
    for j in range(Col_2):
        print(result[i][j], end=" ")
    print()

"""
Sample I/O :

Enter the number of rows for first matrix : 3
Enter the number of columns for first matrix : 3
Enter the entries rowwise:
1 2 3
4 5 6
7 8 9
Enter the number of rows for second matrix : 3
Enter the number of columns for second matrix : 4
Enter the entries rowwise:
1 2 3 4
5 6 7 8
9 10 11 12
The result of the matrix multiplication is
38 44 50 56
83 98 113 128
128 152 176 200

Time complexity : O(n^3)
Space complexity : O(n^2)
"""
