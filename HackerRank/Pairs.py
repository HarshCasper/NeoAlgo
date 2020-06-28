import math
def pairs(k, arr):
    arr=set(arr)
    brr=set(x+k for x in arr)
    count=arr.intersection(brr)
    return count.__len__()