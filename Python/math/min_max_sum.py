'''
Given five positive integers, the aim is to find the minimum and maximum values that can be calculated by summing exactly four of the five integers.

'''

def MMSum(a):
    # sorting the array so that it becomes easier to find the min and max set of values
    a.sort()    
    minn=0
    maxx=0
    for i in range(0,4):
        # summing up all minimum values
        minn+=a[i]           
    for i in range(1,5):
        # summing up all maximum values
        maxx+=a[i]           
    print(minn,maxx)

# getting the input    
user_input = (input().strip().split()) 
array = []
for i in user_input:
    array.append(int(i))
# calling the Min-Max-Sum function     
MMSum(array)                           
  
'''

COMPLEXITY:
	
	 Time Complexity -> O(N)
	 Space Complexity -> O(N)
     
Sample Input:
1 2 3 4 5

Sample Output:
10 14

'''
