//program to check if a string in palindrome or not
//a stinng is palindrome if it is same as it is when it is reversed.

//getting string as input
n=int(input("Enter number:"))
temp=n
rev=0
while(n>0):
    dig=n%10
    rev=rev*10+dig
    n=n//10
if(temp==rev):
    print("The number is a palindrome!")
else:
    print("The number is not a palindrome!")
