"""
Purpose: Given a binary matrix of N*M order where 0 is the wall and 1 is way.
        Find the shortest distance from a source cell to a destination cell,
        traversing through limited cells only. Also you can move only
        up, down, left and right. If found then print the distance and
        path in separate lines, else return -1.
"""

from heapq import heappop, heappush

# Manhattan Distance for heuristic functionn


def heuristic_function(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return abs(x1 - x2) + abs(y1 - y2)


def Astar(maze, src, des, way=1):

    # Base Case: If there is no way from the source, returnn False
    if(maze[src[0]][src[1]] != 1):
        return False

    # Dimention of the maze
    n = len(maze)
    m = len(maze[0])

    hp = []
    count = 0
    x, y = src

    # To keep a track of visited nodes, also mark source as visited
    visited = [[False] * m for i in range(n)]
    visited[x][y] = True

    # All possible moves from a cell
    moves = {(1, 0): 'D', (-1, 0): 'U', (0, 1): 'R', (0, -1): 'L'}
    parent = {}

    # Initilize the heap with the source cell
    heappush(hp, [0, count, src])

    # Initilze the G_score for each node to infinity
    # And G_score of source is 0
    g_score = [[float('inf')] * m for i in range(n)]
    g_score[x][y] = 0

    # Initilze the F_score for each node to infinity
    # And F score of source is 1
    # F_source = G_score + heuristic function
    f_score = [[float('inf')] * m for i in range(n)]
    f_score[x][y] = 1

    while hp:
        cur_pos = heappop(hp)[2]
        # print(cur_pos)
        xx, yy = cur_pos

        if cur_pos == des:
            path = ''

            # Calculate the path by backtracking with the parent dict
            while cur_pos != src:
                print(cur_pos)
                prev_move = parent[cur_pos]
                m = (cur_pos[0] - prev_move[0], cur_pos[1] - prev_move[1])
                path += moves[m]
                cur_pos = prev_move

            # Return the distance and path
            return len(path), path[::-1]

        for i in moves.keys():
            r = xx + i[0]
            c = yy + i[1]

            # If the next node inside the maze , has a way and not yet visited
            # then mark it visited and push it in the queue
            if 0 <= r < n and 0 <= c < m and maze[r][c] == way and not visited[r][c]:
                temp = g_score[xx][yy] + 1
                if temp < g_score[r][c]:
                    parent[(r, c)] = (xx, yy)
                    g_score[r][c] = temp

                    # F_source = G_score + heuristic function
                    f_score[r][c] = temp + heuristic_function(des, (r, c))

                    count += 1
                    heappush(hp, [f_score[r][c], count, (r, c)])
                    visited[r][c] = 1

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
    ans = Astar(maze, src, des)

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
1 0 0 0 1
1 1 1 1 1
Enter the Source cell: 0 0
Enter the Destination cell: 4 4
Disance=  8
Path:  DDDDRRRR


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

