# Program to find the longest common prefix 

def findMinLength(array, size): 
    minimum = len(array[0]) 
    for i in range(1,size): 
        if (len(array[i])< minimum): 
            minimum = len(array[i]) 

    return(minimum) 

# A Function that returns the longest common prefix from the array of strings 
def commonPrefix(array, size): 

    minimmum_length = findMinLength(array, size) 
    result ="" 
    for i in range(minimmum_length): 
        common_char = array[0][i] 

        for j in range(1,size): 
            if (array[j][i] != common_char): 
                return result 

        # Append to result 
        result = result+common_char 

    return (result) 

array = []
size = int(input("Enter size:"))
for i in range(size):
    item=input()
    array.append(item)

answer = commonPrefix (array, size) 

if (len(answer)): 
    print("The longest common prefix is ",answer) 
else: 
    print("There is no common prefix") 


'''
Sample I/O:
    Input:
    Enter size: 3
    star
    start
    stardom

    Output:
    The longest Common Prefix is : star

Time Complexity: O(size*M) (M = Length of the largest string)
Space Complexity:O(1)

'''
