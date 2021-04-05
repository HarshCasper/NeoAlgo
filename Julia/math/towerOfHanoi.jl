#= The famous Tower of Hanoi question where there are 3 towers with discs in them. You need
to transfer all the discs from A to C =#

## Function 

function towerOfHanoi(discs, source = "A", destination = "C", helper = "B")
    if (discs == 0)
        return
    end
    towerOfHanoi(discs - 1, source, helper, destination)
    println("Move from $(source) to $(destination)")
    towerOfHanoi(discs - 1, helper, destination, source)
end

## Input 

println("Enter the number of discs: ")
n = readline()
n = parse(Int64, n)

## Calling the function 

towerOfHanoi(n)

#=
Sample Test Case:
Input: 
    Enter the number of discs: 3
Output:
    Move from A to C
    Move from A to B
    Move from C to B
    Move from A to C
    Move from B to A
    Move from B to C
    Move from A to C
Time complexity: O(2^N)
=#
