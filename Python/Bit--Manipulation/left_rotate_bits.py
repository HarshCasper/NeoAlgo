# Python program to Left Rotate a number by a specific bits.


# Left Rotate 'cnt' number of bits of the given number 'n'
def left_rotate_bits(n, cnt):
    cnt = cnt % 31
    while(cnt > 0):
        # Store the current MSB in a temporary variable
        msb = (n >> 31) & 1
        # Left rotate the given number by one bit
        n = (n << 1)
        # Set the dropped MSB as the new LSB
        n = n | msb
        # Decrement cnt
        cnt = cnt - 1
    return n


if __name__ == '__main__':
    print("Enter the number? ", end="")
    num = int(input())
    print("How many bits do you want to rotate? ", end="")
    cnt = int(input())
    left = left_rotate_bits(num, cnt)
    print("The Left-rotated number is: {}".format(left))


"""
Time Complexity: O(n)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the number? 23
How many bits do you want to rotate? 12 
The Left-rotated number is: 94208 
"""
