'''
     A pronic number is a number which is the product of two consecutive integers.
     Such as 2=2*1 (2 and 1 are consecutive numbers)
             12=4*3
             
     This program will print the pronic numbers in the given range.        
'''
import math

'''Function to check whether number is pronic or not
   A number is pronic if the root of equation i^2+i-num=0 is real and integer.'''

def is_pronic(n):
    d=1+4*n
    if d<=0:
        return 0
    else:
        root=int(math.sqrt(d))
        if root*root==d and d%2==1:
            return 1
        else:
            return 0

if __name__ == '__main__':

    ran_ge = list(input("Enter range to print all the PRONIC NUMBERS: ").split())
    #Printing pronic numbers in given range
    print("PRONIC NUMBERS from "+ran_ge[0]+" to "+ran_ge[1]+" are:")
    for i in range(int(ran_ge[0]),int(ran_ge[1])+1):
        if is_pronic(i):
            print(i,end=" ")

'''
    Enter range to print all the PRONIC NUMBERS: 1 1000
    PRONIC NUMBERS from 1 to 1000 are:
    2 6 12 20 30 42 56 72 90 110 132 156 182 210 240 272 306 342 380 420 462 506 552 600 650 702 756 812 870 930 992

    Enter range to print all the PRONIC NUMBERS: 500 10000
    PRONIC NUMBERS from 500 to 10000 are:
    506 552 600 650 702 756 812 870 930 992 1056 1122 1190 1260 1332 1406 1482 1560 1640 1722 1806 1892 1980 2070 2162 2256 2352 2450 2550 2652 2756 2862 2970 3080
    3192 3306 3422 3540 3660 3782 3906 4032 4160 4290 4422 4556 4692 4830 4970 5112 5256 5402 5550 5700 5852 6006 6162 6320 6480 6642 6806 6972 7140 7310 7482 7656
    7832 8010 8190 8372 8556 8742 8930 9120 9312 9506 9702 9900 

'''

'''
   Time Complexity:O(n) //where n is total numbers in range
   Time Complexity of is_pronic()=O(1) 
   Space Complexity:O(1)
'''
            


