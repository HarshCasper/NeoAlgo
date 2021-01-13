"""
This is a program written in python for finding GCD of two numbers. 
This solution uses recursive approach as implementation.
Recursive approach means a fuction calling itself for which a base condition is given so that the program knows where to terminate.
"""

#definition of functions to find GCD of 2 numbers.
def gcd_of_nums(x,y):
    #choose the smaller number
    if x > y:
        t=x
        x=y
        y=t

    if(x==0):
        return y
    else:
        return gcd_of_nums(x,y%x)

def main():
    num1 = int(input("Enter 1st number: "))
    num2 = int(input("Enter 2nd number: "))

    print("The GCD is: ", gcd_of_nums(num1,num2))
    
if __name__ == "__main__":
    main()    


"""
Output:

Enter 1st number: 48
Enter 2nd number: 6
The GCD is:  6

Enter 1st number: 43
Enter 2nd number: 54
The GCD is:  1
"""
print("\n")
