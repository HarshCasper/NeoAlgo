'''
Given five positive integers, the aim is to find the minimum and maximum values that can be calculated by summing exactly four of the five integers.

Example:
arr = [1,3,5,7,9]
The minimum sum is 1+3+5+7 = 16 and the maximum sum is 3+5+7+9 = 24. So, the output will be:
16 24

'''

def MMSum(a):
    a.sort()     # sorting the array so that it becomes easier to find the min and max set of values
    minn=0
    maxx=0
    for i in range(0,4):
        minn+=a[i]           # summing up all minimum values
    for i in range(1,5):
        maxx+=a[i]           # summing up all maximum values
    print(minn,maxx)
    
user_input = (input().strip().split()) # getting the input
array = []
for i in user_input:
    array.append(int(i))
MMSum(array)                           # calling the Min-Max-Sum function 
  
'''
Sample Input:
1 2 3 4 5

Sample Output:
10 14

'''