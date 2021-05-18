""" Julia program to Check if a number is an Armstrong Number or not.
An armstrong number is a number such that the sum of its digits each 
raised to the power of the number of digits.
"""

function check_armstrong(num)
    temp = num
    sum = 0
    cnt = floor(log10(num) + 1)
    while (temp > 0)
        rem = temp % 10
        sum = sum + (rem ^ cnt)
        temp = temp ÷ 10;
    end
    if(num == sum)
        return true
    else
        return false
    end
end


print("Enter the number: ")
num = readline()
num = parse(Int, num)
if(num < 0)
    println("The given number $num is not a Armstrong Number.")
    exit()
end
res = check_armstrong(num)
if res
    println("The given number $num is a Armstrong Number.")
else
    println("The given number $num is not a Armstrong Number.")
end


"""
Time Complexity: O(log(num)), where 'num' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 371
The given number 371 is a Armstrong Number.

SAMPLE 2
Enter the number: 1234
The given number 1234 is not a Armstrong Number.

"""
