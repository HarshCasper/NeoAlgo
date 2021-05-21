'''
Description :

A Fenwick tree or binary indexed tree is a data structure that can efficiently update elements 
and Calculate prefix sums in a table of numbers.
'''

# Python Code :
# forming the function
def Sum(ft, index): 
    s=0
    index = index + 1
    while index > 0:  
        s += ft[index]
        index -= index & (-index) 
    return s 

def update(ft, size, index, val):

    index += 1
    while index <= size: 
        ft[index] += val 
        index += index & (-index) 

def construct(arr, size): 

    ft = [0]*(size+1) 
    for i in range(size): 
        update(ft, size, i, arr[i]) 
    return ft 


freq = list(map(int,input("\nEnter the numbers : ").split()))

# construct function will return the Fsenwick Tree.
ft = construct(freq,len(freq))

#Printing freq[0....n]
n = int(input("Enter the last index : "))
print("Sum from 0 to",n,":",Sum(ft,n))

#Updating 
position = int(input("Enter the position to update : "))
value = int(input("Enter the value to be added : "))
update(ft,len(freq),position,value) 
n = int(input("Enter the last index : "))
print("Sum from 0 to",n,":",Sum(ft,n))


"""
Sample TestCase:

Enter the numbers: 2 1 1 3 2 3 4 5 6 7 8 9
Enter the last index : 5
Sum from 0 to 5 : 12
Enter the position to update : 2
Enter the value to be added : 12
Enter the last index : 3
Sum from 0 to 3 : 19
"""