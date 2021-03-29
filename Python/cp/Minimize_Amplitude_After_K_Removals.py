"""Minimize Amplitude After K Removals


You are given a list of integers nums, and an integer k.
Given that you must remove k elements in nums,
return the minimum max(nums) - min(nums) value we can achieve.

Constraints:-

1 ≤ n ≤ 100,000 where n is the length of nums
k < n

Approach :- we have to sort the list first and take a 'p' variable
in which it stores the length of the list after removing the k.
Taken an 'm' variable which stores the min possible max(nums)-min(nums)
firstly and needs to be changed when we get the less max(nums)-min(nums).
Now, take a for loop which is to be iterated from 0 to len(nums)-p+1 ,
during the for loop I will check the difference i+p-1'th term to the i'th term
when I get the lease min I will change the min value to it.
At the end will return the 'm'(min(max(nums)-min(nums)))"""

# input list
nums = [int(num) for num in input("Enter the list items : ").split()]

# input the k
k = int(input("Enter the number of items to be removed : "))

nums = sorted(nums)

# storing initial len(nums)-k
p = len(nums) - k

# initial max is stored in m
m = nums[-1] - nums[0]

i = 0

# iteration loop
while i < len(nums) - p + 1:

    # Actual process

    if nums[i + p - 1] - nums[i] < m:
        m = nums[i + p - 1] - nums[i]

    i += 1

# printing max possible from list
print("The manimum Possible difference is : " , m)

"""Test Case for the given sum
Input:-

nums = [84, 45, 2, 1, 894, 156, 68, 48]
k = 4

output:-
39

Time Complexity:  O(nlogn)
Space Complexity: O(1) """
