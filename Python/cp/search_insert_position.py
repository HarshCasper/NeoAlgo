'''

Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

'''

x = list(map(int, input().strip().split()))
target = int(input())

if target in x:
    print(x.index(target))
else:
    x.append(target)
    x.sort()
    print(x.index(target))
