# Python program for implementation of Shell Sort

def shellsort(arr):

	# Start with a big gap, then reduce the gap
	size = len(arr)
	gap = size//2

	# Do a gapped insertion sort for this gap size. 
	while gap > 0:

		for iteration in range(gap,size):

			# save a[i] in temp
			temp = arr[iteration]

			#shift earlier gap-sorted elements up until the correct(new)
			# location for a[i] is found
			new_loc = iteration

			while new_loc>= gap and arr[new_loc-gap] > temp:
				arr[new_loc] = arr[new_loc-gap]
				new_loc -= gap

			# put temp (the original a[i]) in its correct location 
			arr[new_loc] = temp
		gap //= 2

#input array
arr = []

size = int(input("Enter size: "))
print("Enter elements:")
for i in range(0,size):
	item = int(input())
	arr.append(item)

shellsort(arr)

#array after sorting
print("\nArray after sorting:")
for i in range(size):
	print(arr[i],end = ' ')


'''
Sample I/O
	Input:
	
	Enter Size : 5
	Enter Elements: 5 4 3 2 1

	Output:
	Array After Sorting: 1 2 3 4 5

Time Complexity: O(n*2)
Space Complexity: O(1)

'''
