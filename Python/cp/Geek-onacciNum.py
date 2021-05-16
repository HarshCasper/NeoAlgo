# In this problem we are provided with four numbers A,B,C and N. A,B and C are the 
# first three numbers of a series called as geek-onacci series. In this series the  
# nth number is the sum (n-1)th, (n-2)th and (n-3)th number. Our task is to find the
# nth number.


# Python Code :
# This function will find the value of the nth term using recursion 

def Checklist(x,y,z,n):

    # base case
    # the 4th term is sum of first three terms then

    if n==4:
        return (x+y+z)

    else:
        # recursive call for the function
        return Checklist(y,z,x+y+z,n-1)

# main function

# taking input x,y,z and n
        
x=int(input())
y=int(input())
z=int(input())
n=int(input())

# Calling the function geek_onacci

print(Checklist(x,y,z,n))

'''
Time complexity : O(log N)  # N refers to total inputs in array
Space complexity : O(1)

Test Case 1 :
Input :  
 1 3 2 4
Output : 
 6

Test Case 2 :
Input :
 1 3 2 6
Output :
 19

Test Case 3 :
Input :  
 1 3 2 5
Output : 
 11
'''