""" Julia program to Check if a number is a Mystery Number or Not.

A mystery number is that number which can be expressed as a sum of two 
numbers and those two numbers must be the reverse of each other
"""


function reverse(n)
    rev = 0
    while n > 0
        rev = rev * 10
        rev = rev + (n % 10);
        n = n ÷ 10
    end
    return rev
end


function check_mystery_num(n)
    # Let us iterate from 1 upto n/2, to check if there is any pair, such that thier
    # sum equals the given number and check if the pair are reverse of each other 
    temp = n ÷ 2
    for i in 1:(temp)
        if (reverse(i) == (n - i))
            return true
        end
    end
    return false
end


print("Enter the number: ")
num = readline()
num = parse(Int, num)
res = check_mystery_num(num)
if res
    println("The given number $num is a Mystery Number.")
else
    println("The given number $num is not a Mystery Number.")
end

"""
Time Complexity: O(n*log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 43234
The given number 43234 is a Mystery Number.

SAMPLE 2
Enter the number: 1234
The given number 1234 is not a Mystery Number.

"""
