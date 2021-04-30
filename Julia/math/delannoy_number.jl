"""
Julia program to find the Delannoy number for a given rectangular grid.
A Delannoy number describes the number of paths from the southwest corner 
(0, 0) of a rectangular grid to the northeast corner (m, n) using only single steps north, northeast, or east.
Delannoy number is named after the French mathematican Henri Delannoy.
"""

function delannoy_number(r, c)

    # Initialize the dp array with '0' as value.
    dp = zeros(Int, c + 1, r + 1)

    for i in 1:c
        dp[1,i] = 1
    end
    for i in 2:c+1
        dp[i,1] = 1
    end
    # From Each point calculate the number of paths, to the north-east point, that can be reached by 
    # traversing through the immediate right or immediate top or immediate top-right point.
    for i in 2:c+1
        for j in 2:r+1
            dp[i,j] = dp[i-1,j] + dp[i-1,j-1] + dp[i,j-1]
        end
    end
    return dp[c+1,r+1]
end    
        

print("Enter the co-ordinates of the north-east corner.\nEnter the row co-ordinate: ")
x = readline()
x = parse(Int, x)
print("Enter the column co-ordinate: ")
y = readline()
y = parse(Int, y)
res = delannoy_number(x, y)
print("The Delannoy number of the given grid is $res.")


"""
Time Complexity - O(x * y), where `x`, `y` is the given co-ordinates.
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter the co-ordinates of the north-east corner.
Enter the row co-ordinate: 5
Enter the column co-ordinate: 6
The Delannoy number of the given grid is 3653.
"""
