'''
Given an array of positive and negative numbers, find if there is a subarray (of size at-least one) with 0 sum.

Examples : 

Input: {4, 2, -3, 1, 6}
Output: true 
Explanation:
There is a subarray with zero sum from index 1 to 3.

Input: {4, 2, 0, 1, 6}
Output: true 
Explanation:
There is a subarray with zero sum from index 2 to 2.

Input: {-3, 2, 3, 1, 6}
Output: false
'''
def print0S(arr):      #cumulative sum
        d = {0: -1};  
        s = 0
        for i in range(len(arr)):
            s+=arr[i]
            if s in d:  
                return "Found a sunbarray with 0 sum" #  print arr[d[s]+1:i+1]  
            d[s] = i      #key will cumulative sum
        return "No Such sub array with 0 sum exits!"

if __name__ == "__main__":
    arr = list(map(int,input("Enter the list: ").split()))
    print(print0S(arr))

"""
Time Complexity: O(n)
Space Complexity : O(1)

INPUT: 
Enter the list: 4 2 -3 1 6


OUTPUT:
Found a sunbarray with 0 sum

"""
