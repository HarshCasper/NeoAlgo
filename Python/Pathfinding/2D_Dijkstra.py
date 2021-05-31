"""
Purpose: Given a binary matrix of N*M order where 0 is the wall and 1 is the way.
        Find the shortest distance from a source cell to a destination cell,
        traversing through limited cells only. Also, you can move only
        up, down, left and right. If found then print the distance and
        path in separate lines, else return -1.

"""
from heapq import heappop, heappush


def Dijkstra(maze, src, des, way=1):

    # Dimention of the maze
    n = len(maze)
    m = len(maze[0])

    # To keep a track of visited nodes, also mark source as visited
    visited = [[False] * m for i in range(n)]
    distance = [[float('inf')] * m for i in range(n)]

    # All possible moves from a cell
    moves = {(1, 0): 'D', (-1, 0): 'U', (0, 1): 'R', (0, -1): 'L'}

    x, y = src
    distance[x][y] = maze[0][0]
    visited[x][y] = True

    cur_pos = [(x, y)]
    parent = {}

    while True:
        boo = False
        hp = []
        for i in cur_pos:
            x, y = i

            # If the node is destination, calculate the path and return
            if (x, y) == des:
                path = ''
                dis = distance[x][y]
                cur = (x, y)

                # Calculate the path by backtracking with the parent dict
                while cur != src:
                    prev_move = parent[cur]
                    m = (cur[0] - prev_move[0], cur[1] - prev_move[1])
                    path += moves[m]
                    cur = prev_move

                # Return the distance and path
                return dis, path[::-1]

            for j in moves.keys():
                r = x + j[0]
                c = y + j[1]

                # If the next node inside the maze , has a way and not yet visited
                # then mark it visited and push it in the queue
                if 0 <= r < n and 0 <= c < m and maze[r][c] == way and not visited[r][c]:
                    visited[r][c] = True
                    parent[(r, c)] = (x, y)
                    heappush(hp, (distance[x][y] + 1, r, c))

        while hp:
            dis, x, y = heappop(hp)
            if(distance[x][y] > dis):
                boo = True
                distance[x][y] = dis
                cur_pos.append((x, y))

        if not boo:
            break

    return False


def Find_Path(maze, src, des):

    # Base Case: If there is no way from the source, returnn False
    if(maze[src[0]][src[1]] != 1):
        return False

    return Dijkstra(maze, src, des)

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

Time Complexity:  O(N*M)
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

