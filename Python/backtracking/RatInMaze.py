'''
Problem statement- given a maze of 1s with obstacles (represented by 0). We have to print all the possible paths to the end.
Logical intuition- We have to explore all the possible paths hence our mouse will move in all four directions untill it reaches the end
'''

def printPathHelper(i,j,maze,n,solution):
    '''
    Summary Line:
    This funcion helps us to print the path followed by the rat in the maze. It puts 1s at places that the mouse can go and 0s at places where the mouse doesn't go.

    Args:
    i- current position on the maze horizontally
    j- current position on the maze vertically
    maze- The 2D matrix that was inputted through which the Rat has to pass
    n- side of the 2D matrix
    solution- solution matrix to be returned
    '''
    if i==n-1 and j==n-1:
        print()
        solution[i][j]=1
        for i in range(n):
            for j in range(n):
                print(solution[i][j],end=" ")
            print()
        solution[i][j]=0
        return
    if i<0 or j<0 or i>=n or j>=n or maze[i][j]==0 or solution[i][j]==1:
        return
    solution[i][j]=1
    printPathHelper(i+1,j,maze,n,solution)
    printPathHelper(i,j+1,maze,n,solution)
    printPathHelper(i-1,j,maze,n,solution)
    printPathHelper(i,j-1,maze,n,solution)
    solution[i][j]=0
    return


def printPath(maze):
    '''
    Summary Line:
    This function helps us to take form a solution matrix and calls another method printPathHelper() on the solution matrix to print all possible paths for the mouse.

    Args:
    maze- The 2D matrix that was inputted through which the Rat has to pass
    '''
    n=len(maze)
    solution=[[0 for j in range(n)]for i in range(n)]
    printPathHelper(0,0,maze,n,solution)

if __name__ == '__main__':
    n=int(input())
    maze=[]
    for j in range(n):
        arr=[int(i) for i in input().split()]
        maze.append(arr)
        j+=1
    printPath(maze)

'''
Sample input-
4
1 1 1 1
1 1 0 1
1 0 1 1 
1 1 1 1

Illustration for the maze-
(Obstacles at positions where there is 0 in the input matrix)
                0       1       2       3
            +-------+-------+-------+-------+
            |       |       |       |       |
        0   |       |       |       |       |
            |       |       |       |       |
            +---------------+-------+-------+
            |       |       |       |       |
        1   |       |       |   x   |       |
            |       |       |       |       |
            +-------+-------+-------+-------+
            |       |       |       |       |
        2   |       |   x   |       |       |
            |       |       |       |       |
            +-------+-------+-------+-------+
            |       |       |       |       |
        3   |       |       |       |       |
            |       |       |       |       |
            +-------+-------+-------+-------+

Sample Output-
All possible paths will be printed

Time complexity- O(2^(n^2))
'''
