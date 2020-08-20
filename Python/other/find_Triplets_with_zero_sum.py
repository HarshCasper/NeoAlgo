'''
  Author : Mohit Kumar
  
  python program to find triplets in a given  array whose sum is zero 

'''

# function to print triplets with 0 sum 

def findTriplets(arr, n): 

	found = False

	# sort array elements 
	arr.sort() 

	for i in range(0, n-1): 
	
		# initialize left and right 
		l = i + 1
		r = n - 1
		x = arr[i] 
		while (l < r): 
		
			if (x + arr[l] + arr[r] == 0): 
				# print elements if it's sum is zero 
				print(x, arr[l], arr[r]) 
				l+=1
				r-=1
				found = True
			

			# If sum of three elements is less 
			# than zero then increment in left 
			elif (x + arr[l] + arr[r] < 0): 
				l+=1

			# if sum is greater than zero than 
			# decrement in right side 
			else: 
				r-=1
		
	if (found == False): 
		print(" No Triplet Found") 


# Driven source 
arr = [0, -1, 2, -3, 1] 
n = len(arr) 
findTriplets(arr, n) 

'''
SAMPLE INPUT 1 :
	arr = [0, -1, 2, -3, 1] 
OUTPUT :
	-1 0 1
	-3 2 1

COMPLEXITY ANALYSIS :

Time Complexity : O(n^2).
    Only two nested loops is required, so the time complexity is O(n2).

Auxiliary Space : O(1), no extra space is required, so the time complexity is constant.

'''
