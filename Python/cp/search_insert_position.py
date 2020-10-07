'''

Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

'''
#taking the input from the user

x = list(map(int, input().strip().split()))
target = int(input())

#finding whther the target value is in the list or not

if target in x:
    print(x.index(target))   #if target is present then printing the index
else:
    x.append(target)   #adding the target in the list
    x.sort()   	#sorting the list
    print(x.index(target))   #printing the target index
