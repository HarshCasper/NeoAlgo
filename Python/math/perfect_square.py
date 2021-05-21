'''
A program that returns the count of perfect squares less than or equal to a given number.
It also displays those numbers which are perfect squares within the range of that number.
The number should be greater than or equal to 1
'''
#importing math function as it will be used for square root
import math
#count function
def countsq(n):
    c=0
    for i in range(1,n+1):
        x=int(math.sqrt(i))
		#Checks whether the number is perfect square or not
        if((x*x)==i):
            c=c+1
            print(i)
    return c
#Driver's code
def main():
    n1=int(input("Enter a number"))
    c1=countsq(n1)
    print("The number of perfect squares are",c1)
if __name__=="__main__":
    main()


'''
Time Complexity:O(n)
Space Complexity:O(1)

Input/Output
Enter a number 55
1
4
9
16
25
36
49
The number of perfect squares are 7
'''
