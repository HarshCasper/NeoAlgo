# Unique_Number_III
#Given an array that contains all elements occurring 3 times, but one occurs only once. Find that unique element.

def uniquee_element(array, size): 

	for i in range(size): 
		j = 0
		while(j < size): 
			if (i != j and array[i] == array[j]): 
				break
			j += 1
		if (j == size): 
			return array[i] 
	
	return -1
	
print("Enter Elements:")	
array = input().split()
size = len(array)
print("Uniuqe element:")
print(uniquee_element(array, size)) 

'''
Sample I/O:
	Input:
	Enter Elements:
	1 1 1 4 2 2 2 3 3 3 

	Output: 
	Uniuqe element: 
	4

Time Complexity: O(size)
Space Complexity:O(1)
'''

