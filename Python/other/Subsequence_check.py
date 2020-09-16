# Take input for class TestCase
print("Enter Number of TestCase :")
testcase= int(input())
# Iterate till TestCase
for item in range(testcase):
    # Take input for str1 and str2
    print("\nEnter value for str1 and str2 :")
    str1, str2 = input().split()
    # Base Cases
    index1 = 0
    index2 = 0
    len1 = len(str1)
    len2 = len(str2)
    # Iterate till index1 and index2
    # Is less than len1 and len2
    while index1 < len1 and index2 < len2:
        if str1[index1] == str2[index2]:
            index1 += 1
            index2 += 1
        else:
            index2 += 1
    print("\tOUTPUT\n")
    # print yes if A is a subsequence of B.
    if index1 == len1:
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
