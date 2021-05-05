'''
A pronic number is a number which is the product of two consecutive integers.
Such as 2=2*1 (2 and 1 are consecutive numbers)
        12=4*3
             
This program will print the pronic numbers in the given range. '''

import math

'''Function to check whether number is pronic or not
   A number is pronic if the root of equation i^2+i-num=0 is real and integer.'''

def is_pronic(n):
    dis = 1 + 4 * n
    if dis <= 0:
        return 0
    else:
        root = int(math.sqrt(dis))
        if root * root == dis and dis % 2 == 1:
            return 1
        else:
            return 0

if __name__ == '__main__':

    ran_ge = list(input("Enter range to print all the PRONIC NUMBERS: ").split())

    #Printing pronic numbers in given range
    print("PRONIC NUMBERS from "+ ran_ge[0] +" to "+ran_ge[1]+" are:")
    for i in range(int(ran_ge[0]),int(ran_ge[1])+1):
        if is_pronic(i):
            print(i,end=" ")

'''
Sample Input/Output:

Input:
Enter range to print all the PRONIC NUMBERS: 1 1000

Output:
PRONIC NUMBERS from 1 to 1000 are:
2 6 12 20 30 42 56 72 90 110 132 156 182 210 240 272 306 342 380 420 462 506 552 600 650 702 756 812 870 930 992

Time Complexity:O(n)  where n is total numbers in range
Time Complexity of is_pronic()=O(1) 
Space Complexity:O(1)

'''
