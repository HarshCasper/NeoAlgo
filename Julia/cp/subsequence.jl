#= Print all the subsequences of the string.
=#

## Function 

function subsequence(s, ans)
    if (length(s) == 0)
        if (length(ans) >= 1)
            println(ans)
        end
        return
    end
    ch = s[1]
    rest_of_string = SubString(s, 2)
    subsequence(rest_of_string, ans)
    subsequence(rest_of_string, ans * ch)
end

## Input

println("Enter the string: ")
s = readline()

## Calling the Function 

println("The subsequences are :")
subsequence(s, "")

#=
Sample Test Case: 
Input: 
    Enter the string: abc
Output:
    The subsequences are :
    c
    b
    bc
    a
    ac
    ab
    abc
Time complexity: O ( 2^N * l) (where l is the length of string)
=#
