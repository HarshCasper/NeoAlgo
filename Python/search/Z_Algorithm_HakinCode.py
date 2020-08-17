# Function to implement the filling of Zarray
def ZA(strn, ZArr):
    n = len(strn)
    Left = 0
    Right = 0
    k = 0
    for i in range(1, n):
        if i > Right:
            Left = i
            Right = i
            while (Right < n) and (strn[Right-Left] == strn[Right]):
                Right += 1
            ZArr[i] = Right-Left
            Right -= 1

        else:
            k = i-Left
            if ZArr[k] < (Right+1-i):
                ZArr[i] = ZArr[k]
            else:
                Left = i
                while (Right < n) and (strn[Right-Left] == strn[Right]):
                    Right += 1
                ZArr[i] = Right-Left
                Right -= 1


# Search Process
txt = input("Enter Text : ")
pat = input("Enter pattern : ")
strn = pat + "$" + txt
l = len(strn)
z = [0] * l
ZA(strn, z)
for i in range(l):
    if z[i] == len(pat):
        print("Pattern found at index : "+str(i - len(pat) - 1))
