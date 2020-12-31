"""
Purpose: To check wether it is possible for a Knight to visit each
         cell of the N*N chessboard without visiting any cell
         twice starting from (X, Y) position.

Method: Backtracking Algorithm
Intution: To visit each and every positions which are available from
          the current position and recursively repeat this until
          all the cells are covered
Worst-Case Time Complexity:  O(8^N)
Space Complexity: O(N^2)

Argument: Tupple (Current Position)
Return  : 2d Matrix (Steps of the Knight)

Note: Backtracking approch for Knight's Tour Problem is very slow
        hence use smaller number (<7) for fast result
"""

from time import time


def move_Knight(n, pos, move, ans, step):
    x, y = pos

    # Base Case
    if step == n * n:
        return ans
    for i in move:
        r = x + i[0]
        c = y + i[1]
        if 0 <= r < n and 0 <= c < n and not ans[r][c]:
            ans[r][c] = step + 1
            temp = move_Knight(n, (r, c), move, ans, step + 1)
            if temp is not False:
                return temp
            ans[r][c] = 0
    return False


def Knight_Tour(n, pos):
    x, y = pos

    # All valid moves that a Knight can make
    move = [[2, 1], [2, -1], [-2, 1], [-2, -1],
            [1, 2], [1, -2], [-1, 2], [-1, -2]]

    # To keep a track of already visited cells and
    # Answer Matrix
    answer = [[0]*n for i in range(n)]

    # To mark (X, Y) cell as visited
    answer[x][y] = 1

    return move_Knight(n, pos, move, answer, 1)


# ------------------------DRIVER CODE ------------------------

if __name__ == "__main__":

    # Input the initial Position of the Knight
    N = int(input("Enter the size of the Chessboard: "))
    X, Y = map(int, input("Enter Initial Position of the Knight: ").split())
    start = time()
    ans_mat = Knight_Tour(N, (X-1, Y-1))
    if ans_mat is False:
        print("Knight's Tour form the given initial position is not possible")
    else:
        print("The desired Knight's Tour :")
        for i in ans_mat:
            print("\t\t", *i)
    print("Time taken: ", time()-start)

"""
Sample Input / Output

Enter the size of the Chessboard: 5
Enter the Initial Position of the Knight: 1 1
The desired Knight's Tour :
                1 6 15 10 21
                14 9 20 5 16
                19 2 7 22 11
                8 13 24 17 4
                25 18 3 12 23
Time taken:  0.6455559730529785


Enter the size of the Chessboard: 6
Enter the Initial Position of the Knight: 1 1
The desired Knight's Tour :
                 1 12 21 28 7 10
                 22 29 8 11 20 27
                 13 2 23 4 9 6
                 30 35 32 17 26 19
                 33 14 3 24 5 16
                 36 31 34 15 18 25
Time taken:  23.60681414604187

"""
