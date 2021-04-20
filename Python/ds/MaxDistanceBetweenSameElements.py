# Your task is to Complete this function
# functtion should return an integer
def maxDistance2(arr, n):
    # t.c  = O(n^2)
    max1=0
    for i in range(0,n):
        for j in range(n-1,-1,-1):
            if arr[i] == arr[j]:
                # print(i,j)
                val = j-i
                if val>max1:
                    max1=val
    return max1



def maxDistance(arr, n):
    arr2 = [0*x for x in range(n)]
    # print(arr2)
    dict1 =  {}
    res = 0
    for i in range(n):
        if arr[i] not in dict1.keys():
            dict1[arr[i]] = i
        else:
            first_occ = dict1[arr[i]]
            diff = i - first_occ
            try:

                if diff >= arr2[arr[i]]:
                    arr2[arr[i]] = diff
            except:
                pass
            if diff>=res:
                res = diff

    # print(arr2)
    return res


#{
#  Driver Code Starts
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(maxDistance(arr, n))



# } Driver Code Ends