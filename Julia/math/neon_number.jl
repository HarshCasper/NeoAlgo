"""Julia program to check if a number is a Neon Number or not
A neon number is a number where the sum of digits of square of the number is equal to the number.
"""

function check_neon_num(n)
    sum = 0
    temp = n ^ 2
    while(temp != 0)
        sum = sum + (temp % 10)
        temp = temp  ÷ 10
    end
    if(sum == n)
        return true
    else
        return false
    end
end


print("Enter the number: ")
n = readline()
n = parse(Int, n)
res = check_neon_num(n)
if res
    println("The given number $n is a Neon Number.")
else
    println("The given number $n is not a Neon Number.")
end


"""
Time Complexity: O(log(num)), where 'num' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 0
The given number 0 is a Neon Number..

SAMPLE 2
Enter the number: 14
The given number 14 is not a Neon Number.

"""
