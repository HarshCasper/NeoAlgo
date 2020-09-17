#Python Program to find the longest common prefix

# function to find minimum length
def findMinLength(string, size): 
	minimum = len(string[0]) 

	for i in range(1,size): 
		if (len(string[i])< minimum): 
			minimum = len(string[i]) 

	return(minimum) 

# A Function that returns the longest common prefix 
def commonPrefix(string, size): 

	minimum_length = findMinLength(string, size) 
	result ="" 
	for i in range(minimum_length):  
		same_char = string[0][i] 
		for j in range(1,size): 
			if (string[j][i] != same_char): 
				return result 
		result = result+same_char 

	return (result) 

# Driver code
if __name__ == "__main__":
	string = []
	size = int(input("Enter size:"))
	print("Enter strings:")
	for i in range(size):
		item = input()
		string.append(item)
	answer = commonPrefix (string, size) 
	if (len(answer)): 
		print("The longest common prefix is ",answer) 
	else: 
		print("There is no common prefix") 

'''
Sample I/O:
	Input:
	Enter size:3
	Enter Strings:
	star
	start
	stardom

	Output:
	The longest common prefix is star

Time Complexity: O(size*Length of the largest string)
Space Complexity:O(length of the largest string)
	
'''