"""
Problem Statement : To find Hamming Distance between two numbers.
                    Hamming distance? The hamming distance is the value differ in two binary 
                    representations as a 32-bit integer.

Intution: If num1 = 7(0111) and num2 = 8(1000), the bit differance between 
          these two numbers will be 4.

"""

def hamming_distance(num1, num2):

    #To store value of the differnce
    bitdiff = 0
    
    for i in range(31, -1, -1):
        
        #right shift for both the numbers for i AND 1 times
        binary_num1 = num1>>i&1
        binary_num2 = num2>>i&1

        #checking if binary of both are not equal
        if binary_num1 != binary_num2:
            bitdiff += 1
        #i it is equal bitdiff will be same and loop will continue

    return bitdiff

def main():

    #User input for a both numbers
    num1 = int(input("Enter 1st number: "))
    num2 = int(input("Enter 2nd number: "))

    #function call for getting hamming distance for the given two numbers.
    print("Hamming distance between these two numbers is: ", hamming_distance(num1, num2))

main()

'''
Time complexity :O(n)
Space complexity :O(1)
'''

"""
Sample Input / Output:

Enter 1st number: 7
Enter 2nd number: 8
Hamming distance between these two numbers is:  4

Enter 1st number: 1
Enter 2nd number: 6
Hamming distance between these two numbers is:  3

"""
