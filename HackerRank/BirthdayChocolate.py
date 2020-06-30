def birthday(s, d, m):
    count=0
    for i in range(len(s)-m+1):
        k=i+m
        if sum(s[i:k])==d:
            count+=1
    return count 