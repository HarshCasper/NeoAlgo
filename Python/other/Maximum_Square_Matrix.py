# find the size of Maximum Square Matrix With All 1s


def MaxSquare(mat):
    # creating a null matrix
	ans = 0
    temp = [[0] * len(mat[0])] * len(mat)
    # Traversing through the given matrix
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            temp[i][j] = mat[i][j]
            # checking if it is not a corner case:
            if i > 0 and j > 0 and mat[i][j] == 1:
                temp[i][j] = min(temp[i][j - 1], temp[i - 1][j], temp[i - 1][j - 1])
				temp[i][j] += 1
            # for finding max size of square mat
            if ans < temp[i][j]:
                ans = temp[i][j]
    return ans


mat = []
rows = input("Enter rows")
col = input("Enter col")
for i in range(0, int(rows)):
    mat.append([int(j) for j in input().split()])

print("output is", MaxSquare(mat))
'''
output:
Enter rows3
Enter col3
0 0 0
0 1 0
0 0 0

output is 1

Enter rows3
Enter col3
0 1 1
0 1 1
0 0 0

output is 2

Time Complexity : O(rows*col)'''

