#= Finding the Greatest Common Divisor of 2 numbers using the Euclidean
Formula to lessen the time complexity.
=#

## Function

function GCD(a, b)
    if (a == 0)
        return b
    end
    if (b == 0)
        return a
    end
    if (a < b)
        a, b = b, a
    end
    ans = a % b
    while (ans != 0)
        a = b
        b = ans
        ans = a % b
    end
    return b
end

## Input

a = readline()
a = parse(Int64, a)
b = readline()
b = parse(Int64, b)

## Calling the function

GCD(a, b)

#=
Sample Test case:
Input: 
    a = 1001  b = 2352
Output:
    7
Time complexity: O( log (min(a,b)) )
=#
