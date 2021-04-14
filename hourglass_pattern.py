#print a pattern of hourglass using python
#here note: there are odd number of stars....

#1.Enter the size from the user.

n=int(input())

#to cut the shape into two halves for that reason p=n//2
p=n//2

#if size is odd then n will be n-1...

if(n%2!=0):
  n=n-1

#Divide the pattern into two halves:

# in first half the range is from 0 to n/2
# first it prints a single star which is the border of pattern,then print a triangle of spaces,then reverse triangle of stars and then another triangle of spaces ,then right border...   

for i in range(p):
    print ("*" + (i)*" " + (n-(2*i+1))*"*" + (i)*" " + "*" )

# then the lower halves print
# it prints a single star which is the border of pattern,then print a triangle spaces(reverse of upper half space triangle) ,then triangle of stars and then another triangle of spaces ,then right border...       

for i in range(p):
    print ("*" + (p-i-1)*" " + (2*i+1)*"*" + (p-i-1)*" " + "*" )


#time complexity:O(n)
