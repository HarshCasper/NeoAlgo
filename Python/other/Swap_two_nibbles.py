#Python Program to swap the two nibbles in a given byte.

#function to swap nibbles
def swapNibbles(number): 
    return ( (number & 0x0F)<<4 | (number & 0xF0)>>4 ) 

number = int(input("Enter Number: "))
print("After swapping the nibbles:")
print(swapNibbles(number)) 

'''
Sample I/O:
    Input
    Enter Number: 100

    Output:
    After swapping the nibbles:                                                                                                    
    70   

Time Complexity: O(1)
Space Complexity: O(1)

'''
