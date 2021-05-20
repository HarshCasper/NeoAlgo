# Julia program to check if a number is a power of two.

function power_of_two(n)
    # 0 is not a power of 2
    if(n != 0)
        if((n & (n-1)) == false)
            return true
        end
    end
    return false
end


print("Enter a number: ")
n = readline()
n = parse(Int, n)
res = power_of_two(n)
if(res)
    print("The given number is a power of 2.")
else
    print("The given number is not a power of 2.")
end


"""
Time Complexity - O(1)
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I
Enter a number: 4
The given number is a power of 2.

SAMPLE II
Enter a number: 0
The given number is not a power of 2.
"""
