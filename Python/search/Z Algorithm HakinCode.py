def zalgo(txt, pat):
    lis = []
    strn = ""

    for i in range(0, len(txt)-len(pat)):
        strn = txt[i:i+len(pat)]

        c = 0
        for j in range(0, len(pat)):
            if pat[j] == strn[j]:
                c += 1

        if c == len(pat):
            lis.append(i)
    return lis

# Search Process


txt = input("Enter Text : ")
pat = input("Enter pattern : ")
res = zalgo(txt, pat)
for i in res:
    print("The pattern is present at : "+str(i))
