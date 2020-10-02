from PIL import Image
import numpy as np
import sys

# increase recursion depth
sys.setrecursionlimit(500000)

# get args
file_path = sys.argv[1]

# arrays go by rows first THEN columns
row = int(sys.argv[3])
col = int(sys.argv[2])

# get img
print('Loading image...')
img = Image.open(file_path).convert('1')

# get dimensions
width = img.size[0]
height = img.size[1]

# turn into array
arr = np.array(img)

# invert values (True values become False and vice versa)
arr = np.logical_not(arr)

# validate
if row > height or row < 0 or col > width or col < 0:
    sys.exit('Invalid coordinates!')

print(f'{file_path} successfully loaded!')


def flood_fill(arr, row, col):
    # if the coords are out of bounds
    if row >= height or col >= width or row < 0 or col < 0:
        return

    # if there is no pixel on these coords (False value)
    if arr[row][col] == False:
        # fill it in (invert)
        arr[row][col] = True
    else:
        return

    # if there is no pixel on the coords surrounding this pixel, call recursively
    if arr[row-1][col] == False:
        flood_fill(arr, row-1, col)
    if arr[row][col+1] == False:
        flood_fill(arr, row, col+1)
    if arr[row+1][col] == False:
        flood_fill(arr, row+1, col)
    if arr[row][col-1] == False:
        flood_fill(arr, row, col-1)


# call the method
print('Starting flood fill...')
flood_fill(arr, row, col)

# invert values (True values become False and vice versa)
arr = np.logical_not(arr)

# converts to RGB image and saves
result = Image.fromarray(arr.reshape(width, height).astype('uint8')*255)
result.save('result.png')

# print final message
print(f'{file_path} successfully flood filled at {col}, {row}! Check result.png!')
