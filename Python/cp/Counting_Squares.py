'''
Given two integers r and c, we are supposed to return  the number of unique squares that can
be made from a grid with r rows and c columns of evenly-spaced points.
Mod the result by 10 ** 9 + 7.
A square consists of a set of 4 points that form the vertices of a square. Each side of the square must have the same length, and the square does
not necessarily have to be aligned with the axes of the grid.
'''

'''
Input
r = 3
c = 3
Output
6
Explanation
We can make 4 1x1 squares, and 2 2x2 squares (one of them at a 45 degree angle)
'''

'''
Time Complexity:
O(min(r,c)) - we only count up squares with side lengths less than min(r, c)min(r,c)

Space Complexity:
O(1) - no data structures are used, we use math to solve the problem
'''

def Counting_squares(r, c):
    # initialize the answer variable with value 0 
    ans=0
    k=1
    # the value in add gives us the number of squares which are present in the grid which are 
    # parallel to the axises
    # the general formula for the number of squares parallel to the x- and y-axis in a n x  square of points to be equal to ∑ (n−k)(m-k) k is from 1 to n-1
    # where k represents the subproblem of size k i.e square of side k 
    add=(r-k)*(c-k) 
    while add>0:
        # since we need to include all the squares including those which are inclined . we observe that for every square of side length = k there are k inclined squares therefore we multiply our current variable add with k
        ans+=add*k
        k+=1
        add=(r-k)*(c-k) 
    return ans%(10**9+7)

print(Counting_squares(5,3))
# // output =14




