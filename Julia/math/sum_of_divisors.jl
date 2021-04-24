# Julia program to find the sum of divisors of a number.

function sum_of_divisors(num)
    i = 1
    sum = 0
    while (i <= sqrt(num))
        if num % i == 0 && i == sqrt(num)
            sum = sum + i
        elseif num % i == 0
            sum = sum + i
            sum = sum + (num ÷ i)
        end
        i = i + 1
    end
    return sum
end


print("Enter the number: ")
num = readline()
num = parse(Int, num)
sum = sum_of_divisors(num)
print("The Sum of the Divisors of the given number is $sum.")

"""
Time Complexity - O(n^(0.5)), where 'n' given is the number
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter the number: 256
The Sum of the Divisors of the given number is 511.

SAMPLE II

Enter the number: 5687
The Sum of the Divisors of the given number is 6384.
"""
