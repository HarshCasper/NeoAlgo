'''
The program is to check whether a given number is a special number or not.
A special number is a number whose all digits are 1
Example-11
'''

def special(n):
    c=s=0
    while(n!=0):
        b=n%10
		#Count of digits
        c=c+1
		#Sum of digits
        s=s+b
        n=n//10
	#If sum and count equal then special
    if s==c:
        print("The given number is special")
    else:
        print("The given number is not special")
#Driver's Code
def main():
    n1=int(input("Enter a number"))
	#Call the function
    special(n1)
if __name__=="__main__":
    main()

'''
Time Complexity:O(n)
Space Complexity:O(1)
Input/Output:
Enter a number 111
The given number is special
'''
