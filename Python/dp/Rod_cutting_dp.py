'''
Cutting a Rod with Maximum value
Author: Sakar Mehra (@sakar97)
Problem Statement: Given a rod of length n inches and an array of prices that 
        contains prices of all pieces of size smaller than n.
        Determine the maximum value obtainable by cutting up the rod and selling the pieces.

        For Example:
            length   | 1   2   3   4   5   6   7   8  
            --------------------------------------------
            price    | 1   5   8   9  10  17  17  20
    Output: 22

    Time Complexity: O(N^2)
'''
# A Dynamic Programming solution for Rod cutting problem 
INT_MIN = -32767

# Returns the best obtainable price for a rod of length n and 
# price[] as prices of different pieces 
def cutRod(price, n): 
	val = [0 for x in range(n+1)]
	val[0] = 0

	# Build the table val[] in bottom up manner and return 
	# the last entry from the table 
	for i in range(1, n+1):
		max_val = INT_MIN
		for j in range(i):
			max_val = max(max_val, price[j] + val[i-j-1])
		val[i] = max_val

	return val[n]

# Driver program to test above functions 


if __name__ == "__main__":

    arr = [1, 5, 8, 9, 10, 17, 17, 20] 
    size = len(arr) 

    # User input for price array and length of the rod.
    ans = str(cutRod(arr, size))
    print("Maximum Value is: ", ans)