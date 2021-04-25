# Julia program to Right Rotate a number by a specific bits.

# Right Rotate 'cnt' number of bits of the given number 'n'
function right_rotate_bits(n, cnt)
    cnt = cnt % 31
    while(cnt > 0)
        # Store the current LSB in a temporary variable
        lsb = n & 1
        # Right rotate the given number by one bit and drop its LSB
        n = (n >> 1) & (~(1 << 31))
        # Set the dropped LSB as the new MSB
        n = n | (lsb << 31)
        # Decrement cnt
        cnt = cnt - 1
    end
    return n
end


print("Enter the number? ")
num = readline()
num = parse(Int, num)
print("How many bits do you want to rotate? ")
cnt = readline()
cnt = parse(Int, cnt)
left = right_rotate_bits(num, cnt)
print("The Right-rotated number is: $left")


"""
Time Complexity: O(n)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the number? 39
How many bits do you want to rotate? 17
The Right-rotated number is: 1277952 
"""
