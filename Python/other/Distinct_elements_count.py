# Python program to count distinct elements in every window of size k
from collections import defaultdict


def Distinct_count(array, window):

    # Creates an empty hashmap
    hash_map = defaultdict(lambda: 0)
    count_distinct = 0

    for i in range(window):
        if hash_map[array[i]] == 0:
            count_distinct += 1
        hash_map[array[i]] += 1

    # Print count of first window
    print(count_distinct)

    # Traverse through the remaining array
    for i in range(window, size):
        # If there was only one occurrence, reduce distinct count.
        if hash_map[array[i - window]] == 1:
            count_distinct -= 1
        hash_map[array[i - window]] -= 1

    # increment distinct element count
        if hash_map[array[i]] == 0:
            count_distinct += 1
        hash_map[array[i]] += 1

        # Print count of current window
        print(count_distinct)


size = int(input("Enter Size: "))
array = [int(i) for i in input("Enter Array: ").split()]
window = int(input("Enter window: "))
Distinct_count(array, window)

'''
Sample I/O:
Input:
Enter Size: 7
Enter Array: 1 2 3 4 2 3 4
Enter window: 4

Output:
4
3
3
3

Time Complexity: O(size)
Space Complexity: O(Size)
'''
