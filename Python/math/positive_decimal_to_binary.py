#Function to convert a positive decimal number into its binary equivalent
'''
By using the double dabble method, append the remainder
to the list and divide the number by 2 till it is not
equal to zero
'''
def DecimalToBinary(num):
    #the binary equivalent of 0 is 0000
    if num == 0:
        print('0000')
        return
    else:
        binary = []
        while num != 0:
            rem = num % 2
            binary.append(rem)
            num = num // 2
    #reverse the list and print it
    binary.reverse()
    for bit in binary:
        print(bit, end="")

#executable code
decimal = int(input("Enter a decimal number to be converted to binary : "))
print("Binary number : ")
DecimalToBinary(decimal)

'''
Sample I/O :
Input :
Enter a decimal number to be converted into binary: 8

Output:
Binary number:
1000

Time Complexity : O(n)
Space Complexity : O(1)
'''
