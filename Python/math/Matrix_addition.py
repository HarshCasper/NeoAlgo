"""
In mathematics, matrix addition is the operation of adding two matrices by adding 
the corresponding entries together.This program takes two matrices of order r*c and 
stores it in two-dimensional array. Then, the program adds these two matrices and 
displays it on the screen.
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
# Adding both matrices and storing in result
for i in range(Row_1):
    for j in range(Col_2):
        result[i][j] = matrix_1[i][j] + matrix_2[i][j]

print("The result of the matrix Addition is")
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
Enter the number of columns for second matrix : 3
Enter the entries rowwise:
1 2 3
4 5 6
7 8 9
The result of the matrix Addition is
2 4 6
8 10 12
14 16 18

Time complexity : O(n^2)
Space complexity : O(n^2)
"""
