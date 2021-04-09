"""Julia program to check if a number is automorphic or not.
An Automorphic Number is such a number whose square ends in the same digits as  the number itself."""


function check_automophic(num)
    temp = num * num

    while(num > 0)
        # Extract the last digits of the given number and its square.
        lastNum = num % 10
        lastSquare = temp % 10

        # Check if they are equal
        if(lastNum != lastSquare)
            return false
        end

        num = num ÷ 10
        temp = temp ÷ 10
    end

    return true
end

print("Enter the number: ")
n = readline()
n = parse(Int, n)
res = check_automophic(abs(n))
if res
    println("The given number $n is an Automorphic Number.")
else
    println("The given number $n is not an Automorphic Number.")
end


"""
Time Complexity: O(log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number: 24
The given number 24 is not an Automorphic Number.

SAMPLE 2

Enter the number: 25
The given number 25 is an Automorphic Number.
"""

