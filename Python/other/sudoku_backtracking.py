
def solve(board, i=0, j=0):
        i,j = nextCell(board, i, j)
        if i == -1:
                return True
        for e in range(1,10):
                if isValid(board,i,j,e):
                        board[i][j] = e
                        if solve(board, i, j):
                                return True
                        board[i][j] = 0
        return False        

def print_board(board):
    for i in range(len(board)):
        if i % 3 ==0 and i != 0:
            print("------------------------")

        for j in range(len(board[0])):
            if j % 3 ==0 and j !=0:
                print("|",end="")

            if j == 8:
                print(board[i][j])
            else:
                print(str(board[i][j]) + " " , end="")  

def nextCell(board, i, j):
        for x in range(i,9):
                for y in range(j,9):
                        if board[x][y] == 0:
                                return x,y
        for x in range(0,9):
                for y in range(0,9):
                        if board[x][y] == 0:
                                return x,y
        return -1,-1

def isValid(board,x,y,n):
    for i in range(9):
        if board[x][i] == n or board[i][y] == n:
            return False
    new_x = x//3 * 3
    new_y = y//3 * 3
    for i in range(3):
        for j in range(3):
            if board[new_x + i][new_y + j] == n:
                return False

    return True 

if __name__ == "__main__":
    print("Enter the numbers row by row, and put 0 for empty space:")
    board = [[int(input()) for x in range (9)] for y in range(9)] 
    solve(board)  
    print_board(board)