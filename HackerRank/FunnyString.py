def funnyString(s):
    a=[]
    b=[]
    original=list(s)
    for i in original:
        a.append(ord(i))
    for i in range(len(a)-1):
        b.append(abs(a[i]-a[i+1]))
    if b==b[::-1]:
        return "Funny"
    else:
        return "Not Funny"