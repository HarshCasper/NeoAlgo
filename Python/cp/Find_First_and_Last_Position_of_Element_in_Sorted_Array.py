"""
    Takes an array of integers sorted in ascending order, a target value and
    finds the starting and ending position of a given target value.
    We will be using Binary Search:

"""


def Binary_Search(nums, target, flag=0):
    """
    - Returns the initial found index position of the target value
      if flag is set to 0 (Default)
    - Returns Starting Positon of the target value if flag is set to -1
    - Returns Ending Positon of the target value if flag is set to 1

    If the target is not present in the list of numbers,
    -1 is returned irrespective of the flag value
    """
    pos = -1
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = (low + high) // 2
        if nums[mid] == target:
            # Checking if target is at mid position
            pos = mid
            if flag == -1:
                high = mid - 1
            elif flag == 1:
                low = mid + 1
            else:
                return pos
        elif nums[mid] < target:
            # Checking if target is greater than the number at mid position
            low = mid + 1
        else:
            high = mid - 1
    return pos


def search_range(nums, target):
    """
    Performs Binary Search on nums and returns a list of two elements:
    - [<First Positon of the target elemet>, <Last Positon of the target elemet>]

    Returns [-1, -1] if the target not exists in the list of numbers
    """
    starting_position = Binary_Search(nums, target, -1)
    ending_position = -1
    if starting_position != -1:
        ending_position = Binary_Search(nums, target, 1)
    return [starting_position, ending_position]


if __name__ == "__main__":
    list_of_nums = [int(x) for x in input().split()]
    key = int(input())
    print(search_range(list_of_nums, key))

# Sample Input-Output:
# Input 1:
# 5 7 7 8 8 10
# 8
# Output 1: [3,4]
# The target 8 is found first at index 3
# and last at index 4 in the list of numbers

# Input 2:
# 5 7 7 8 8 10
# 6
# Output 2: [-1,-1]
# The target 6 is not found in the list of numbers

# Input 3:

# 0
# Output 3: [-1,-1]
# The given list of numbers is empty

# Time Complexity: O(log n)
# Space Complexity: O(1)
