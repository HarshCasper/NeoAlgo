# The basic idea is to check fewer elements by jumping ahead by fixed steps or skipping some elements in place of searching all elements.
# Time Complexity : O(√n)
# Auxiliary Space : O(1)

import math
#main function
def jump_search(arr,search):
    flag = 0
    interval = int(math.sqrt(len(arr)))
    for i in range(0,len(arr),interval):
        if arr[i] >  search:
            chunk = i
            flag = 1
            break
        if arr[i] ==  search:
            return i
    if flag==0:
        c=i
        for j in arr[i:]:
            if j==search:
                return c
            c+=1
    else:
        arr_ls = arr[chunk-interval:chunk]
        ind = [i for i,d in enumerate(arr_ls) if d==search]
        return chunk-interval+ind[0]
#driver code
arr = list(map(int,input().split()))
#get the item to be searched
val=int(input())
res = jump_search(arr, val)
print(res) 
# NOTE:-Works only sorted arrays.
