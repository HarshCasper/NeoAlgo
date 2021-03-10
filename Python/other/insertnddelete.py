def lcs(str1, str2, m, n):

    if m == 0 or n == 0:
        return 0
    
    elif str1[m - 1] == str2[n - 1]:
        return lcs(str1, str2, m - 1, n - 1) + 1

    else:
        return max(lcs(str1, str2, m, n - 1), lcs(str1, str2, m - 1, n))
 
 
def DelAndInsert(str1, str2):
    a = len(str1)
    b = len(str2)
    length = lcs(str1, str2, a, b)
    print("Number of deletions = ", a - length)
    print("Number of insertions = ",b - length)
 
str1 = input("Enter the string you want to convert from ")
str2 = input("Enter the string you want to convert to ")
 
DelAndInsert(str1, str2)
 
