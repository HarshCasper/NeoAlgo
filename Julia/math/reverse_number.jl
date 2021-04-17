# Julia program to reverse a number

# Function to reverse a number.
function reverse(num)
    rev = 0
    while(num > 0)
        # Extract the last digit of num and add it to rev
        rev = rev * 10 + num %10
        num = num ÷ 10
    end
    return rev
end

print("Enter the number: ")
num = readline()
num = parse(Int, num)
rev = reverse(num)
println("The reverse of the given number is $rev.")


"""
Time Complexity: O(log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 1234
The reverse of the given number is 4321.

SAMPLE 2
Enter the number: 785487
The reverse of the given number is 784587.
"""
