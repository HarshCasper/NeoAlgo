#=Counting the number of 1s in the binary representation of a number of 1s using Bit Manipulation.
Calulating using bit operator & gives us a faster result than converting the decimal number to binary and then 
counting. =#

## Function

function counter(n)
    count = 0
    while (n > 0)
        n = n & (n - 1)
        count += 1
    end
    return count
end

## Input

print("Enter the number ")
n = readline()
n = parse(Int64, n)
print("\nThe number of 1s in the binary representation are ")

## Calling the function 

counter(n)

#=
Time Complexity: O(n)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the number 5
The number of 1s in the binary representation are 2
=#
