# Julia program to Left Rotate a number by a specific bits.


# Left Rotate 'cnt' number of bits of the given number 'n'
function left_rotate_bits(n, cnt)
    cnt = cnt % 31
    while(cnt > 0)
        # Store the current MSB in a temporary variable
        msb = (n >> 31) & 1;
        # Left rotate the given number by one bit
        n = (n<<1);
        # Set the dropped MSB as the new LSB
        n = n | msb;
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
left = left_rotate_bits(num, cnt)
print("The Left-rotated number is: $left")


"""
Time Complexity: O(n)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the number? 39
How many bits do you want to rotate? 17
The Left-rotated number is: 5111808 
"""
