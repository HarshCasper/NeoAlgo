"""
Julia program to check if a number is a pronic number
Pronic Numbers are those numbers that can be arranged to form a rectangle.
It is a number which is the product of two consecutive integer
"""

function check_pronic(x)
    i = 0
    while(i <= isqrt(x))
        if(x == i * (i + 1))
            return true
        end
        i = i + 1   
    end
    return false 
end


print("Enter the number: ")
n = readline()
n = parse(Int, n)
res = check_pronic(abs(n))
if(res)
    print("The given number $n is a pronic number.")
else
    print("The given number $n is not a pronic number.")
end


"""
Time Complexity: O(log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number: 154
The given number 154 is not a pronic number.

SAMPLE 2
Enter the number: 72
The given number 72 is a pronic number.
"""
