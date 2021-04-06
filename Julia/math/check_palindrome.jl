""" Julia program to Check if a number is a Palindrome Number or not.
A palindrome number is a number such that the reverse of the number is equal to the number itself 
"""

function check_palindrome(num)
    temp = num
    rev = 0
    while (temp > 0)
        rem = temp % 10
        rev = (rev * 10) + rem
        temp = temp ÷ 10;
    end
    if (num == rev)
        return true
    else
        return false
    end
end


print("Enter the number: ")
num = readline()
num = parse(Int, num)
res = check_palindrome(abs(num))
if res
    println("The given number $num is a Palindrome Number.")
else
    println("The given number $num is not a Palindrome Number.")
end


"""
Time Complexity: O(log(num)), where 'num' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 121
The given number 121 is a Palindrome Number.

SAMPLE 2
Enter the number: 1234
The given number 1234 is not a Palindrome Number.

"""
