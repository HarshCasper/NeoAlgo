# Julia program to find the number of bits to be flipped to convert one number to another

"""Inorder to compare the individual bits of given the numbers, we can compute the number of
set bits in thier XOR, as we know that XOR operation yields set bits, only when two same
bits are XORed."""
function get_num_flips(n1, n2)
    count = 0
    n = n1 ⊻ n2
    while(n != 0)
        if(n & 1 == 1)
            count = count + 1
        end
        n = n >> 1
    end
    return count
end


print("Enter the first number:")
n1 = readline()
n1 = parse(Int32, n1)
print("Enter the second number:")
n2 = readline()
n2 = parse(Int32, n2)
res = get_num_flips(n1, n2)
print("Number of flips required to inter-convert the given numbers is: $res")

"""
Time Complexity: O(log(n)), where n is the greater of the input number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the first number:13
Enter the second number:26
Number of flips required to inter-convert the given numbers is: 4
"""
