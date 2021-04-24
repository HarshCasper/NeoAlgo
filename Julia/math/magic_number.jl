"""Julia program to check if a number is a Magic Number or not
A number is said to be a magic number if the recursive sum of its digits is 1.
    For Example Let's Consider
      19, 1 + 9 = 10
      10, 1 + 0 = 1
      = 1 , Hence 19 is a Maigc Number
"""


function sum_of_digits(n)
    sum = 0
    while(n>0)
        rem = n % 10
        sum = sum + rem
        n = n ÷ 10
    end
    return sum
end

function check_magic_num(n)
    while(n > 9)
        n = sum_of_digits(n)
    end
    if(n == 1)
        return true
    else
        return false
    end
end



print("Enter the number: ")
n = readline()
n = parse(Int, n)
res = check_magic_num(abs(n))
if res
    println("The given number $n is a Magic Number.")
else
    println("The given number $n is not a Magic Number.")
end


"""
Time Complexity: O(log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 23
The given number 23 is not a Magic Number.

SAMPLE 2
Enter the number: 1729
The given number 1729 is a Magic Number..

"""
