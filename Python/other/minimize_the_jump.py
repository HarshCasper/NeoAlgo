#Find Minimum number of jumps to reach end
def min_jump(arr, n):
    if n <= 1: 
        return 0 #return zero values if the array less than one element
    
    #assigning the value 0    
    left = 0
    right = arr[0]
    count = 1

    while right < n-1:
        count += 1 #incresing the value 
        jump = max(i + arr[i] for i in range(left, right + 1)) #by this checking all the arr and finding min values 
        left, right = right, jump #swaping the values
    return count

arr = list(map(int, input("Enter the elements: ").split()))
size = len(arr)
print('Minimum number of jumps to reach',
      'end is', min_jump(arr, size))

'''
Time Complexity : O(n)
Space Complexity : O(1)

INPUT:
    Enter the elements: 1 3 5 8 9 2 6 7 6 8 9

OUTPUT  
    Minimum number of jumps to reach end is 3

Output: 3 (1-> 3 -> 8 -> 9)
Explanation: Jump from 1st element 
to 2nd element as there is only 1 step, 
now there are three options 5, 8 or 9. 
If 8 or 9 is chosen then the end node 9 
can be reached. So 3 jumps are made.

'''

