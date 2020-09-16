# Take input for class TestCase
print("Enter Number of TestCase :")
t = int(input())
# Iterate till t TestCase
for item in range(t):
    # Take input for str1 and str2
    print("\nEnter value for str1 and str2 :")
    str1, str2 = input().split()
    # Base Cases
    i = 0
    j = 0
    n = len(str1)
    m = len(str2)
    # Iterate till i and j
    # Is less than n and m
    while i < n and j < m:
        if str1[i] == str2[j]:
            i += 1
            j += 1
        else:
            j += 1
    print("\tOUTPUT\n")
    # print yes if A is a subsequence of B.
    if i == n:
        print ("YES! String1 is subsequence of String2")
    # else print No
    else:
        print ("NO! String1 is not subsequence of String2")

# Sample Input output:
# Enter Number of TestCase : 2
# Enter value for str1 and str2 :AXY YADXCP
#    OUTPUT
# NO! String1 is not subsequence of String2
# Enter value for str1 and str2 :AXY ADXCPY
#   OUTPUT
# YES! String1 is subsequence of String2
# Time Complexity:O(n)
