# NOTE:-Works only sorted arrays.
import math

# main function
def jump_search(arr, search):
    """Takes in a sorted array arr and a value to search for"""
    flag = 0
    interval = int(math.sqrt(len(arr)))
    for i in range(0, len(arr), interval):
        if arr[i] > search:
            chunk = i
            flag = 1
            break
        if arr[i] == search:
            return i
    if flag == 0:
        c = i
        for j in arr[i:]:
            if j == search:
                return c
            c += 1
    else:
        arr_ls = arr[chunk - interval : chunk]
        ind = [i for i, d in enumerate(arr_ls) if d == search]
        return chunk - interval + ind[0]


# driver code
if __name__ == "__main__":
    ary = list(map(int, input().split()))
    val = int(input())
    res = jump_search(ary, val)
    print(res)

"""
Time Complexity : O(√n)
Auxiliary Space : O(1)
SAMPLE INPUT line 1   1 2 3 4 5 6 7 8 9 10
SAMPLE INPUT line 2   5
SAMPLE OUTPUT     4
"""
