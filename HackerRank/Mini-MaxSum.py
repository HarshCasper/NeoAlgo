def miniMaxSum(arr):
    arr.sort()
    maxsum=minsum=0
    le=int(len(arr))
    for i in range(0,le):
        if i==0:
            continue
        else:
            maxsum+=arr[i]
    for i in range(0,le):
        if i==le-1:
            continue
        else:
            minsum+=arr[i]
    return (str(minsum)+' '+str(maxsum))