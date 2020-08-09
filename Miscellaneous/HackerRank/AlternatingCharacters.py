def alternatingCharacters(s):
    count=0
    lent=len(s)-1
    for i in range(0,lent):
        if s[i]==s[i+1]:
            count+=1
    return count
