#author : @anushkrishnav
def makeAnagram(a,b):
    count=0
    a,b=list(a),list(b)
    for i in a:
        if i in b:
            b.remove(i)
            count+=1
    return len(a)+len(b)-count
