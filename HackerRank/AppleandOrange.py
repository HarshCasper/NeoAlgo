def countApplesAndOranges(s, t, a, b, apples, oranges):
    countapp=countorg=0
    for i in apples:
        if i+a in range(s,t+1):
            countapp+=1
    for i in oranges:
        if i+b in range(s,t+1):
            countorg+=1
    print(countapp)
    print(countorg)