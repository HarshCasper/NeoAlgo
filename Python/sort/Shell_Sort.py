
def shellsort(arr):

	#calculate the size of the array
	size = len(arr)

	#dividing the array in two parts
	gap = size//2
	while gap > 0:
		for i in range(gap,size):
			temp = arr[i]

			#shifting the elements
			j = i

			while j>= gap and arr[j-gap] > temp:
				arr[j] = arr[j-gap]
				j -= gap
				#putting the elements at right place
			arr[j] = temp
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
