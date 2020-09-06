def palindrome(string): 
	maxLength = 1

	begin = 0
	length = len(string) 

	low = 0
	high = 0

	# One by one consider every character as center point of even and length palindromes 

	for i in range(1, length): 
		# Find the longest even length palindrome with center points as i-1 and i. 
		low = i - 1
		high = i 
		while low >= 0 and high < length and string[low] == string[high]: 
			if high - low + 1 > maxLength: 
				begin = low 
				maxLength = high - low + 1
			low -= 1
			high += 1

		# Find the longest odd length palindrome with center point as i 
		low = i - 1
		high = i + 1
		while low >= 0 and high < length and string[low] == string[high]: 
			if high - low + 1 > maxLength: 
				begin = low 
				maxLength = high - low + 1
			low -= 1
			high += 1

	print ("Longest palindrome substring is:" )
	print (string[begin:begin + maxLength] )

	return maxLength 


string = input("Enter String: ") 
print ("Length is: " + str(palindrome(string)))

'''
To find the longest Palindrome Substring in given string

Sample I/O:
	Input:
	
	Enter String: Boon
	
	Output:
	Longest palindrome substring is:
	oo
	Length is: 2

Time Complexity: O(n*2)
Space Complexity: O(1)

'''