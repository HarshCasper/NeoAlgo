# Number of K-Length Sublists with Average at Least Target

# Given a list of integers nums, and integers k and target
# return the number of sublists whose length is k and its average value ≥ target.

# Constraints:-

# n ≤ 100,000 where n is the length of nums

# Approach : First i will take the sum of [0:k] elements and check it's avg.
# If avg greater than target ans count is increased
# then in the loop starting from kth index adding the new element 
# and removeing the initial added elements simultaneously


#input list
nums= [int(num) for num in input("Enter the list items : ").split()]

#input the k-length of sublist
k=int(input()) #

#target value( min avg)
target=int(input()) 

#taking first [0:k] sum
p=sum(nums[0:k]) 

#number of k sets possible before
c=0 

#verifying the taken avg sum greater than target or not
if (p//k)>=target: 
    #if yes increment the count [result]
    c+=1 

i=k
while i<len(nums):

    #adding new element and removeing the firstly added element, this operation takes place until the last element in the list is added 
    p+=nums[i]-nums[i-k] 

    #checking if avg sum greater than target 
    if (p//k)>=target: 
        c+=1
    
    i+=1

#printing final result
print("Number of combinations possible: " ,c) 

# ST-1:- Input:-

# nums = [0, 9, 4, 5, 6]
# k = 3
# target = 5

# output:-
# 2

# ST-2:- Input:-

# nums = [84, 45, 2, 1, 894, 156, 68, 48, 7, 7, 54, 45, 3, 8, 98, 4, 3, 35, 87, 68, 4, 5, 5, 4, 8, 68, 7, 3554, 8]
# k = 4
# target = 13

# output:-
# 24

# Time Complexity:  O(N)
# Space Complexity: O(N)
