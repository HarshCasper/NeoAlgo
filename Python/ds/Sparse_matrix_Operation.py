"""

Input:

    Enter the number of rows: 3

    Enter the number of columns: 3

    Enter the entries row wise:
    1
    1
    0
    0
    0
    0
    0
    2
    0

Output:

    Given matrix is a sparse matrix
    [0, 0, 2]
    [0, 1, 1]
    [1, 1, 2]


Time Complexity:O(noOfRows*noOfcolumns)
Space Complexity:O(1)

"""


# for row and column input


ROW = int(input("Enter the number of rows:"))
COLUMN = int(input("Enter the number of columns:"))


# Initialize matrix


matrix = []

print("Enter the entries row wise:")

# For user input


for i in range(ROW):          # A for loop for row entries
    a = []
    for j in range(COLUMN):      # A for loop for column entries
        a.append(int(input()))
    matrix.append(a)        # taking input of arrays

# Initializing count = 0 to count the number of zeros.

count = 0

# Calculates number of rows and columns present in given matrix


matrix_rows = len(matrix)
matrix_cols = len(matrix[0])

# Calculates the size of the array


size = matrix_rows * matrix_cols


# Count all zero element present in matrix

for i in range(0, matrix_rows):
    for j in range(0, matrix_cols):
        if(matrix[i][j] == 0):
            count = count + 1


# Sparse Matrix definition

def sparse_matrix():
    size = 0
    for i in range(ROW):
        for j in range(COLUMN):
            if (matrix[i][j] != 0):
                size += 1

    matrix_rows, matrix_cols = (3, size)
    Print_Matrix = [[0 for i in range(matrix_cols)]
                    for j in range(matrix_rows)]

    k = 0
    for i in range(ROW):
        for j in range(COLUMN):
            if (matrix[i][j] != 0):
                Print_Matrix[0][k] = i
                Print_Matrix[1][k] = j
                Print_Matrix[2][k] = matrix[i][j]
                k += 1

    for i in Print_Matrix:
        print(i)


if(count == size):
    print("Null Mtrix")

elif(count > (size/2)):
    print("Given matrix is a sparse matrix")
    sparse_matrix()

else:
    print("Given matrix is not a sparse matrix")
