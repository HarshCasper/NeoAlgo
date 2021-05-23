"""Julia program to check if a number is a Krishnamurthy number or not.
Krishnamurthy Number is a number whose sum of the factorial of digits
is equal to the number itself. The Number is named after Jiddu Krishnamurti.
"""

# Helper function to return the factorial of a number
function factorial(num)
    if ( num == 1 || num == 0 )
        return 1
    end
    return num * factorial( num - 1)
end

""" Extract each digit of the given number and calculate the sum of the
    factorial of each digit present in the given number"""
function check_krishnamurthy_number(num)
    temp = num
    sum = 0
    while(temp > 0)
        rem = temp % 10
        sum = sum + factorial(rem)
        temp = temp ÷ 10
    end
    return sum
end



print("Enter the number: ")
num = readline()
num = parse(Int, num)
sum = check_krishnamurthy_number(num)
if sum == num
    println("The given number $num is a Krishnamurthy Number.")
else
    println("The given number $num is not a Krishnamurthy Number.")
end


"""
Time Complexity: O(n*log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number: 3124
The given number 3124 is not a Krishnamurthy Number.

SAMPLE 2

Enter the number: 145
The given number 145 is a Krishnamurthy Number.
"""
