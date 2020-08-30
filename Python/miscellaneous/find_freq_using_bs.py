def get_index(arr: list, N: int, key: int, search_left: bool) -> int:
    """Returns left-most or right-most index of key in a sorted list arr. 

    This function takes an list and a key and finds 
    the left most or right most index of that key in the list depending
    on the value of search_left flag using binary search technique.

    Parameters
    -------------
        arr         : The list in which search is to be performed
        N           : size of the list
        key         : The element whose frequency is to be calculated
        search_left : To indicate search direction 

    Returns
    -------------
        index       : The left-most or right-most index 
    """
    # initializing necessary variables
    left = 0
    right = N - 1
    found_index = -1

    # Performing binary search using search_left flag
    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == key:
            found_index = mid
            if search_left:
                right = mid - 1
            else:  # search right
                left = mid + 1

        elif arr[mid] > key:
            right = mid - 1

        else:
            left = mid + 1

    return found_index


def get_freq_using_bs(arr, N, key):
    """ Returns frequency of Key in arr using Binary Search

    This function internally calls get_index() function to 
    find left most and right most index of a key and calculates
    total occurence.

    Parameters
    -------------
        arr     : The list in which search is to be performed
        N       : size of the list
        key     : The element whose frequency is to be calculated

    Returns
    -------------
        -1      : if Key is not present
        count   : The frequency of key
    """

    # Sorting inorder to use binary search
    # use any stable sorting algorithm
    arr.sort()

    # finding first and last occurrence of key
    first_occurence = get_index(arr, N, key, True)
    last_occurence = get_index(arr, N, key, False)

    if (first_occurence, last_occurence) == (-1, -1):  # If key not present
        return -1
    # else returning the count
    return last_occurence - first_occurence + 1


# driver code
if __name__ == "__main__":
    N = int(input())
    arr = list(map(int, input().split()))
    key = int(input())
    freq = get_freq_using_bs(arr, N, key)

    if freq == -1:  # Key not found
        print("Ocurrence of", key, "is: 0")
    else:
        print("Occurence of", key, "is:", freq)

# Sample Test Case
# Input
# 5
# 1 4 2 3 4
# 4

# Output
# Occurrence of 4 is: 2
