"""
Python program to find the number of bits to be flipped to convert one number to another

Inorder to compare the individual bits of given the numbers, we can compute
the number of set bits in thier XOR, as we know that XOR operation yields
set bits, only when two same bits are XORed.
""" 


def get_num_flips(n1, n2):
    count = 0
    n = n1 ^ n2
    while(n != 0):
        if(n & 1 == 1):
            count = count + 1
        n = n >> 1
    return count

if __name__ == '__main__':
    print("Enter the first number:", end="")
    n1 = int(input())
    print("Enter the second number:", end="")
    n2 = int(input())
    res = get_num_flips(n1, n2)
    print("Number of flips required to inter-convert the given numbers is: {}".format(res))

    

"""
Time Complexity: O(log(n)), where n is the greater of the input number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the first number:12
Enter the second number:24
Number of flips required to inter-convert the given numbers is: 2
"""
