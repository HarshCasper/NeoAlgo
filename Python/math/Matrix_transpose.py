"""
Transpose of a matrix is a matrix obtained by changing rows to columns and columns
to rows.In other words, transpose of Arr[][] is obtained by changing Arr[i][j] to Arr[j][i].
The below program finds transpose of matrix[][] and stores the result in result[][]
"""

Row = int(input("Enter the number of rows : "))
Col = int(input("Enter the number of columns : "))

matrix = []
print("Enter the entries rowwise:")
for i in range(Row):
    matrix.append([int(x) for x in input().split(" ")])

result = [[0 for i in range(Col)] for j in range(Row)]
# Storing transpose of matrix in result
for i in range(Row):
    for j in range(Col):
        result[i][j] = matrix[j][i]

print("The Transpose of the matrix is")
for i in range(Row):
    for j in range(Col):
        print(result[i][j], end=" ")
    print()

"""
Sample I/O :

Enter the number of rows : 3
Enter the number of columns : 3
Enter the entries rowwise:
1 2 3
4 5 6
7 8 9
The Transpose of the matrix is
1 4 7
2 5 8
3 6 9

Time complexity : O(n^2)
Space complexity : O(n^2)
"""
