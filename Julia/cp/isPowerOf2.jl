#= Given a number N check if it is a power of 2 in O(1). We will be 
using bitwise operator to get the calculation.=#

## Function

function isPowerOfTwo(n)
    return (n & (n - 1) == 0)
end

## Input

n = readline()
n = parse(Int64, n)

## Calling the function

isPowerOfTwo(n)

#=
Sample Test Case
Input: 
    n = 4294967296
Output:
    true
Time complexity: O( 1 ) 
=#
