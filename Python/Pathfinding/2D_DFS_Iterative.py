"""
Depth First Search: Its a graph traversal technique which uses
        stack data-structure fo its implementation. We extract the
        current node from the top of the stack and traverse its adjacent
        nodes. If not visited, we put the node at the top of the stack
        mark it as visited.
Purpose: Given a binary matrix of N*M order where 0 is the wall and 1 is the way.
        Find the shortest distance from a source cell to a destination cell,
        traversing through limited cells only. Also, you can move only
        up, down, left and right. If found then print the distance and
        path in separate lines, else return -1.

Method : Depth-First Search
Intuition : As we know stack is used for DFS.

        1. Initialize stack.
        2. Initialize 2d boolean array, the same size as the original array.
            This will help us in avoiding traversal to go in loops.
        3. Push the first element position (element at (0,0), row=0, column=0) to stack
        4. Now until the stack is not empty
            - pop the position from the stack. Split it by “,” to get the row
                index and column index. and check if indexes are within the range of
                given matrix and marked false in the visited[] array, if not then ignore
                it and pop the next position from the stack. If indexes are valid and not
                visited then print the element.
            - Mark the element in the visited array.
            - Add the element positions from left, right, down and up from the current
                element into the stack.
        5. Repeat this until the destination cell is found or all cells are visited

Time Complexity:   O(N*M)
Space Complexity: O(N*M)

Argument: 2-d list, tuple, tuple (Maze, Source, Destination)
Return  : Integer, String          (Distance, Path)

"""
# Main DFS function using recursion

def DFS(maze, src, des, way=1):

    # Dimention of the maze
    n = len(maze)
    m = len(maze[0])

    # To keep a track of visited nodes, also mark source as visited
    visited = [[False] * m for i in range(n)]
    visited[src[0]][src[1]] = True

    # All possible moves from a cell
    moves = {(1, 0): 'D', (-1, 0): 'U', (0, 1): 'R', (0, -1): 'L'}

    # Initilize the stack data structure and parent dictionary
    stack = [(src[0], src[1], 0)]
    parent = {}

    # Until the stack is empty, run the loop
    while stack:
        x, y, cost = stack.pop()

        # If the node is destination, calculate the path and return
        if (x, y) == des:
            path = ''
            dis = cost
            cur = (x, y)

            # Calculate the path by backtracking with the parent dict
            while cur != src:
                prev_move = parent[cur]
                m = (cur[0] - prev_move[0], cur[1] - prev_move[1])
                path += moves[m]
                cur = prev_move

            # Return the distance and path
            return dis, path[::-1]

        # For a given node check each possible move
        for i in moves.keys():
            r = x + i[0]
            c = y + i[1]

            # If the next node inside the maze , has a way and not yet visited
            # then mark it visited and push it in the stack
            if 0 <= r < n and 0 <= c < m and maze[r][c] == way and not visited[r][c]:
                visited[r][c] = True
                parent[(r, c)] = (x, y)
                stack.append((r, c, cost + 1))

    # If the stack is empty, there is no way possible, return False
    return False


def Find_Path(maze, src, des):

    # Base Case: If there is no way from the source, returnn False
    if(maze[src[0]][src[1]] != 1):
        return False

    return DFS(maze, src, des)

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
