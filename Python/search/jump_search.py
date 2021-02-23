"""
The basic idea is to check fewer elements,
by jumping ahead by fixed steps.
NOTE:-Works only sorted arrays.
Time Complexity : O(√n)
Auxiliary Space : O(1)
SAMPLE INPUT line 1   1 2 3 4 5 6 7 8 9 10
SAMPLE INPUT line 2   5
SAMPLE OUTPUT     4
"""
import math


# main function
def jump_search(arr, search):
    """Takes in a sorted array arr and a value to search for"""
    interval = int(math.sqrt(len(arr)))
    for i in range(0, len(arr), interval):
        if arr[i] < search:
            low = i
        elif arr[i] == search:
            return i
        else:
            break
    l_index = [e for e, i in enumerate(arr[low:low+interval]) if i == search]
    if l_index[0]:
        return low + l_index[0]
    return "Not Found"


# driver code
if __name__ == "__main__":
    ary = list(map(int, input("ENTER A SORTED ARRAY").split()))
    val = int(input("ENETER THE VALUE TO SEARCH"))
    ans = jump_search(ary, val)
    print(ans)
