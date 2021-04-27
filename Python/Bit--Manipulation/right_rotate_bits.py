# Python program to Right Rotate a number by a specific bits.

# Right Rotate 'cnt' number of bits of the given number 'n'
def right_rotate_bits(n, cnt):
    cnt = cnt % 31
    while(cnt > 0):
        # Store the current LSB in a temporary variable
        lsb = n & 1
        # Right rotate the given number by one bit and drop its LSB
        n = (n >> 1) & (~(1 << 31))
        # Set the dropped LSB as the new MSB
        n = n | (lsb << 31)
        # Decrement cnt
        cnt = cnt - 1
    return n


if __name__ == '__main__':
    print("Enter the number? ", end="")
    num = int(input())
    print("How many bits do you want to rotate? ", end="")
    cnt = int(input())
    right = right_rotate_bits(num, cnt)
    print("The Right-rotated number is: {}".format(right))

"""
Time Complexity: O(n)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the number? 52
How many bits do you want to rotate? 29
The Right-rotated number is: 416
"""
