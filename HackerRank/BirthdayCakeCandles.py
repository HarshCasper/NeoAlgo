def birthdayCakeCandles(ar):
    count=0
    ar.sort()
    le=len(ar)
    maxv=ar[le-1]
    for i in ar:
        if i==maxv:
            count+=1
    print(count)
