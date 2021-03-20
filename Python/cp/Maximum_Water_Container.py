# Python code for maximum water Container


def maxArea(A):  # Function to find Maximum Area
    start = 0
    end = len(A) - 1
    area = 0

    while start < end:
        # Calculating the max area
        area = max(area, min(A[start], A[end]) * (end - start))

        if int(A[start]) < int(A[end]):
            start += 1
        else:
            end -= 1
    return area


# Driver code
print("Input-->")
# number of elemetns as input
size1 = int(input(" Enter the a size :\n"))
size2 = int(input(" Enter the b size :\n"))
a = []
b = []
# iterating till the range
print(" Enter the elements of a container :")
for i in range(0, size1):
    ele1 = int(input())

    a.append(ele1)  # adding the element
print(" Enter the elements of b container :")
for j in range(0, size2):
    ele2 = int(input())

    b.append(ele2)  # adding the element
print("Output-->")
# displaying the Output
A = int(maxArea(a))
B = int(maxArea(b))
if A > B:
    print("Container a with more area contain more water i.e " + str(A))
else:
    print("Container b with more area contain more water i.e " + str(B))
"""
 Input-->
 Enter the a size : 4
 Enter the b size : 5
 Enter the elements of a container :
 1 5 4 3
 Enter the elements of b container :
 3 2 1 4 5
 Output-->
 Container b contain more water i.e 12

 Time Compelxity: O(n) where n is size of array.
 Space Complexity: O(1).
 No extra space is required, so space complexity is constant
"""
