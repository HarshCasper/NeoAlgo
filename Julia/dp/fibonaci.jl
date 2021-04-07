#= Finding the Nth number in the Fibonaci Sequence using Dynamic Programming
=#

## Function 

function fibonaci(n)
    f = Int64[]
    push!(f, 0)
    push!(f, 1)
    for i = 3:n
        temp = f[i-1] + f[i-2]
        push!(f, temp)
    end
    return f[n]
end

## Input 

print("Enter the number: ")
n = readline()
n = parse(Int64, n)
println("The $(n)th fibonaci number is ")

## Calling the function 

fibonaci(n)

#=
Sample Test Case:
Input: 
    Enter the number: 5
Output:
    The 5th fibonaci number is 3

Time Complexity: O ( N )
=#
