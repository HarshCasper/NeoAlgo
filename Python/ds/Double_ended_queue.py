# Import collections module:
import collections

# Initialize deque:
dq = collections.deque([4, 5, 6])
print("Initial: ", dq)


#INSERTION METHODS
# Append to the right:
dq.append(7)
print("Append 7 to the right: ", list(dq))

# Append to the left:
dq.appendleft(3)
print("Append 3 to the left: ", list(dq))

# Append multiple values to right:
dq.extend([8, 9, 10])
print("Append 8, 9 and 10 to the right: ", list(dq))

# Append multiple values to left:
dq.extendleft([1, 2])
print("Append 2 and 1 to the left: ", list(dq))

# Insert -1 at index 5
dq.insert(5, -1)
print("Insert -1 at index 5: ", list(dq))


#DELETION METHODS
# Pop element from the right end:
dq.pop()
print("Remove element from the right: ", list(dq))

# Pop element from the left end:
dq.popleft()
print("Remove element from the left: ", list(dq))

# Remove -1:
dq.remove(-1)
print("Remove -1: ", list(dq))


#MISCELLANEOUS METHODS
# Count the number of times 5 occurs:
i = dq.count(5)
print("Count the number of times 5 occurs: ", i)

# Return index of '7' if found between index 4 and 6:
i = dq.index(7, 4, 6)
print("Search index of number 7 between index 4 and 6: ", i)

# Rotate the deque three times to the right:
dq.rotate(3)
print("Rotate the deque 3 times to the right: ", list(dq))

# Reverse the whole deque:
dq.reverse()
print("Reverse the deque: ", list(dq))


'''
OUTPUT:

Initial:  deque([4, 5, 6])
Append 7 to the right:  [4, 5, 6, 7]
Append 3 to the left:  [3, 4, 5, 6, 7]
Append 8, 9 and 10 to the right:  [3, 4, 5, 6, 7, 8, 9, 10]
Append 2 and 1 to the left:  [2, 1, 3, 4, 5, 6, 7, 8, 9, 10]
Insert -1 at index 5:  [2, 1, 3, 4, 5, -1, 6, 7, 8, 9, 10]
Remove element from the right:  [2, 1, 3, 4, 5, -1, 6, 7, 8, 9]
Remove element from the left:  [1, 3, 4, 5, -1, 6, 7, 8, 9]
Remove -1:  [1, 3, 4, 5, 6, 7, 8, 9]
Count the number of times 5 occurs:  1
Search index of number 7 between index 4 and 6:  5
Rotate the deque 3 times to the right:  [7, 8, 9, 1, 3, 4, 5, 6]
Reverse the deque:  [6, 5, 4, 3, 1, 9, 8, 7]
'''