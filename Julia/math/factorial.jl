# Julia program to find the factorial of a number

function find_factorial(num)
    if ( num == 1 || num == 0 )
        return 1
    end
    return num * find_factorial( num - 1)
end


print("Enter a number: ")
num = readline()
num = parse(Int, num)
if(num < 0)
    print("Factorial is not defined for Negative numbers")
    exit()
end
fac = find_factorial(num)
print("The factorial of the given number is $num ! = $fac ")


"""
Time Complexity - O(n), where 'n' is the given number
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter a number: 13
The factorial of the given number is 13 ! = 6227020800 

SAMPLE II

Enter a number: -8
Factorial is not defined for Negative numbers
"""
