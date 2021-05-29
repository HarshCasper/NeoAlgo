"""
Purpose: Given a binary matrix of N*M order where 0 is the wall and 1 is way.
        Find the shortest distance from a source cell to a destination cell,
        traversing through limited cells only. Also you can move only
        up, down, left and right. If found then print the distance and
        path in separate lines, else return -1.

"""
from collections import deque


# Main BFS function to find the path
def BFS(maze, src, des, way=1):

    # Base case: is source has no way, return false
    if maze[src[0]][src[1]] != way:
        return False

    # Dimeention of the matrix and a queue is initlized with the source vertex
    n = len(maze)
    m = len(maze[0])
    queue = deque([(src[0], src[1], 0)])

    # To keep a track of the visdited nodes and parents
    visited = [[False] * m for i in range(n)]
    parent = {}

    # All possible moves from a cell
    move = {(1, 0): 'D', (-1, 0): 'U', (0, 1): 'R', (0, -1): 'L'}

    while queue:

        # Extract the left most node from the queue
        v = queue.popleft()

        # If the node is destination, calculate the path and return
        if (v[0], v[1]) == des:
            path = ''
            dis = v[2]
            cur = (v[0], v[1])

            # Calculate the path by backtracking with the parent dict
            while cur != src:
                prev_move = parent[cur]
                m = (cur[0] - prev_move[0], cur[1] - prev_move[1])
                path += move[m]
                cur = prev_move

            # Return the distance and path
            return dis, path[::-1]

        # For a given node check each possible move
        for i in move.keys():
            r = v[0] + i[0]
            c = v[1] + i[1]

            # If the next node inside the maze , has a way and not yet visited
            # then mark it visited and push it in the queue
            if 0 <= r < n and 0 <= c < m and maze[r][c] == way and not visited[r][c]:
                visited[r][c] = True
                parent[(r, c)] = (v[0], v[1])
                queue.append((r, c, v[2] + 1))

    # If the queue is empty, there is no way possible, return False
    return False


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
    ans = BFS(maze, src, des)

    # If ans is false, i.e. no way is possible, else print distance and path
    if ans is False:
        print("No Path exists between", src, "and", des)
    else:
        dist = ans[0]
        path = ans[1]
        print("Disance= ", dist)
        print("Path: ", path)


"""

Time Compexity:   O(N*M)
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

