"""
    Takes an array of integers sorted in ascending order, a target value and
    finds the starting and ending position of a given target value.

    Approach - Binary Search
"""


def Binary_Search(nums, target, flag=0):
    """
    Binary search follows divide and conquer approach in which,
    the list is divided into two halves and the item is compared 
    with the middle element of the list. If the match is found then,
    the location of middle element is returned otherwise, 
    we search into either of the halves depending upon the result produced through the match.

    - Returns the initial found index position of the target value if flag is set to 0 (Default)
    - Returns Starting Positon of the target value if flag is set to -1
    - Returns Ending Positon of the target value if flag is set to 1 

    If the target is not present in the list of numbers, -1 is returned irrespective of the flag value

    # Time Complexity: O(log n)
    # Space Complexity: O(1)
    """
    pos = -1
    low, high = 0, len(nums) - 1
    while low <= high:
        mid = (low + high) // 2
        if nums[mid] == target:  # Checking if target is at mid position
            pos = mid
            if flag == -1:
                high = mid - 1
            elif flag == 1:
                low = mid + 1
            else:
                return pos
        elif nums[mid] < target:  # Checking if target is greater than the number at mid position
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


# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]

# Input: nums = [5,7,7,8,8,10], target = 6
# Output: [-1,-1]

# Input: nums = [], target = 0
# Output: [-1,-1]
