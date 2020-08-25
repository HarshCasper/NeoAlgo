'''Program to solve the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.'''
class QueenChessBoard:
    def __init__(self, size):
        self.size = size
        self.columns = []
        self.count = 0
 
    def place_in_next_row(self, column):
        '''Tries to place the queen in the next column of the current row'''
        self.columns.append(column)
 
    def remove_in_current_row(self):
        '''Removes the queen in the current column of the current row'''
        return self.columns.pop()
 
    def is_this_column_safe_in_next_row(self, column):
        '''Checks if the current column is safe in the next row and returns either True or False'''
        row = len(self.columns)
 
        # check column
        for queen_column in self.columns:
            if column == queen_column:
                return False
 
        # check diagonal
        for queen_row, queen_column in enumerate(self.columns):
            if queen_column - queen_row == column - row:
                return False
 
        # check other diagonal
        for queen_row, queen_column in enumerate(self.columns):
            if ((self.size - queen_column) - queen_row
                == (self.size - column) - row):
                return False
 
        return True
 
    def display(self):
        '''Displays the information about current chessboard before printing it.'''
        self.count += 1
        print(f"__Solution {self.count}__\nCoordinates: ", end = '')
        for row in range(self.size):
            for column in range(self.size):
                if column == self.columns[row]:
                    print(f'({row+1}, {column+1})', end = '')
        print('\nBoard: ')
        
        for row in range(self.size):
            print('       ', end = '' )
            for column in range(self.size):
                if column == self.columns[row]:
                    print('Q', end=' ')
                else:
                    print('.', end=' ')
            print("")
         
 
def solve_queen(size):
    '''Displays a chessboard for each possible configuration of placing n queens on an n x n chessboard and prints the number of such configurations.'''
    board = QueenChessBoard(size)
    number_of_solutions = 0
    row = 0
    column = 0
    
    # iterate over rows of board
    while True:
        # place queen in next row
        while column < size:
            if board.is_this_column_safe_in_next_row(column):
                board.place_in_next_row(column)
                row += 1
                column = 0
                break
            else:
                column += 1
 
        if (column == size or row == size):
            if row == size:
                board.display()
                print()
                number_of_solutions += 1
 
                board.remove_in_current_row()
                row -= 1
 
            # now backtrack
            try:
                prev_column = board.remove_in_current_row()
            except IndexError:
                break
            row -= 1
            column = 1 + prev_column
    print('Number of solutions:', number_of_solutions,'\n')

if (__name__ == "__main__"):
	choice = (input('Do you want to see an example first? (Y/N) '))
	if(choice == 'y' or choice == 'Y'):
		print('\nNumber of Queen: 3') 
		solve_queen(3)
		print('\nNumber of Queen: 4') 
		solve_queen(4)
		print('\nNow try it on your own...')
	n = int(input('\nEnter the Number of Queen: '))
	solve_queen(n)