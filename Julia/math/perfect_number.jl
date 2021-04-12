"""Julia program to check if a number is a Perfect number or not.
    Perfect Number is a number if it is equal to the sum of its proper divisors excluding the number itself."""


"""Iterate from 1 till the square root of the given number.
    Identify the divisors and take thier sum. And then check
    If the sum is equal to given number"""
function perfect_number(num)
    # variable to store the sum of the proper divisors, initialized to one
    sum = 1
    # Index to iterate from 1 till the square root
    div = 2
    while((div * div) <= num)
        # Check if the current 'div' number is a divisor or not.
        if(num % div == 0)
            sum = sum + div + num ÷ div
        end
        div = div + 1
    end
    if(sum == num && num != 1)
        return true
    else
        return false
    end
end


print("Enter the number: ")
num = readline()
num = parse(Int, num)
res = perfect_number(num)
if res
    println("The given number $num is a Perfect Number.")
else
    println("The given number $num is not a Perfect Number.")
end


"""
Time Complexity: O(n^(0.5)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 8128
The given number 8128 is a Perfect Number.

SAMPLE 2
Enter the number: 8129
The given number 8129 is not a Perfect Number.
"""
