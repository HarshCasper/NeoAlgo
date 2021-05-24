"""
Purpose: Given a binary matrix of N*M order where 0 is the wall and 1 is the way.
        Find the shortest distance from a source cell to a destination cell,
        traversing through limited cells only. Also, you can move only
        up, down, left and right. If found then print the distance and
        path in separate lines, else return -1.

"""
# Main DFS function using recursion


def DFS(maze, Dim, cur_pos, des, visited, path, moves):
    x, y = cur_pos
    n, m = Dim

    # Base case: if the current position is the destination, return the path
    if cur_pos == des:
        return path

    # Check for each possible move from a possition
    for i in moves.keys():
        r = x + i[0]
        c = y + i[1]

        # If the next node inside the maze , has a way and not yet visited
        # then mark it visited, add the path and recursively call DFS()
        # Function from that position
        if 0 <= r < n and 0 <= c < m and maze[r][c] == 1 and not visited[r][c]:
            visited[r][c] = True
            path += moves[i]
            temp = DFS(maze, Dim, (r, c), des, visited, path, moves)

            # If the path is found, simply return path
            if temp:
                return temp

            # If the path is not found, pop the path
            path.pop()

    # If no path from the current node is possible, return False
    return False


def Find_Path(maze, src, des):

    # Base Case: If there is no way from the source, returnn False
    if(maze[src[0]][src[1]] != 1):
        return False

    # Dimention of the maze
    n = len(maze)
    m = len(maze[0])

    # To keep a track of visited nodes, also mark source as visited
    visited = [[False] * m for i in range(n)]
    visited[src[0]][src[1]] = True

    # All possible moves from a cell
    moves = {(1, 0): 'D', (-1, 0): 'U', (0, 1): 'R', (0, -1): 'L'}

    path = DFS(maze, (n, m), src, des, visited, [], moves)

    # if the path is not found, return False
    if path is False:
        return False

    return len(path), "".join(path)

# --------------------------------DRIVER CODE ---------------------------------


if __name__ == "__main__":

    N, M = map(int, input("Enter the Dimension of the maze:- ").split())
    print("Enter the Maze: ")
    maze = []

    # Input the Maze
    for _ in range(N):
        maze.append([int(i) for i in input().split()])

    src = tuple(map(int, input("Enter the Source cell: ").split()))
    des = tuple(map(int, input("Enter the Destination cell: ").split()))
    ans = Find_Path(maze, src, des)

    # If ans is false, i.e. no way is possible, else print distance and path
    if ans is False:
        print("No Path exists between", src, "and", des)
    else:
        dist = ans[0]
        path = ans[1]
        print("Disance= ", dist)
        print("Path: ", path)


"""

Time Complexity:   O(N*M)
Space Complexity: O(N*M)

Sample Input / Output

Enter the Dimension of the maze:- 5 5
Enter the Maze:
1 0 1 1 1
1 0 1 0 1
1 0 1 0 1
1 0 1 0 1
1 1 1 0 1
Enter the Source cell: 0 0
Enter the Destination cell: 4 4
Disance=  16
Path:  DDDDRRUUUURRDDDD


Enter the Dimension of the maze:- 5 5
Enter the Maze:
1 0 1 1 1
1 0 1 0 1
1 0 0 0 1
1 0 1 0 1
1 1 1 0 1
Enter the Source cell: 0 0
Enter the Destination cell: 4 4
No Path exists between (0, 0) and (4, 4)


Enter the Dimension of the maze:- 5 8
Enter the Maze:
1 0 1 1 1 1 1 1
1 0 1 0 0 0 0 1
1 0 1 1 1 1 0 1
1 0 0 0 0 1 0 1
1 1 1 1 1 1 0 1
Enter the Source cell: 0 0
Enter the Destination cell: 4 7
Disance=  25
Path:  DDDDRRRRRUULLLUURRRRRDDDD
"""

