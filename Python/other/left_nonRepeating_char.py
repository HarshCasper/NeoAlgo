"""Algorithm to find the first non-repeating character in a string


Input the string from the user.
Start traversing the string using two loops.
Use the first loop to scan the characters of the string one by one.
Use the second loop to find if the current character is occurring in the latter part if the string or not.
If it is not occurring, print that character.
Else, continue traversing.
"""

def firstNonRepeating(string): 
    k = -1
    l = len(string)
    for i in range(0,l):
        flag = 1
        for j in range(0,l):
            if(string[i] == string[j] and (not(i-j))):
                flag = 0
                break
        if(flag == 1):
            return i
    return k
            
    
    
  
# Driver program to test above function 
string = input("Enter a string: ")
index = firstNonRepeating(string) 
if index == None: 
    print('-1')
else: 
    print(index)
    
"""
Sample input 1:
Input: "abaacd"
Output: 1

Sample input 2:
Input:"aabbccdd"
Output: -1
    """