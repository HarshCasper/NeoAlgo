inff = 99999999999999
def floydwarshall(G):
    table = list(map(lambda i: list(map(lambda j: j, i)), G))
    n=len(G)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                table[i][j] = min(table[i][j], table[i][k] + table[k][j])
    printgraph(table,n)

def printgraph(table,n):
    for i in range(n):
        for j in range(n):
            if(table[i][j] == inff):
                print("inff", end=" ")
            else:
                print(table[i][j], end="  ")
        print(" ")


G = [[0, 3, inff, 5],
         [2, 0, inff, 4],
         [inff, 1, 0, inff],
         [inff, inff, 2, 0]]
floydwarshall(G)
