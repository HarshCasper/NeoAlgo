# Function to check if a word exists in a 2D board of characters.
# Uses backtracking to explore possible paths in the grid.

def word_search(board, word):
   
    rows, cols = len(board), len(board[0])
    
    # Backtracking function to explore each cell in the board
    def backtrack(r, c, i):
        # If we have matched all characters in the word
        if i == len(word):
            return True
        
        # Check if the current position is out of bounds or does not match the current character
        if r < 0 or c < 0 or r >= rows or c >= cols or board[r][c] != word[i]:
            return False
        
        # Temporarily mark the current cell as visited
        temp = board[r][c]
        board[r][c] = '#'  # mark as visited
        
        # Explore all possible directions: down, up, right, left
        found = (backtrack(r + 1, c, i + 1) or
                 backtrack(r - 1, c, i + 1) or
                 backtrack(r, c + 1, i + 1) or
                 backtrack(r, c - 1, i + 1))
        
        # Unmark the current cell to backtrack
        board[r][c] = temp  # unmark
        return found
    
    # Iterate through each cell in the board
    for r in range(rows):
        for c in range(cols):
            # Start backtracking from each cell
            if backtrack(r, c, 0):
                return True  # Word found in the board
    
    return False  # Word not found in the board

# Sample Usage:
# Input: 2D board and a word to search
# Example board:
# [
#     ['A', 'B', 'C', 'E'],
#     ['S', 'F', 'C', 'S'],
#     ['A', 'D', 'E', 'E']
# ]
# Example word: "ABCCED"

# Input from user
rows = int(input("Enter the number of rows in the board: "))
cols = int(input("Enter the number of columns in the board: "))

board = []
print("Enter the board row by row (characters without spaces):")
for _ in range(rows):
    row = list(input().strip())
    board.append(row)

word = input("Enter the word to search for: ")

# Call the function and print the result
if word_search(board, word):
    print("The word exists in the board.")
else:
    print("The word does not exist in the board.")
