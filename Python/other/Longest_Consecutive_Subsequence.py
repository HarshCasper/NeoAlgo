"""
Given an array of positive integers. Find the length of the longest sub-sequence such that 
elements in the subsequence are consecutive integers,
the consecutive numbers can be in any order.

Example:
Input: {2,6,1,9,4,5,3}
Output: 6

Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.

"""

def LongestConsecutiveSubsequence(arr):
    #let take dict save the the element 
    dict={}
    
    for l in arr:
        if l not in dict.keys():
            dict[l]=1

    sub=[0]*len(arr)
    #check  present or not then increase the count with 1 
    for i in range(0,len(arr)):

        key=arr[i]

        while key in dict.keys():
            key=key+1

        sub[i]=key-arr[i]
    #result
    return sorted(sub,reverse=True)[0]

if __name__ == '__main__':
    arr = list(map(int,input("Enter the number: ").split()))
    print("The longest consective subsequence is ",LongestConsecutiveSubsequence(arr))

'''
Time complexity : O(n^n) 
Space complexity : O(n^n) 

INPUT:-
Enter the number: 36 41 56 35 44 33 34 92 43 32 42 

OUTPUT:-
The Longest Consecutive Subsequence is  5

'''
