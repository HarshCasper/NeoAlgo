# Problem statement- You are given N, and for a given N x N chessboard. We have to place all queens such that they are not in the same row, or same column, or the same diagonal of any of the other queens.

def isSafeToPut(i,j,n,solution):
    '''
    Summary Line:
    This fuction helps us to check whether we can put a queen at (ixj)th position in the matrix by checking for any other queens present vertically, horizontally and diagonally to this position.

    Returns:
    Boolean value
    '''
    k=i-1
    while k>=0:
        if solution[k][j]:
            return False
        k-=1
    row=i-1
    col=j-1
    while row>=0 and col>=0:
        if solution[row][col]:
            return False
        row-=1
        col-=1
    row=i-1
    col=j+1
    while row>=0 and col<n:
        if solution[row][col]:
            return False
        row-=1
        col+=1
    return True

def nqueen(solution,n,i):
    '''
    Summary Line:
    This is a recursive function that helps to place the queens on the matrix. If the queen cannot be placed in a particular row, then this function helps us backtrack to change previously placed queens. Also, help us to print the matrix on hitting the base case.

    Returns:
    Boolean value
    '''
    if i==n:
        for i in range(n):
            for j in range(n):
                print(solution[i][j],end=" ")
        print()
        return False
    for j in range(n):
        solution[i][j]=1
        if isSafeToPut(i,j,n,solution):
            if nqueen(solution,n,i+1):
                return True
        solution[i][j]=0
    return False


if __name__ == "__main__":
    n=int(input())
    solution=[[0 for j in range(n)]for i in range(n)]
    nqueen(solution,n,0)

# Sample input-
# 4

# Sample output-
# 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
# 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
