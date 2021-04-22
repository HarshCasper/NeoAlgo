''''
This is the simple python code for finding the roots of quadratic equation.
Approach :  Enter the values of a,b,c  of the quadratic equation of the form (ax^2  bx + c )
the function quadraticRoots will calculate the Discriminant , if D is greater than 0 then it will find the roots and print them otherwise it will print Imaginary!!
'''


import math
class Solution:
    def quadraticRoots(self, a, b, c):
        d = ((b*b) - (4*a*c))
        if d<0:
            lst=[]
            lst.append(-1)
            return lst
        D = int(math.sqrt(d))
        x1 = math.floor((-1*b + D)/(2*a))
        x2 =  math.floor((-1*b - D)/(2*a))
        lst = []
        lst.append(int(x1))
        lst.append(int(x2))
        lst.sort()
        lst.reverse()
        return lst


#  Driver Code Starts
if __name__ == '__main__':
    # For the values of a,b,c taking in a list in one line  eg : 1 2 3
    print("Enter the values for a,b,c of the equation of the form ax^2 + bx +c")
    abc=[int(x) for x in input().strip().split()]
    a=abc[0]
    b=abc[1]
    c=abc[2]
    # Making a object to class Solution
    ob = Solution()
    ans = ob.quadraticRoots(a,b,c)
    if len(ans)==1 and ans[0]==-1:
        print("Imaginary Roots")
    else:
        print("Roots are :",end=" ")
        for i in range(len(ans)):
            print(ans[i], end=" ")
        print()


'''
Sample Input/Output:

Enter the values for a,b,c of the equation of the form ax^2 + bx +c
1 2 1

Output:
Roots are : -1 -1 

Time Complexity : O(1)
Space Complexity : O(1)

'''
