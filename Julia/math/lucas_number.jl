"""
Julia program to find the N'th Lucas Number.
Lucas Numbers is a sequence similar to Fibonacci numbers and is defined 
as the sum of its two immediately previous terms.
The first and second numbers in Lucas sequence are 2 and 1 respectively.
"""

function lucas_num(n)
    l1 = 2
    l2 = 1
    if(n == 0)
        return l1
    end

    for i in (2:n)
        next = l1 + l2
        l1 = l2
        l2 = next
    end
    return l2
end


print("Enter the value of n(where you need the nth lucas number): ")
n = readline()
n = parse(Int, n)
if(n < 0)
    print("Invalid Value of n !!!")
    exit()
end
res = lucas_num(n)
print("The $n'th Lucas Number is $res.")


"""
Time Complexity - O(n), where `n` is the given number.
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter the value of n(where you need the nth lucas number): 25
The 25'th Lucas Number is 167761.
"""
