# Importing sys module to initalize the maxsize
import sys
''' Floyd Warshall Algorithm '''
''' Problem Statement :The problem is to find shortest distances
                      between every pair of vertices in a given
                      edge weighted directed Graph. The Graph is
                      represented as Adjancency Matrix, and the
                      Matrix denotes the weight of the edegs
                      (if it exists) else INF (1e7).
'''
# Assigning max value a variable can take
INT_MAX = sys.maxsize - 1
# Initialize Infinity
INF = 9999999
# Enter the size of the matrix
print("Enter the sides of the Matrix : ")
print("Enter the Row and the Column")
row = int(input("Row:"))
col = int(input("Column:"))
# Taking input of list
print("Enter the integers:")
graph = list(map(str, input().rstrip().rsplit()))
# Convert the given list into integers
for i in range(row*col):
    if(graph[i] == "INF"):
        graph[i] = INF
    else:
        graph[i] = int(graph[i])
# Constructing a Matrix.
graph = [graph[i:i + col] for i in range(0, len(graph), col)]
# Floyd Warshall


def FloydWarshall(graph, row, col):
    table = list(map(lambda i: list(map(lambda j: j, i)), graph))
    # Add the vertices
    for k in range(row):
        for i in range(col):
            for j in range(row):
                table[i][j] = min(table[i][j], table[i][k] + table[k][j])
    return(table)
# Print List Function


def printlist(table):
    for i in table:
        print(*i)
FW = FloydWarshall(graph, row, col)
print("The shortest paths are".format(printlist(FW)))
'''
Sample input:
    Enter the sides of the Matrix :
    Enter the Row and the Column
    Row:4
    Column:4
    Enter the integers:
    0 3 INF 5 2 0 INF 4 INF 1 0 INF INF INF 2 0
Sample Output:
    The shortest paths are
    0 3 7 5
    2 0 6 4
    3 1 0 5
    5 3 2 0
'''
