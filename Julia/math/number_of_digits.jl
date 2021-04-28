# Julia program to Find the Number of Digits in a Number 

# Extracting the number of digits
function number_of_digits(num)
    count = 0
    while(num != 0)
        count = count + 1
        num = num ÷ 10
    end
    return count
end

print("Enter the number: ")
num = readline()
num = parse(Int, num)
count = number_of_digits(abs(num))
println("The number of digits in the given number is $count.")

"""
Time Complexity: O(log(num)), where 'num' is the length of the given number
Space Complexity: O(1)
SAMPLE INPUT AND OUTPUT
SAMPLE 1
Enter the number: -12
The number of digits in the given number is 3.
SAMPLE 2
Enter the number: 43258
The number of digits in the given number is 22.
"""
