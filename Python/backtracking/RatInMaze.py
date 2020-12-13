# Problem statement- given a maze of 1s with obstacles (represented by 0). We have to print all the possible paths to the end.
# Logical intuition- We have to explore all the possible paths hence our mouse will move in all four directions untill it reaches the end


# Sample input-
# 4
# 1 1 1 1
# 1 1 0 1
# 1 1 1 1 
# 1 1 1 1


def printPathHelper(i,j,maze,n,solution):
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
    n=len(maze)
    solution=[[0 for j in range(n)]for i in range(n)]
    printPathHelper(0,0,maze,n,solution)

# main
n=int(input())
maze=[]
for j in range(n):
    arr=[int(i) for i in input().split()]
    maze.append(arr)
    j+=1
printPath(maze)

# Time complexity- O(2^(n^2))
